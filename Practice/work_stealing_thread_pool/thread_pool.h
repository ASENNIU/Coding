//
// Created by 13345 on 2024/3/13.
//

#ifndef CODING_THREAD_POOL_H
#define CODING_THREAD_POOL_H

#include <vector>
#include <thread>
#include <atomic>
#include <memory>
#include <future>
#include <mutex>
#include <condition_variable>

#include "stealing_queue.h"
#include "threadsafe_queue.h"

namespace leon {
    class join_threads
    {
    private:
        std::vector<std::thread>& threads_;
    public:
        explicit join_threads(std::vector<std::thread>& threads) : threads_(threads) {}
        ~join_threads() {
            for (unsigned int i = 0; i < threads_.size(); ++i) {
                if (threads_[i].joinable()) {
                    threads_[i].join();
                }
            }
        }
    };

    class thread_pool
    {
    private:
        typedef function_wrapper task_type;
        std::atomic_bool done_;
        threadsafe_queue<task_type> pool_work_queue_;
        std::vector<std::unique_ptr<work_stealing_queue>> queues_;
        std::vector<std::thread> threads_;
        std::mutex m_mutex_;
        std::condition_variable m_event_cond_;
        join_threads joiner_;
        unsigned thread_count;

        // thread_local作为类成员变量时必须是static的
        static thread_local work_stealing_queue* local_work_queue_;
        static thread_local unsigned my_index_;

    private:
        void worker_thread(unsigned index) {
            my_index_ = index;
            local_work_queue_ = queues_[index].get();

            // 指数退避策略去窃取高优先级任务
            const int maxDelay = 1024;
            int delay = my_index_ + 1;

            while (!(done_ && local_work_queue_->empty())) {
                delay = 2 * delay;
                bool isStealing = delay >= maxDelay;
                run_pending_task(isStealing);
                if (isStealing) {
                    delay = my_index_ + 1;
                }
            }
        }

        bool pop_task_from_local_queue(task_type& task) {
            if (local_work_queue_ && local_work_queue_->try_pop(task)) {
                printf("thread %d pop task from local queue.\n", my_index_);
                return true;
            }

            return false;
        }

        bool pop_task_from_pool_queue(task_type& task) {
            if (pool_work_queue_.try_pop(task)) {
                printf("thread %d pop task from pool queue.\n", my_index_);
                return true;
            }

            return false;
        }

        // local_work_queue的index代表优先级，数字越小，优先级越高
        bool pop_task_from_other_thread_queue(task_type& task) {
            for (unsigned i = 0; i < queues_.size(); ++i) {
                if (queues_[i]->try_steal(task)) {
                    printf("thread %d pop task from %d thread queue.\n", my_index_, i);
                    return true;
                }
            }

            return false;
        }

    public:
        thread_pool() : done_(false), joiner_(threads_) {
            thread_count = std::thread::hardware_concurrency();
            try {
                for (unsigned i = 0; i < thread_count; ++i) {
                    queues_.push_back(std::make_unique<work_stealing_queue>());
                }
                for (unsigned i = 0; i < thread_count; ++i)
                {
                    threads_.emplace_back(&thread_pool::worker_thread, this, i);
                }
            }
            catch (...) {
                done_ = true;
                throw;
            }
        }

        ~thread_pool() {
            done_ = true;
            m_event_cond_.notify_all(); // 唤醒所有等待的线程
        }

        template<typename FunctionType>
        std::future<typename std::result_of<FunctionType()>::type> submit(FunctionType f, int priority) {
            typedef typename std::result_of<FunctionType()>::type result_type;
            std::packaged_task<result_type()> task(f);
            std::future<result_type> res(task.get_future());

            if (priority >= thread_count || priority < 0) {
                pool_work_queue_.push(std::move(task));
            } else {
                queues_[priority].get()->push(std::move(task));
            }

            m_event_cond_.notify_one();
            return res;
        }

        void run_pending_task(bool isStealing) {
            task_type task;
            if (isStealing) {
                if (pop_task_from_other_thread_queue(task)) {
                    task();
                    m_event_cond_.notify_one(); // 唤醒一个等待的线程
                }
            }
            if (
                pop_task_from_local_queue(task) ||
                pop_task_from_pool_queue(task) ||
                pop_task_from_other_thread_queue(task)
                )
            {
                task();
                m_event_cond_.notify_one(); // 唤醒一个等待的线程
            }
            else {
                std::unique_lock<std::mutex> lock{m_mutex_};
                m_event_cond_.wait(lock, [=] {return !local_work_queue_->empty() || done_; });
            }

        }
    };

    thread_local work_stealing_queue* leon::thread_pool::local_work_queue_ = nullptr;
    thread_local unsigned leon::thread_pool::my_index_ = -1;
}



#endif //CODING_THREAD_POOL_H

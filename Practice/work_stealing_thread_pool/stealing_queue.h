//
// Created by 13345 on 2024/3/13.
//

#ifndef CODING_STEALING_QUEUE_H
#define CODING_STEALING_QUEUE_H

#include "spinlock.h"
#include <queue>
#include <memory>
#include <queue>


namespace leon {
    class function_wrapper
    {
        struct impl_base {
            virtual void call() = 0;
            virtual ~impl_base() = default;
        };

        std::unique_ptr<impl_base> impl;
        template<typename F>
        struct impl_type : impl_base
        {
            F f;
            impl_type(F&& f_) : f(std::move(f_)) {}
            void call() override {
                f();
            }
        };

    public:
        template<typename F>
        function_wrapper(F&& f) : impl(new impl_type<F>(std::move(f))) {}
        function_wrapper() = default;
        function_wrapper(function_wrapper&& other)  noexcept : impl(std::move(other.impl)) {}
        function_wrapper& operator=(function_wrapper&& other)
        noexcept     {
            impl = std::move(other.impl);
            return *this;
        }
        function_wrapper(const function_wrapper&)=delete;
        function_wrapper(function_wrapper&)=delete;
        function_wrapper& operator=(const function_wrapper&)=delete;

        void operator()() {
            impl->call();
        }
    };

    class spinlock_guard {
    private:
        spinlock& lock_;
    public:
        // 在C++中，explicit关键字用于阻止类构造函数的隐式自动类型转换。
        explicit spinlock_guard(spinlock& lock) : lock_(lock) {
            lock_.lock();
        }

        ~spinlock_guard() {
            lock_.unlock();
        }

        // 禁止拷贝构造和拷贝赋值
        spinlock_guard(const spinlock_guard&) = delete;
        spinlock_guard& operator=(const spinlock_guard&) = delete;

        // 禁止移动构造和移动赋值（可选，根据实际需要决定）
        spinlock_guard(spinlock_guard&&) = delete;
        spinlock_guard& operator=(spinlock_guard&&) = delete;
    };

    class work_stealing_queue {
    private:
        typedef function_wrapper data_type;
        std::deque<data_type> the_queue;
        // 在C++中，mutable关键字用于突破const成员函数对成员变量修改的限制。当你声明一个类成员变量为mutable时，即使在一个const成员函数内，你也可以修改这个变量的值。
        mutable leon::spinlock the_lock;
    public:
        work_stealing_queue() = default;
        work_stealing_queue(const work_stealing_queue&) = delete;
        work_stealing_queue& operator=(const work_stealing_queue&) = delete;

        void push(data_type data) {
            spinlock_guard guard(the_lock);
            the_queue.push_back(std::move(data));

        }

        bool empty() const {
            spinlock_guard guard(the_lock);
            bool flag = the_queue.empty();
            return flag;
        }

        bool try_pop(data_type& res) {
            spinlock_guard guard(the_lock);
            if (the_queue.empty()) {
                return false;
            }
            res = std::move(the_queue.front());
            the_queue.pop_front();
            return true;
        }

        bool try_steal(data_type& res)
        {
            spinlock_guard guard(the_lock);
            if (the_queue.empty()) {
                return false;
            }

            res = std::move(the_queue.back());
            the_queue.pop_back();
            return true;
        }
    };


}


#endif //CODING_STEALING_QUEUE_H

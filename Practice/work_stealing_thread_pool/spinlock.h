//
// Created by 13345 on 2024/3/13.
//

#ifndef CODING_SPINLOCK_H
#define CODING_SPINLOCK_H

#include <atomic>

namespace leon {
    struct spinlock {
        std::atomic_flag flag_;
        spinlock() : flag_(ATOMIC_FLAG_INIT) {}

        void lock() {
            while (flag_.test_and_set(std::memory_order::memory_order_acquire));
        }

        void unlock() {
            flag_.clear(std::memory_order::memory_order_release);
        }
    };

}

#endif //CODING_SPINLOCK_H

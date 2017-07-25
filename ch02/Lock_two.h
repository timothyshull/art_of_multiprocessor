#ifndef MULTIPROCESSOR_PROGRAMMING_LOCK_TWO_H
#define MULTIPROCESSOR_PROGRAMMING_LOCK_TWO_H

#include <thread>
#include <utility>

#include "Lock.h"

class Lock_two : public Lock {
private:
    std::thread::id _victim;

public:
    void lock() override;

    void unlock() override;
};

#endif //MULTIPROCESSOR_PROGRAMMING_LOCK_TWO_H

#ifndef MULTIPROCESSOR_PROGRAMMING_PETERSON_H
#define MULTIPROCESSOR_PROGRAMMING_PETERSON_H

#include <thread>
#include <unordered_map>
#include <utility>

#include "Lock.h"

class Peterson_lock : public Lock {
private:
    std::unordered_map<std::thread::id, bool> _flags;
    std::thread::id _victim;

public:
    void lock() override;

    void unlock() override;

private:
    std::thread::id _other(std::thread::id i) const
    {
        auto it = (std::find_if(_flags.begin(), _flags.end(), [&i](auto j) { return j.first != i; }));
        return (*it).first;
    }
};

#endif //MULTIPROCESSOR_PROGRAMMING_PETERSON_H

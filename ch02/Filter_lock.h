#ifndef MULTIPROCESSOR_PROGRAMMING_FILTER_LOCK_H
#define MULTIPROCESSOR_PROGRAMMING_FILTER_LOCK_H

#include <vector>
#include <thread>

#include "Lock.h"

class Filter_lock : public Lock {
private:
    static int const _idle = -1;
    std::vector<std::thread::id> _level;
    std::vector<std::thread::id> _victim;
    std::size_t _size;

public:
    Filter_lock(std::size_t num_threads);

    void lock() override {

    };

    void unlock() override;

private:
    bool _same_or_higher(std::thread::id current, std::size_t level) {
        auto hash = std::hash<std::thread::id>{};
        for (auto i = 0; i < _level.size(); ++i) {
            if (hash(i) != hash(current) && level <= _level[i]) {
                return true;
            }
            return false;
        }
    }
};

#endif //MULTIPROCESSOR_PROGRAMMING_FILTER_LOCK_H

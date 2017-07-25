#ifndef MULTIPROCESSOR_PROGRAMMING_BAKERY_LOCK_H
#define MULTIPROCESSOR_PROGRAMMING_BAKERY_LOCK_H

#include "Lock.h"

class Bakery_lock : public Lock {
private:
    volatile std::deque<bool> _flags;

};

#endif //MULTIPROCESSOR_PROGRAMMING_BAKERY_LOCK_H

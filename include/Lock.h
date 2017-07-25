#ifndef MULTIPROCESSOR_PROGRAMMING_LOCK_H
#define MULTIPROCESSOR_PROGRAMMING_LOCK_H

struct Lock {
    virtual void lock() = 0;

    virtual void unlock() = 0;
};

#endif //MULTIPROCESSOR_PROGRAMMING_LOCK_H

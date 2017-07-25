#include "Lock_two.h"

void Lock_two::lock()
{
    auto i = std::this_thread::get_id();
    _victim = i; // let the other thread go first
    while (_victim == i) {} // spin
}

void Lock_two::unlock() {}

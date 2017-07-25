#include "Peterson_lock.h"

void Peterson_lock::lock()
{
    auto i = std::this_thread::get_id();
    _flags[i] = true;
    _victim = i;
    if (_flags.size() < 2) { return; } // continue holding lock and make progress
    auto j = _other(i);
    while (_flags[j] && _victim == i) {} // spin
}

void Peterson_lock::unlock()
{
    auto i = std::this_thread::get_id();
    _flags[i] = false;
}

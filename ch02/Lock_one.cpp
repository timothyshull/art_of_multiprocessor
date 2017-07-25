#include <iostream>
#include "Lock_one.h"

void Lock_one::lock()
{
    auto i = std::this_thread::get_id();
    _flags[i] = true;

    if (_flags.size() < 2) { return; } // continue holding lock and make progress

    auto j = _other(i);
    while (_flags[j]) {} // spin on second thread's flag
}

void Lock_one::unlock()
{
    auto i = std::this_thread::get_id();
    _flags[i] = false;
}

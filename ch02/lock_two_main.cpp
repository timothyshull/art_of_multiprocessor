#include <iostream>

#include "Lock_two.h"

int main()
{
    Lock_two lock;
    std::size_t counter{0};
    auto f = [&]() {
        lock.lock();
        ++counter;
        lock.unlock();
    };
    std::thread t1(f);
    std::thread t2(f);
    if (t1.joinable()) { t1.join(); }
    if (t2.joinable()) { t2.join(); }
    std::cout << counter << "\n";
    return 0;
}

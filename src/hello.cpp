#include <iostream>
#include <thread>
#include <chrono>

#include "base/core/event.h"
#include "base/core/ignore_unused.hpp"

hestia::base::Event event;

void threadFunWait()
{
    using namespace std::chrono_literals;

    std::cout << std::this_thread::get_id() << " : wait" << std::endl;
    bool result = event.WaitFor(5s);
    std::cout << std::this_thread::get_id() << " : finish, result : " << std::boolalpha << result << std::endl;
}

void threadFunSignal()
{
    using namespace std::chrono_literals;

    std::this_thread::sleep_for(1s);

    std::cout << std::this_thread::get_id() << " : begin notify" << std::endl;

    std::this_thread::sleep_for(1s);

    event.NotifyOne();

    std::this_thread::sleep_for(1s);

    event.NotifyAll();
}

int main(int agrc, char **argv)
{
    std::cout << "hello hestia" << std::endl;
    std::thread td1(threadFunWait), td2(threadFunWait), td3(threadFunWait);
    std::thread td4(threadFunSignal);

    td1.join();
    td2.join();
    td3.join();
    td4.join();
    return 0;
}
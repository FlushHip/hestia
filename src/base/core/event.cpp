#include "base/core/event.h"

namespace hestia
{

namespace base
{

Event::Event()
    : oneFlag_(false)
    , allFlag_(false)
{}

void Event::Wait()
{
    std::unique_lock<std::mutex> lock(mutex_);
    condition_.wait(lock, [this] { return oneFlag_ || allFlag_; });
    oneFlag_ = false;
}
/*
template<class Rep, class Period>
bool Event::WaitFor(const std::chrono::duration<Rep, Period> & duration)
{
    std::unique_lock<std::mutex> lock(mutex_);
    if (condition_.wait_for(lock, duration, [this] { return oneFlag_ || allFlag_; })) {
        oneFlag_ = false;
        return true;
    }
    return false;
}
*/

template<class Clock, class Duration>
bool Event::WaitUntil(const std::chrono::time_point<Clock, Duration> & point)
{
    std::unique_lock<std::mutex> lock(mutex_);
    if (condition_.wait_until(lock, point, [this] { return oneFlag_ || allFlag_; })) {
        oneFlag_ = false;
        return true;
    }
    return false;
}


void Event::NotifyOne()
{
    std::lock_guard<std::mutex> lock(mutex_);
    oneFlag_ = true;
    condition_.notify_one();
}

void Event::NotifyAll()
{
    std::lock_guard<std::mutex> lock(mutex_);
    allFlag_ = true;
    condition_.notify_all();
}

void Event::Reset()
{
    std::lock_guard<std::mutex> lock(mutex_);
    oneFlag_ = allFlag_ = false;
}

} // namespace base

} // namespace hestia
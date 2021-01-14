#pragma once

#include <memory>
#include <mutex>
#include <chrono>

namespace hestia
{

namespace base
{

namespace core
{

class Event
{

public:

    Event();
    ~Event() = default;

    void Wait();
    template<class Rep, class Period>
    bool WaitFor(const std::chrono::duration<Rep, Period> & duration);

    template<class Clock, class Duration>
    bool WaitUntil(const std::chrono::time_point<Clock, Duration> & point);

    void Reset();

    void NotifyOne();
    void NotifyAll();

private:
    std::mutex mutex_;
    std::condition_variable condition_;

    bool oneFlag_;
    bool allFlag_;
};

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

} // namespace core

} // namespace base

} // namespace hestia
#include "hestia/base/core/event.h"

namespace hestia
{

namespace base
{

namespace core
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

} // namespace core

} // namespace base

} // namespace hestia
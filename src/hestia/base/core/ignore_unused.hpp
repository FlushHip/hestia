#pragma once

namespace hestia
{

namespace base
{

namespace core
{

template<typename... Dummy>
void IgnoreUnused(const Dummy & ...) {}

template<typename... Dummy>
void IgnoreUnused() {}

} // namespace core

} // namespace base

} // namespace hestia


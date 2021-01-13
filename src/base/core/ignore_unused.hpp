#pragma once

namespace hestia
{
template<typename... Dummy>
void ignore_unused(const Dummy & ...) {}

template<typename... Dummy>
void ignore_unused() {}

} // namespace hestia

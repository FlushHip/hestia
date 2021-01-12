#pragma once

namespace hestia
{
template <typename... Ts>
void ignore_unused(const Ts & ...) {}

template <typename... Ts>
void ignore_unused() {}

} // namespace hestia

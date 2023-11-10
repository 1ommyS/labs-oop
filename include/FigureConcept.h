#pragma once

#include <concepts>

template <typename T>
concept Figure = (std::is_default_constructible<T>::value);
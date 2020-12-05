// Vector2.hpp
//
// A two dimensional vector struct that will be used throughout this library

#pragma once

#include <cstdint>

template<typename T>
struct Vector2 {
	T x = 0;
	T y = 0;
};

using Vector2I = Vector2<int32_t>;
using Vector2UI = Vector2<uint32_t>;
using Vector2F = Vector2<float>;
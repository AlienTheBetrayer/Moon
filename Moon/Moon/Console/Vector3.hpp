// Vector3.hpp
//
// A three dimensional vector struct that will be used throughout this library

#pragma once

#include <cstdint>

template<typename T>
struct Vector3 {
	T x = 0;
	T y = 0;
	T z = 0;
};

using Vector3I = Vector3<int32_t>;
using Vector3UI = Vector3<uint32_t>;
using Vector3F = Vector3<float>;
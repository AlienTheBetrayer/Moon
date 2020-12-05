// Rect.hpp
//
// A rectangle struct that will be used throughout this library

#pragma once

#include <cstdint>

template<typename T>
struct Rect {
	T left = 0;
	T right = 0;
	T top = 0;
	T bottom = 0;
};
	
using RectI = Rect<int32_t>;
using RectUI = Rect<uint32_t>;
using RectF = Rect<float>;

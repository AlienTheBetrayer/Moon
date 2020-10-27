// Misc.hpp
//
// Moon Engine's Miscleannous stuff

#pragma once

#include "../Moon/Console/ConsoleGeneral.hpp"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>
#include <random>

namespace Moon {
	namespace Misc {
		// Random
		int32_t RandomRange(const int32_t min, const int32_t max) noexcept;
		bool RandomBoolean(void) noexcept;
		
		// Cursor
		bool IsWithinRect(const Vector2& pos, const Rect& rect) noexcept;
		Vector2 GetCursorPosition(void) noexcept;
		Vector2 SnapToConsole(const Vector2& position) noexcept;
	}
}

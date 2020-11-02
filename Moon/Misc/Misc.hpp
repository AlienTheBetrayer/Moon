// Misc.hpp
//
// Moon Engine's Miscleannous stuff

#pragma once

#include "../Macros.hpp"
#include "../../Moon/Console/Vector2.hpp"
#include "../../Moon/Console/Rect.hpp"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>
#include <unordered_map>
#include <thread>
#include <functional>
#include <random>
#include <vector>

namespace Moon {
	namespace Misc {
		// Random
		[[nodiscard]] int32_t RandomRange(const int32_t min, const int32_t max) noexcept;
		[[nodiscard]] bool RandomBoolean(void) noexcept;
		
		// Cursor
		[[nodiscard]] bool IsWithinRect(const Vector2& pos, const Rect& rect) noexcept;
		[[nodiscard]] Vector2 GetCursorPosition(void) noexcept;
		[[nodiscard]] Vector2 SnapToConsole(const Vector2& position) noexcept;

		// Other
		void Sleep(const uint32_t ms) noexcept;
		
		// Key
		[[nodiscard]] bool IsKeyPressed(const uint8_t key) noexcept;
		[[nodiscard]] std::vector<uint8_t> GetPressedKeys(void) noexcept;

		// Map
		template<typename T1, typename T2>
		void IterateMap(const std::unordered_map<T1, T2>& map, const std::function<void(T1, T2)>& callbackFunc) noexcept {
#ifdef CPP17GRT
			for (const auto& [key, value] : map)
				callbackFunc(key, value);
#else
			for (const auto& pair : map)
				callbackFunc(pair.first, pair.second);
#endif
		}
	}
}

// Misc.hpp
//
// Moon Engine's Miscellaneous stuff

#pragma once

#include "../../IncludeSettings.hpp"

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
		[[nodiscard]] bool IsWithinRect(const Vector2I& pos, const RectI& rect) noexcept;
		[[nodiscard]] Vector2I GetCursorPosition(void) noexcept;
		[[nodiscard]] Vector2I SnapToConsole(const Vector2I& position) noexcept;

		// Other
		void Sleep(const uint32_t ms) noexcept;

		template<typename Ret = void, typename... Args>
		void RunAsync(const std::function<Ret(Args&&...)>& func, Args&&... args) noexcept {
			std::thread(func, std::forward<Args>(args)...).detach();
		}
		
		// Key
		[[nodiscard]] bool IsKeyPressed(const uint8_t key) noexcept;
		[[nodiscard]] std::vector<uint8_t> GetPressedKeys(void) noexcept;

		// Map
		template<typename T1, typename T2>
		void IterateMap(const std::unordered_map<T1, T2>& map, const std::function<void(T1, T2)>& callbackFunc) noexcept {
			if (map.empty())
				return;

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

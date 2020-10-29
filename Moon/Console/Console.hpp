// Console.hpp
//
// Functions for general console manipulation

#pragma once

#ifdef _MSC_VER
#pragma warning(disable : 4838)
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include "../Macros.hpp"
#include "../Misc.hpp"

#include <unordered_map>
#include <Windows.h>

namespace Moon {
	namespace Console {
		HANDLE GetHandle(const DWORD type = STD_OUTPUT_HANDLE) noexcept;
		HWND GetConsole(void) noexcept;

		void SetWindowSize(const Vector2& size) noexcept;
		void SetBufferSize(const Vector2& size) noexcept;
		void SetWindowPosition(const Vector2& pos) noexcept;

		Vector2 GetWindowSize(void) noexcept;
		Vector2 GetBufferSize(void) noexcept;
		Rect GetWindowPosition(void) noexcept;

		void Center(void) noexcept;

		bool IsCursorWithin(void) noexcept;

		// Buffer
#ifdef CPP17GRT
		inline std::unordered_map<std::string, int32_t> colors = {
			{"dark_blue", 1},
			{"green", 2},
			{"light_blue", 3},
			{"red", 4},
			{"purple", 5},
			{"orange", 6},
			{"light_gray", 7},
			{"dark_gray", 8},
			{"blue", 9},
			{"light_green", 10},
			{"cyan", 11},
			{"light_red", 12},
			{"pink", 13},
			{"yellow", 14},
			{"white", 15}
		};
#else
		extern std::unordered_map<std::string, int32_t> colors;
#endif
		void GotoAxis(const Vector2& axis) noexcept;

		void SetColor(const int32_t color) noexcept;
		void SetColor(const std::string& color) noexcept;

		void ColorPrint(const int32_t color, const std::string& text) noexcept;
		void ColorPrint(const std::string& color, const std::string& text) noexcept;

		void AxisColorPrint(const Vector2& pos, const int32_t color, const std::string& text) noexcept;
		void AxisColorPrint(const Vector2& pos, const std::string& color, const std::string& text) noexcept;
	}
}
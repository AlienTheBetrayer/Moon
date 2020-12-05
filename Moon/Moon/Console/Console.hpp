// Console.hpp
//
// Functions for general console manipulation

#pragma once

#include "../../IncludeSettings.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4838)
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include "../Macros.hpp"

#include "Rect.hpp"
#include "Vector2.hpp"

#ifndef MOON_DISABLE_MISC
#include "../Misc/Misc.hpp"
#endif

#include <unordered_map>
#include <Windows.h>

namespace Moon {
	namespace Console {
		[[nodiscard]] HANDLE GetHandle(const DWORD type = STD_OUTPUT_HANDLE) noexcept;
		[[nodiscard]] HWND GetConsole(void) noexcept;

		// Set console's properties
		void SetWindowSize(const Vector2I& size) noexcept;
		void SetBufferSize(const Vector2I& size) noexcept;
		void SetWindowPosition(const Vector2I& pos) noexcept;
		void SetWindowBounds(const RectI& bounds) noexcept;

		// Get console's properties
		[[nodiscard]] Vector2I GetWindowSize(void) noexcept;
		[[nodiscard]] Vector2I GetBufferSize(void) noexcept;
		[[nodiscard]] RectI GetWindowBounds(void) noexcept;

		void Center(void) noexcept;
		void SetTitle(const std::string& title) noexcept;
		[[nodiscard]] std::string GetTitle(void) noexcept;

		// Console selection
		void SwitchConsoleSelection(void) noexcept;
		void SetConsoleSelection(const bool selection = false) noexcept;

		// Cursor
#ifndef MOON_DISABLE_MISC
		[[nodiscard]] bool IsCursorWithin(void) noexcept;
#endif

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

		inline bool enabledConsoleSelection = true;
#else
		extern std::unordered_map<std::string, int32_t> colors;
		extern bool enabledConsoleSelection;
#endif
		[[nodiscard]] std::pair<std::string, int32_t> GetRandomColor(void) noexcept;

		void GotoAxis(const Vector2I& axis) noexcept;
		void AxisPrint(const Vector2I& axis, const std::string& text) noexcept;

		void SetColor(const int32_t color) noexcept;
		void SetColor(const std::string& color) noexcept;

		void ColorPrint(const int32_t color, const std::string& text) noexcept;
		void ColorPrint(const std::string& color, const std::string& text) noexcept;

		void AxisColorPrint(const Vector2I& pos, const int32_t color, const std::string& text) noexcept;
		void AxisColorPrint(const Vector2I& pos, const std::string& color, const std::string& text) noexcept;
	}
}
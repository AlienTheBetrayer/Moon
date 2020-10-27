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

#include "../Misc.hpp"

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

		void GotoAxis(const Vector2& axis) noexcept;
	}
}
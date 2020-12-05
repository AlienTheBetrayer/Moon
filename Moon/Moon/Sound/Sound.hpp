// Sound.hpp
//
// Moon Engine's Sound component

#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include "../../IncludeSettings.hpp"

#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib")

#include <string>

namespace Moon {
	namespace Sound {
		void Play(const std::string& path) noexcept;
		void PlayFrom(const std::string& path, const uint32_t ms) noexcept;
	}
}
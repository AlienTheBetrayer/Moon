// Debug.hpp
//
// Moon Engine's Debug component
// Each debug call will be saved to a file in the folder called moon-logs

#pragma once

#include "../Macros.hpp"

#ifdef CPP17GRT
#include "../vendor/ColorFormatter.hpp"
#include <filesystem>
namespace fs = std::filesystem;
#else
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

#include <cstdio>
#include <ctime>
#include <fstream>
#include <string>

namespace Moon {
	namespace Debug {
		enum class LogTypes {
			Message,
			Information,
			Warning,
			Error
		};

		void Message(const char* message) noexcept;
		void Info(const char* message) noexcept;
		void Warn(const char* message) noexcept;
		void Error(const char* message) noexcept;
	}
}
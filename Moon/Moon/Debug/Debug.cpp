// Debug.cpp

#include "Debug.hpp"

namespace {
	void LogType(const Moon::Debug::LogTypes logType, const char* message) noexcept
	{
		if (!fs::exists("moon-logs"))
			fs::create_directory("moon-logs");

		static std::ofstream file("moon-logs/" + std::to_string(time(0)) + "-moonlog.txt");

		const char* logString = "";
#ifndef MOON_DISABLE_CONSOLE
		const char* logColor = "";
#endif

		switch (logType) {
		case Moon::Debug::LogTypes::Message:
			logString = "MSG";
#ifndef MOON_DISABLE_CONSOLE
			logColor = "white";
#endif
			break;
		case Moon::Debug::LogTypes::Information:
			logString = "INFO";
#ifndef MOON_DISABLE_CONSOLE
			logColor = "light_blue";
#endif
			break;
		case Moon::Debug::LogTypes::Warning:
			logString = "WARN";
#ifndef MOON_DISABLE_CONSOLE
			logColor = "orange";
#endif
			break;
		case Moon::Debug::LogTypes::Error:
			logString = "ERR";
#ifndef MOON_DISABLE_CONSOLE
			logColor = "light_red";
#endif
			break;
		}
		 
#ifndef MOON_DISABLE_CONSOLE
		Moon::Console::ColorPrint(logColor, "[" + std::string(logString) + "] ");
#else
		printf("[%s] ", logString);
#endif
		printf("%s\n", message);

		file << "[" << logString << "] " << message << "\n";
	}
}

void Moon::Debug::Message(const char* message) noexcept {
	LogType(LogTypes::Message, message);
}

void Moon::Debug::Info(const char* message) noexcept {
	LogType(LogTypes::Information, message);
}

void Moon::Debug::Warn(const char* message) noexcept {
	LogType(LogTypes::Warning, message);
}

void Moon::Debug::Error(const char* message) noexcept {
	LogType(LogTypes::Error, message);
}
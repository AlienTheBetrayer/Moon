// Debug.cpp

#include "Debug.hpp"

namespace {
	void LogType(const Moon::Debug::LogTypes logType, const char* message) noexcept
	{
		if (!fs::exists("moon-logs"))
			fs::create_directory("moon-logs");

		static std::ofstream file("moon-logs/" + std::to_string(time(0)) + "-moonlog.txt");

		const char* logString = "";
		const char* logColor = "";

		switch (logType) {
		case Moon::Debug::LogTypes::Message:
			logString = "MSG";
			logColor = "white";
			break;
		case Moon::Debug::LogTypes::Information:
			logString = "INFO";
			logColor = "light_blue";
			break;
		case Moon::Debug::LogTypes::Warning:
			logString = "WARN";
			logColor = "orange";
			break;
		case Moon::Debug::LogTypes::Error:
			logString = "ERR";
			logColor = "light_red";
			break;
		}

		Moon::Console::ColorPrint(logColor, "[" + std::string(logString) + "] ");
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
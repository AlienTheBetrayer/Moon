// Debug.cpp

#include "Debug.hpp"

namespace {
	void LogType(const Moon::Debug::LogTypes logType, const char* message) noexcept
	{
		if (!fs::exists("moon-logs"))
			fs::create_directory("moon-logs");

		static std::ofstream file("moon-logs/" + std::to_string(time(0)) + "-moonlog.txt");

		const char* logString = "";
#ifdef CPP17GRT	
		const char* logColor = "";
#endif

		switch (logType) {
		case Moon::Debug::LogTypes::Message:
			logString = "MSG";
#ifdef CPP17GRT
			logColor = "white";
#endif
			break;
		case Moon::Debug::LogTypes::Information:
			logString = "INFO";
#ifdef CPP17GRT
			logColor = "light_blue";
#endif
			break;
		case Moon::Debug::LogTypes::Warning:
			logString = "WARN";
#ifdef CPP17GRT
			logColor = "orange";
#endif
			break;
		case Moon::Debug::LogTypes::Error:
			logString = "ERR";
#ifdef CPP17GRT
			logColor = "light_red";
#endif
			break;
		}

#ifdef CPP17GRT
		console::colorset(console::colors[logColor]);
		printf("[%s] ", logString);
		console::colorset(console::colors["light_gray"]);
		printf("%s\n", message);
#else
		printf("[%s] %s\n", logString, message);
#endif

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
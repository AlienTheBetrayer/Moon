#pragma once

#include <chrono>

namespace Moon {
	namespace Time {
		enum class TimeType {
			Second,
			Millisecond,
			Microsecond,
			Nanosecond
		};

		using timepoint_t = std::chrono::high_resolution_clock::time_point;

		class Clock {
		public:
			explicit Clock(void) = default;
			~Clock(void) = default;

			void Start(void) noexcept;
			void Stop(void) noexcept;
			[[nodiscard]] double Get(const TimeType timeType = TimeType::Second) noexcept;
		private:
			timepoint_t m_Start;
			timepoint_t m_End;
		};
	}
}


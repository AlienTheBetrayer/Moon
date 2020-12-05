#include "Clock.hpp"

void Moon::Time::Clock::Start(void) noexcept
{
	m_Start = std::chrono::high_resolution_clock::now();
}

void Moon::Time::Clock::Stop(void) noexcept
{
	m_End = std::chrono::high_resolution_clock::now();
}

double Moon::Time::Clock::Get(const TimeType timeType) noexcept
{
	return std::chrono::duration<double>(m_End - m_Start).count() * (timeType == TimeType::Second ? 1 : pow(10, static_cast<int32_t>(timeType) * 3));
}
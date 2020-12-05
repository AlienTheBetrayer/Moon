#include "WindowSkeleton.hpp"

Moon::Moving::WindowSkeleton::WindowSkeleton(void) noexcept
{
	SetCurrentBounds();
}

void Moon::Moving::WindowSkeleton::SetBounds(const RectI& bounds) noexcept
{
	m_Bounds = bounds;
}

void Moon::Moving::WindowSkeleton::SetCurrentBounds(void) noexcept
{
	m_Bounds = Moon::Console::GetWindowBounds();
}

RectI& Moon::Moving::WindowSkeleton::GetCurrentBounds(void) noexcept
{
	return m_Bounds;
}

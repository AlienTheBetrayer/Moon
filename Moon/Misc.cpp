#include "Misc.hpp"
// Random.cpp

int32_t Moon::Misc::RandomRange(const int32_t min, const int32_t max) noexcept
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(min, max);

	return distr(gen);
}

bool Moon::Misc::RandomBoolean(void) noexcept
{
	return static_cast<bool>(RandomRange(0, 1));
}

bool Moon::Misc::IsWithinRect(const Vector2& pos, const Rect& rect) noexcept
{
	return pos.x >= rect.left && pos.x <= rect.right && pos.y >= rect.top && pos.y <= rect.bottom;
}

Vector2 Moon::Misc::GetCursorPosition(void) noexcept
{
	POINT point;
	GetCursorPos(&point);

	return Vector2{ point.x, point.y };
}

Vector2 Moon::Misc::SnapToConsole(const Vector2& position) noexcept
{
	POINT point;
	point.x = position.x;
	point.y = position.y;
	
	static const HWND console = GetConsoleWindow();
	ScreenToClient(console, &point);

	return Vector2{ point.x, point.y };
}

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

void Moon::Misc::Sleep(const uint32_t ms) noexcept
{
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

bool Moon::Misc::IsKeyPressed(const uint8_t key) noexcept
{
	return GetAsyncKeyState(key) < 0;
}

std::vector<uint8_t> Moon::Misc::GetPressedKeys(void) noexcept
{
	static constexpr const int32_t from = 65;
	static constexpr const int32_t to = 90;

	std::vector<uint8_t> pressedKeys = {};

	uint8_t arr[256]{ 0 };
	GetKeyState(0);

	if (GetKeyboardState(arr))
		for (int32_t i = from; i <= to; ++i)
			if (static_cast<int32_t>(arr[i]) >> 7)
				pressedKeys.emplace_back(static_cast<uint8_t>(i));

	return pressedKeys;
}

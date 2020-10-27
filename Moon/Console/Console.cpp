// Console.cpp

#include "Console.hpp"

HANDLE Moon::Console::GetHandle(const DWORD type) noexcept
{
	static const HANDLE hOut = GetStdHandle(type);

	return hOut;
}

HWND Moon::Console::GetConsole(void) noexcept
{
	static const HWND console = GetConsoleWindow();

	return console;
}

void Moon::Console::SetWindowSize(const Vector2& size) noexcept
{
	const HWND console = GetConsole();

	RECT cRect;
	GetWindowRect(console, &cRect);

	MoveWindow(console, cRect.left, cRect.top, size.x, size.y, TRUE);
}

void Moon::Console::SetBufferSize(const Vector2& size) noexcept
{
	COORD buffer = { size.x, size.y };
	SetConsoleScreenBufferSize(GetHandle(), buffer);
}

void Moon::Console::SetWindowPosition(const Vector2& pos) noexcept
{
	SetWindowPos(GetConsole(), nullptr, pos.x, pos.y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

Vector2 Moon::Console::GetWindowSize(void) noexcept
{
	Rect cRect = GetWindowPosition();

	return Vector2{ cRect.right - cRect.left, cRect.bottom - cRect.top };
}

Vector2 Moon::Console::GetBufferSize(void) noexcept
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetHandle(), &csbi);

	return Vector2{ csbi.dwSize.X, csbi.dwSize.Y };
}

Rect Moon::Console::GetWindowPosition(void) noexcept
{
	RECT cRect;
	GetWindowRect(GetConsole(), &cRect);

	return Rect{ cRect.left, cRect.right, cRect.top, cRect.bottom };
}

void Moon::Console::Center(void) noexcept
{
	RECT cRect;
	GetWindowRect(GetConsole(), &cRect);

	RECT mRect;
	GetWindowRect(GetDesktopWindow(), &mRect);
	
	SetWindowPosition({ mRect.right / 2 - (cRect.right - cRect.left) / 2, mRect.bottom / 2 - (cRect.bottom - cRect.top) / 2 });
}

bool Moon::Console::IsCursorWithin(void) noexcept
{
	Vector2 pos = Moon::Misc::GetCursorPosition();
	Rect rect = GetWindowPosition();

	return Moon::Misc::IsWithinRect(pos, rect);
}

void Moon::Console::GotoAxis(const Vector2& axis) noexcept
{
	COORD coord;
	coord.X = axis.x;
	coord.Y = axis.y;

	SetConsoleCursorPosition(GetHandle(), coord);
}

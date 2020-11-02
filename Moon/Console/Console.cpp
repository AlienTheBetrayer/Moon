// Console.cpp


#include "Console.hpp"

#ifndef CPP17GRT
std::unordered_map<std::string, int> Moon::Console::colors = {
	{"dark_blue", 1},
	{"green", 2},
	{"light_blue", 3},
	{"red", 4},
	{"purple", 5},
	{"orange", 6},
	{"light_gray", 7},
	{"dark_gray", 8},
	{"blue", 9},
	{"light_green", 10},
	{"cyan", 11},
	{"light_red", 12},
	{"pink", 13},
	{"yellow", 14},
	{"white", 15}
};

bool Moon::Console::enabledConsoleSelection = true;
#endif

HANDLE Moon::Console::GetHandle(const DWORD type) noexcept
{
	const HANDLE hOut = GetStdHandle(type);

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

void Moon::Console::SwitchConsoleSelection(void) noexcept
{
	static const HANDLE hIn = GetHandle(STD_INPUT_HANDLE);

	SetConsoleMode(hIn, enabledConsoleSelection ? ~ENABLE_QUICK_EDIT_MODE : ENABLE_QUICK_EDIT_MODE);

	enabledConsoleSelection = !enabledConsoleSelection;
}

void Moon::Console::SetConsoleSelection(const bool selection) noexcept
{
	if (selection) {
		if (!enabledConsoleSelection)
			SwitchConsoleSelection();
	}
	else {
		if (enabledConsoleSelection)
			SwitchConsoleSelection();
	}
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

void Moon::Console::AxisPrint(const Vector2& axis, const std::string& text) noexcept
{
	GotoAxis(axis);
	printf(text.c_str());
}

void Moon::Console::SetColor(const int32_t color) noexcept
{
	static const HANDLE hOut = GetHandle();
	SetConsoleTextAttribute(hOut, static_cast<WORD>(color));
}

void Moon::Console::SetColor(const std::string& color) noexcept
{
	SetColor(colors[color]);
}

void Moon::Console::ColorPrint(const int32_t color, const std::string& text) noexcept
{
	SetColor(color);
	printf(text.c_str());
	SetColor("light_gray");
}

void Moon::Console::ColorPrint(const std::string& color, const std::string& text) noexcept
{
	ColorPrint(colors[color], text);
}

void Moon::Console::AxisColorPrint(const Vector2& pos, const int32_t color, const std::string& text) noexcept
{
	GotoAxis(pos);
	ColorPrint(color, text);
}

void Moon::Console::AxisColorPrint(const Vector2& pos, const std::string& color, const std::string& text) noexcept
{
	AxisColorPrint(pos, colors[color], text);
}

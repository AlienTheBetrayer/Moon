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

void Moon::Console::SetWindowSize(const Vector2I& size) noexcept
{
	const HWND console = GetConsole();

	RECT cRect;
	GetWindowRect(console, &cRect);

	MoveWindow(console, cRect.left, cRect.top, size.x, size.y, TRUE);
}

void Moon::Console::SetBufferSize(const Vector2I& size) noexcept
{
	COORD buffer = { size.x, size.y };
	SetConsoleScreenBufferSize(GetHandle(), buffer);
}

void Moon::Console::SetWindowPosition(const Vector2I& pos) noexcept
{
	SetWindowPos(GetConsole(), nullptr, pos.x, pos.y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void Moon::Console::SetWindowBounds(const RectI& bounds) noexcept
{
	SetWindowPos(GetConsole(), nullptr, bounds.left, bounds.top, bounds.right - bounds.left, bounds.bottom - bounds.top, SWP_NOZORDER);
}

Vector2I Moon::Console::GetWindowSize(void) noexcept
{
	Rect cRect = GetWindowBounds();

	return Vector2I{ cRect.right - cRect.left, cRect.bottom - cRect.top };
}

Vector2I Moon::Console::GetBufferSize(void) noexcept
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetHandle(), &csbi);

	return Vector2I{ csbi.dwSize.X, csbi.dwSize.Y };
}

RectI Moon::Console::GetWindowBounds(void) noexcept
{
	RECT cRect;
	GetWindowRect(GetConsole(), &cRect);

	return RectI{ cRect.left, cRect.right, cRect.top, cRect.bottom };
}

void Moon::Console::Center(void) noexcept
{
	RECT cRect;
	GetWindowRect(GetConsole(), &cRect);

	RECT mRect;
	GetWindowRect(GetDesktopWindow(), &mRect);
	
	SetWindowPosition({ mRect.right / 2 - (cRect.right - cRect.left) / 2, mRect.bottom / 2 - (cRect.bottom - cRect.top) / 2 });
}

void Moon::Console::SetTitle(const std::string& title) noexcept
{
	SetConsoleTitleA(title.c_str());
}

// BROKEN
std::string Moon::Console::GetTitle(void) noexcept
{
	char data[50];
	GetConsoleTitleA(data, 50);

	return std::string(data);
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

#ifndef MOON_DISABLE_MISC
bool Moon::Console::IsCursorWithin(void) noexcept
{
	Vector2 pos = Moon::Misc::GetCursorPosition();
	Rect rect = GetWindowBounds();

	return Moon::Misc::IsWithinRect(pos, rect);
}	
#endif

[[nodiscard]] std::pair<std::string, int32_t> Moon::Console::GetRandomColor(void) noexcept
{
	const auto it = std::next(colors.begin(), rand() % 14 + 1);
	return std::make_pair(it->first, it->second);
}

void Moon::Console::GotoAxis(const Vector2I& axis) noexcept
{
	COORD coord;
	coord.X = axis.x;
	coord.Y = axis.y;

	SetConsoleCursorPosition(GetHandle(), coord);
}

void Moon::Console::AxisPrint(const Vector2I& axis, const std::string& text) noexcept
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

void Moon::Console::AxisColorPrint(const Vector2I& pos, const int32_t color, const std::string& text) noexcept
{
	GotoAxis(pos);
	ColorPrint(color, text);
}

void Moon::Console::AxisColorPrint(const Vector2I& pos, const std::string& color, const std::string& text) noexcept
{
	AxisColorPrint(pos, colors[color], text);
}

#ifdef _MSC_VER
#pragma warning(pop)
#endif
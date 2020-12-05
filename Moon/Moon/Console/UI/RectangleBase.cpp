// RectangleBase.cpp

#include "RectangleBase.hpp"

Moon::Console::RectangleBase::RectangleBase(void) noexcept
{
	Initialize();
}

Moon::Console::RectangleBase::RectangleBase(const RectI& bounds) noexcept
{
	Initialize();
	SetBounds(bounds);
}

void Moon::Console::RectangleBase::ApplyRenderingStyle(const RenderingStyle& style) noexcept
{
	*m_RenderingStyle = style;
}

std::shared_ptr<Moon::Console::RenderingStyle>& Moon::Console::RectangleBase::GetRenderingStyle(void) noexcept
{
	return m_RenderingStyle;
}

void Moon::Console::RectangleBase::SetColor(const char* color) noexcept
{
	m_RenderingStyle->color = color;
}

void Moon::Console::RectangleBase::SetVisibility(const bool visibility) noexcept
{
	m_RenderingStyle->visible = visibility;
}

void Moon::Console::RectangleBase::SetSymbol(const char symbol) noexcept
{
	m_RenderingStyle->symbol = symbol;
}

void Moon::Console::RectangleBase::SetFill(const bool fill) noexcept
{
	m_RenderingStyle->fill = fill;
}

void Moon::Console::RectangleBase::SetOnHoverColor(const char* color) noexcept
{
	m_RenderingStyle->hoverColor = color;
}

void Moon::Console::RectangleBase::SetOnPressedColor(const char* color) noexcept
{
	m_RenderingStyle->pressedColor = color;
}

void Moon::Console::RectangleBase::SetOnReleasedColor(const char* color) noexcept
{
	m_RenderingStyle->releasedColor = color;
}

void Moon::Console::RectangleBase::SetTextAlignment(const Moon::Console::RenderingStyle::TextAlignment textAlignment) noexcept
{
	m_RenderingStyle->textAlignment = textAlignment;
}

void Moon::Console::RectangleBase::SetTextColor(const char* color) noexcept
{
	m_RenderingStyle->textColor = color;
}

void Moon::Console::RectangleBase::SetFitInOutline(const bool fit) noexcept
{
	m_RenderingStyle->fitInOutline = fit;
}

void Moon::Console::RectangleBase::SetCheckBoxColor(const char* color) noexcept
{
	m_RenderingStyle->checkboxColor = color;
}

void Moon::Console::RectangleBase::SetCheckBoxToggleColor(const char* color) noexcept
{
	m_RenderingStyle->checkboxToggleColor = color;
}

void Moon::Console::RectangleBase::SetBounds(const RectI& bounds) noexcept
{
	m_Bounds = RectI{ bounds.left * 8, bounds.right * 8 - 1, bounds.top * 16, bounds.bottom * 16 + 15 };
}

RectI Moon::Console::RectangleBase::GetBounds(void) const noexcept
{
	return m_Bounds;
}

bool Moon::Console::RectangleBase::IsCursorWithin(void) const noexcept
{
	const Vector2I& pos = Moon::Misc::SnapToConsole(Moon::Misc::GetCursorPosition());

	return Moon::Misc::IsWithinRect(pos, m_Bounds);
}

void Moon::Console::RectangleBase::Initialize(void) noexcept
{
	m_RenderingStyle = std::make_shared<Moon::Console::RenderingStyle>();
	Moon::Console::SetConsoleSelection(false);
}

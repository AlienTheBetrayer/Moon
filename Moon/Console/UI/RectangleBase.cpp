	#include "RectangleBase.hpp"

Moon::Console::RectangleBase::RectangleBase(void) noexcept
{
	Initialize();
}

Moon::Console::RectangleBase::RectangleBase(const Rect& bounds) noexcept
{
	Initialize();
	SetBounds(bounds);
}

void Moon::Console::RectangleBase::ApplyRenderingStyle(const RenderingStyle& style) noexcept
{
	*m_RenderingStyle = style;
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

void Moon::Console::RectangleBase::SetBounds(const Rect& bounds) noexcept
{
	m_Bounds = Rect{ bounds.left * 8, bounds.right * 8 - 1, bounds.top * 16, bounds.bottom * 16 + 15 };
}

Rect Moon::Console::RectangleBase::GetBounds(void) const noexcept
{
	return Rect{m_Bounds.left / 8, m_Bounds.right / 8 - 1, m_Bounds.top / 16, m_Bounds.bottom / 16 - 15};
}

bool Moon::Console::RectangleBase::IsCursorWithin(void) const noexcept
{
	const Vector2& pos = Moon::Misc::SnapToConsole(Moon::Misc::GetCursorPosition());

	return Moon::Misc::IsWithinRect(pos, m_Bounds);
}

void Moon::Console::RectangleBase::Initialize(void) noexcept
{
	m_RenderingStyle = new RenderingStyle();
}

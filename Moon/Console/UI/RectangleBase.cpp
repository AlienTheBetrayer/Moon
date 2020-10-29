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

void Moon::Console::RectangleBase::SetBounds(const Rect& bounds) noexcept
{
	m_Bounds = Rect{ bounds.left * 8, bounds.right * 8 - 1, bounds.top * 16, bounds.bottom * 16 + 15 };
}

Rect Moon::Console::RectangleBase::GetBounds(void) noexcept
{
	return m_Bounds;
}

bool Moon::Console::RectangleBase::IsCursorWithin(void) noexcept
{
	const Vector2& pos = Moon::Misc::SnapToConsole(Moon::Misc::GetCursorPosition());

	return Moon::Misc::IsWithinRect(pos, m_Bounds);
}

void Moon::Console::RectangleBase::Initialize(void) noexcept
{
	m_RenderingStyle = new RenderingStyle();
}

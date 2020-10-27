#include "Rectangle.hpp"

Moon::Console::Rectangle::Rectangle(const Rect& bounds) noexcept
{
    SetBounds(bounds);
}

void Moon::Console::Rectangle::SetBounds(const Rect& bounds) noexcept
{
    m_Bounds = Rect{ bounds.left * 8, bounds.right * 8 - 1, bounds.top * 16, bounds.bottom * 16 + 15 };
}

Rect Moon::Console::Rectangle::GetBounds(void) noexcept
{
    return m_Bounds;
}

bool Moon::Console::Rectangle::IsCursorWithin(void) noexcept
{
    const Vector2& pos = Moon::Misc::SnapToConsole(Moon::Misc::GetCursorPosition());

    return Moon::Misc::IsWithinRect(pos, m_Bounds);
}

void Moon::Console::Rectangle::Render(void) noexcept
{
    for (int32_t y = m_Bounds.top / 16; y <= m_Bounds.bottom / 16; ++y) {
        for (int32_t x = m_Bounds.left / 8; x <= m_Bounds.right / 8; ++x) {
            Moon::Console::GotoAxis({ x, y });
            printf("#");
        }
    }
}

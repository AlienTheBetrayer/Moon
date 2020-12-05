// Rectangle.cpp

#include "Rectangle.hpp"

void Moon::Console::Rectangle::Render(void) noexcept
{
    // PUT THIS IN SOME MISC OR SOMETHING
    if (!m_RenderingStyle->visible)
        return;

    static const auto print = [=](const Vector2I& coords) noexcept -> void {
        Moon::Console::GotoAxis(coords);
        Moon::Console::SetColor(m_RenderingStyle->color);
        printf("%c", m_RenderingStyle->symbol);
    };

    if (m_RenderingStyle->fill) {
        for (int32_t y = m_Bounds.top / 16; y <= m_Bounds.bottom / 16; ++y)
            for (int32_t x = m_Bounds.left / 8; x <= m_Bounds.right / 8; ++x)
                print({ x, y });
    }
    else {
        for (int32_t x = m_Bounds.left / 8; x <= m_Bounds.right / 8; ++x) {
            print({ x, m_Bounds.top / 16 });
            print({ x, m_Bounds.bottom / 16 });
        }

        for (int32_t y = m_Bounds.top / 16; y <= m_Bounds.bottom / 16; ++y) {
            print({ m_Bounds.left / 8, y });
            print({ m_Bounds.right / 8, y });
        }
    }

    Moon::Console::SetColor("light_gray");
}

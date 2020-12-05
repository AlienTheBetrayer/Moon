#include "CheckBox.hpp"

void Moon::Console::CheckBox::Render(void)  noexcept
{
    // PUT THIS IN SOME MISC OR SOMETHING
    if (!m_RenderingStyle->visible)
        return;

    static const auto print = [=](const Vector2I& coords) noexcept -> void {
        Moon::Console::GotoAxis(coords);
        printf("%c", m_RenderingStyle->symbol);
    };

    const auto& x = m_Bounds.left;
    const auto& y = m_Bounds.top;

    // Drawing the checkbox itself
    Moon::Console::SetColor(m_RenderingStyle->checkboxColor);

    for (int32_t i = x / 8; i < x / 8 + 3; ++i) {
        print({ i, y / 16 });
        print({ i, y / 16 + 2 });
    }

    print({ x / 8, y / 16 + 1 });
    print({ x / 8 + 2, y / 16 + 1 });

    if (m_Toggled) {
        Moon::Console::SetColor(m_RenderingStyle->checkboxToggleColor);
        print({ x / 8 + 1, y / 16 + 1 });
    }
    else {
        Moon::Console::AxisPrint({ x / 8 + 1, y / 16 + 1 }, " ");
    }

    // Drawing the text
    Moon::Console::SetColor(m_RenderingStyle->textColor);
    Moon::Console::GotoAxis({ x / 8 + 4, y / 16 + 1 });
    printf("%s", m_Text.c_str());
    Moon::Console::SetColor("light_gray");
}

bool Moon::Console::CheckBox::IsCursorWithin(void) noexcept
{
    const Vector2I& pos = Moon::Misc::SnapToConsole(Moon::Misc::GetCursorPosition());

    return Moon::Misc::IsWithinRect(pos, {m_Bounds.left, m_Bounds.left + 3 * 8, m_Bounds.top, m_Bounds.top + 3 * 16});
}

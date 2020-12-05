// TextLabel.cpp

#include "TextLabel.hpp"

void Moon::Console::TextLabel::Render(void) noexcept
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

    Vector2I vec = {};

    const bool& fit = m_RenderingStyle->fitInOutline;
    
    switch (m_RenderingStyle->textAlignment) {
    // Top
    case RenderingStyle::TextAlignment::TopLeft:
        vec.x = m_Bounds.left / 8;
        vec.y = m_Bounds.top / 16;

        if (fit)
            ++vec.x;
            ++vec.y;

        break;
    case RenderingStyle::TextAlignment::TopCenter:
        vec.x = m_Bounds.left / 8 + (m_Bounds.right - m_Bounds.left) / 16 - m_Text.length() / 2;
        vec.y = m_Bounds.top / 16;

        if (fit)
            ++vec.y;

        break;
    case RenderingStyle::TextAlignment::TopRight:
        vec.x = m_Bounds.right / 8 - m_Text.length() + 1;
        vec.y = m_Bounds.top / 16;

        if (fit) {
            --vec.x;
            ++vec.y;
        }
        break;

    // Center
    case RenderingStyle::TextAlignment::CenterLeft:
        vec.x = m_Bounds.left / 8;
        vec.y = m_Bounds.top / 16 + (m_Bounds.bottom - m_Bounds.top) / 32;
        
        if (fit)
            ++vec.x;

        break;
    case RenderingStyle::TextAlignment::Center:
        vec.x = m_Bounds.left / 8 + (m_Bounds.right - m_Bounds.left) / 16 - m_Text.length() / 2;
        vec.y = m_Bounds.top / 16 + (m_Bounds.bottom - m_Bounds.top) / 32;
        break;
    case RenderingStyle::TextAlignment::CenterRight:
        vec.x = m_Bounds.right / 8 - m_Text.length() + 1;
        vec.y = m_Bounds.top / 16 + (m_Bounds.bottom - m_Bounds.top) / 32;

        if (fit)
            --vec.x;

        break;  

    // Bottom
    case RenderingStyle::TextAlignment::BottomLeft:
        vec.x = m_Bounds.left / 8;
        vec.y = m_Bounds.bottom / 16;

        if (fit) {
            ++vec.x;
            --vec.y;
        }
        break;
    case RenderingStyle::TextAlignment::BottomCenter:
        vec.x = m_Bounds.left / 8 + (m_Bounds.right - m_Bounds.left) / 16 - m_Text.length() / 2;
        vec.y = m_Bounds.bottom / 16;

        if (fit)
            --vec.y;

        break;
    case RenderingStyle::TextAlignment::BottomRight:
        vec.x = m_Bounds.right / 8 - m_Text.length() + 1;
        vec.y = m_Bounds.bottom / 16;

        if (fit) {
            --vec.x;
            --vec.y;
        }
        break;
    }
    
    Moon::Console::SetColor(m_RenderingStyle->textColor);
    Moon::Console::GotoAxis(vec);
    printf("%s", m_Text.c_str());
   

    Moon::Console::SetColor("light_gray");
}

void Moon::Console::TextLabel::SetText(const std::string& str) noexcept
{
    m_Text = str;
}

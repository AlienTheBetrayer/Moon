#include "TextBox.hpp"

void Moon::Console::TextBox::Initialize(void) noexcept
{
	m_RenderingStyle->fill = false;
}

void Moon::Console::TextBox::Render(void) noexcept
{
	static bool first = true;

	if (first) {
		first = false;
		Initialize();
	}

	if (!m_RenderingStyle->visible)
		return;

	static const auto print = [=](const Vector2I& coords) noexcept -> void {
		Moon::Console::GotoAxis(coords);
		Moon::Console::SetColor(m_RenderingStyle->color);
		printf("%c", m_RenderingStyle->symbol);
	};

	for (int32_t x = m_Bounds.left / 8; x <= m_Bounds.right / 8; ++x) {
		print({ x, m_Bounds.top / 16 });
		print({ x, m_Bounds.bottom / 16 });
	}

	for (int32_t y = m_Bounds.top / 16; y <= m_Bounds.bottom / 16; ++y) {
		print({ m_Bounds.left / 8, y });
		print({ m_Bounds.right / 8, y });
	}

	Moon::Console::GotoAxis({ m_Bounds.left / 8 + 2, m_Bounds.top / 16 + (m_Bounds.bottom - m_Bounds.top) / 32 });

	if (m_Text == "") {
		ClearText();
	}
	else {
		printf("%s", m_Text.c_str());
	}
}

void Moon::Console::TextBox::ClearText(void) const noexcept
{
	for (int32_t i = 0; i < (m_Bounds.right - m_Bounds.left) / 8 - 2; ++i) {
		Moon::Console::GotoAxis({ m_Bounds.left / 8 + 2 + i, m_Bounds.top / 16 + (m_Bounds.bottom - m_Bounds.top) / 32 });
		printf(" ");
	}
}

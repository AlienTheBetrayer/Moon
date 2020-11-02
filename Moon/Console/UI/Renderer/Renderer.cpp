// Renderer.cpp	

#include "Renderer.hpp"

void Moon::Console::Renderer::Reserve(const std::size_t n) noexcept
{
	m_Rectangles.reserve(n);
}

void Moon::Console::Renderer::PushSingle(RectangleVirtualBase* base) noexcept
{
	m_Rectangles.emplace_back(base);
}

void Moon::Console::Renderer::PopSingle(void) noexcept
{
	m_Rectangles.pop_back();
}

void Moon::Console::Renderer::Pop(const std::size_t n) noexcept
{
	for (std::size_t i = 0; i < n; ++i)
		m_Rectangles.pop_back();
}

void Moon::Console::Renderer::RenderAll(void) const noexcept
{
	for (RectangleVirtualBase* base : m_Rectangles)
		base->Render();
}

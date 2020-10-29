// Renderer.cpp	

#include "Renderer.hpp"

void Moon::Console::Renderer::Reserve(const std::size_t n) noexcept
{
	rectangles.reserve(n);
}

void Moon::Console::Renderer::PushSingle(RectangleVirtualBase* base) noexcept
{
	rectangles.emplace_back(base);
}

void Moon::Console::Renderer::PopSingle(void) noexcept
{
	rectangles.pop_back();
}

void Moon::Console::Renderer::Pop(const std::size_t n) noexcept
{
	for (std::size_t i = 0; i < n; ++i)
		rectangles.pop_back();
}

void Moon::Console::Renderer::RenderAll(void) noexcept
{
	for (RectangleVirtualBase* base : rectangles)
		base->Render();
}

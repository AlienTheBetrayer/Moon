// RectangleBase.hpp
//
// A class that allows polymorphism and neat stuff like Renderer and EventHandler classes to work

#pragma once

#include "../Rect.hpp"
#include "../Vector2.hpp"

#include "../../Misc/Misc.hpp"

#include "RenderingStyle.hpp"

namespace Moon {
	namespace Console {
		class RectangleVirtualBase
		{
		public:
			virtual void ApplyRenderingStyle(const RenderingStyle& style) noexcept = 0;
			virtual void SetBounds(const Rect& bounds) noexcept = 0;
			[[nodiscard]] virtual Rect GetBounds(void) const noexcept = 0;
			[[nodiscard]] virtual bool IsCursorWithin(void) const noexcept = 0;
			virtual void Render(void) const noexcept = 0;
		};
	}
}
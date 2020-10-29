// RectangleBase.hpp
//
// A class that allows polymorphism and neat stuff like Renderer class to work

#pragma once

#include "../Rect.hpp"
#include "../Vector2.hpp"

#include "../../Misc.hpp"

#include "RenderingStyle.hpp"

namespace Moon {
	namespace Console {
		class RectangleVirtualBase
		{
		public:
			virtual void ApplyRenderingStyle(const RenderingStyle& style) noexcept = 0;
			virtual void SetBounds(const Rect& bounds) noexcept = 0;
			virtual Rect GetBounds(void) noexcept = 0;
			virtual bool IsCursorWithin(void) noexcept = 0;
			virtual void Render(void) noexcept = 0;
		};
	}
}
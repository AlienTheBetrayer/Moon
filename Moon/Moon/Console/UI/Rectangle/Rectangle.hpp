// Rectangle.hpp
//
// UI element that can show a rectangle with different colors

#pragma once

#include "../RectangleBase.hpp"
#include "../RectangleVirtualBase.hpp"
#include "../../Console.hpp"

namespace Moon {
	namespace Console {
		class Rectangle : public RectangleBase
		{
		public:
			using RectangleBase::RectangleBase;

			void Render(void) noexcept;

			~Rectangle(void) noexcept = default;
		};
	}
}
// Rectangle.hpp

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

			void Render(void) const noexcept;

			~Rectangle(void) noexcept = default;
		};
	}
}
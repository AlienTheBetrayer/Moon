#pragma once

#include "../../Console.hpp"
#include "../RectangleFrame.hpp"
#include "../../../Misc.hpp"

namespace Moon {
	namespace Console {
		class Rectangle : public Moon::Console::RectangleFrame
		{
		public:
			Rectangle(void) = default;
			~Rectangle(void) = default;
			Rectangle(const Rect& bounds) noexcept;

			void SetBounds(const Rect& bounds) noexcept;
			Rect GetBounds(void) noexcept;

			bool IsCursorWithin(void) noexcept;

			void Render(void) noexcept;
		private:
			Rect m_Bounds;
		};
	}
}
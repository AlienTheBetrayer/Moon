#pragma once

#include "../../Console.hpp"
#include "../RectangleFrame.hpp"
#include "../../../Misc.hpp"

namespace Moon {
	namespace Console {
		class Button : public Moon::Console::RectangleFrame
		{
		public:
			Button(void) = default;
			~Button(void) = default;
			Button(const Rect& bounds) noexcept;

			void SetBounds(const Rect& bounds) noexcept;
			Rect GetBounds(void) noexcept;

			bool IsCursorWithin(void) noexcept;

			void Render(void) noexcept;	
		private:
			Rect m_Bounds;
		};
	}
}
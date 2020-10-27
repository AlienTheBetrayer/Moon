#pragma once

#include "../ConsoleGeneral.hpp"

namespace Moon {
	namespace Console {
		class RectangleFrame
		{
		public:
			virtual Rect GetBounds(void) = 0;
			virtual void Render(void) = 0;
			virtual bool IsCursorWithin(void) = 0;
		};
	}
}


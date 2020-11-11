// Button.hpp
//
// UI element that you can press on

#pragma once

#include <memory>

#include "../RectangleBase.hpp"
#include "../RectangleVirtualBase.hpp"
#include "../../Console.hpp"

namespace Moon {
	namespace Console {
		class Button : public RectangleBase {
		public:
			using RectangleBase::RectangleBase;

			void Render(void) const noexcept;

			~Button(void) noexcept = default;	
		};
	}
}
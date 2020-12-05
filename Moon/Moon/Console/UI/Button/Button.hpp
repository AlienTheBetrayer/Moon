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

			void Render(void) noexcept;
			void SetText(const std::string& text) noexcept;

			~Button(void) noexcept = default;	
		private:
			std::string m_Text;
		};
	}
}
// TextLabel.hpp
//
// UI element that can display text

#pragma once

#include "../RectangleBase.hpp"
#include "../RectangleVirtualBase.hpp"
#include "../../Console.hpp"

#include <string>

namespace Moon {
	namespace Console {
		class TextLabel : public RectangleBase
		{
		public:
			using RectangleBase::RectangleBase;

			void Render(void) noexcept;

			void SetText(const std::string& str) noexcept;

			~TextLabel(void) noexcept = default;
		protected:
			std::string m_Text;
		};
	}
}
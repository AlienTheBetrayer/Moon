// CheckBox.hpp
//
// UI element that is toggleable. Will change color if you hook it to any event.

#pragma once

#include "../TextLabel/TextLabel.hpp"

namespace Moon {
	namespace Console {
		class CheckBox : public Moon::Console::TextLabel
		{
		public:
			using TextLabel::TextLabel;

			void Render(void) noexcept;

			[[nodiscard]] bool IsCursorWithin(void) noexcept;

			~CheckBox(void) noexcept = default;
			bool m_Toggled = false;
		};
	}
}
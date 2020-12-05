#pragma once

#include "../RectangleBase.hpp"

#include <string>

namespace Moon {
	namespace Console {
			class TextBox : public RectangleBase
			{
			public:
				using RectangleBase::RectangleBase;

				void Initialize(void) noexcept;	
				void Render(void) noexcept;
				void ClearText(void) const noexcept;

				~TextBox(void) noexcept = default;

				std::string m_Text;
			};
	}
}
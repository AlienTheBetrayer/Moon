// RectangleBase.hpp
//
// A base class for all UI elements, which will be inherited from

#pragma once

#include <memory>

#include "../Rect.hpp"
#include "../Vector2.hpp"
#include "../../Misc/Misc.hpp"
#include "../Console.hpp"

#include "RectangleVirtualBase.hpp"
#include "RenderingStyle.hpp"

namespace Moon {
	namespace Console {
		class RectangleBase : public RectangleVirtualBase
		{
		public:
			RectangleBase(void) noexcept;
			explicit RectangleBase(const RectI& bounds) noexcept;

			// Style
			std::shared_ptr<RenderingStyle>& GetRenderingStyle(void) noexcept;
			void ApplyRenderingStyle(const RenderingStyle& style) noexcept;
			void SetColor(const char* color) noexcept;
			void SetVisibility(const bool visibility) noexcept;
			void SetSymbol(const char symbol) noexcept;
			void SetFill(const bool fill) noexcept;
			void SetOnHoverColor(const char* color) noexcept;
			void SetOnPressedColor(const char* color) noexcept;
			void SetOnReleasedColor(const char* color) noexcept;
			void SetTextAlignment(const Moon::Console::RenderingStyle::TextAlignment textAlignment) noexcept;
			void SetTextColor(const char* color) noexcept;
			void SetFitInOutline(const bool fit) noexcept;
			void SetCheckBoxColor(const char* color) noexcept;
			void SetCheckBoxToggleColor(const char* color) noexcept;

			// Bounds
			void SetBounds(const RectI& bounds) noexcept;
			[[nodiscard]] RectI GetBounds(void) const noexcept;
			[[nodiscard]] bool IsCursorWithin(void) const noexcept;

			virtual ~RectangleBase(void) noexcept = default;
		private:
			void Initialize(void) noexcept;
		protected:
			RectI m_Bounds;
			std::shared_ptr<RenderingStyle> m_RenderingStyle;
		};
	}
}
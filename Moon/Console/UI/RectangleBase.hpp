// RectangleBase.hpp
//
// A base class for all UI elements, which will be inherited from

#pragma once

#include "../Rect.hpp"
#include "../Vector2.hpp"

#include "../../Misc/Misc.hpp"

#include "RectangleVirtualBase.hpp"

#include "RenderingStyle.hpp"

namespace Moon {
	namespace Console {
		class RectangleBase : public RectangleVirtualBase
		{
		public:
			RectangleBase(void) noexcept;
			explicit RectangleBase(const Rect& bounds) noexcept;

			// Style
			void ApplyRenderingStyle(const RenderingStyle& style) noexcept;
			void SetColor(const char* color) noexcept;
			void SetVisibility(const bool visibility) noexcept;
			void SetSymbol(const char symbol) noexcept;
			void SetFill(const bool fill) noexcept;

			// Bounds
			void SetBounds(const Rect& bounds) noexcept;
			[[nodiscard]] Rect GetBounds(void) const noexcept;
			[[nodiscard]] bool IsCursorWithin(void) const noexcept;

			virtual ~RectangleBase(void) noexcept = default;
		private:
			void Initialize(void) noexcept;
		protected:
			Rect m_Bounds;
			RenderingStyle* m_RenderingStyle = nullptr;
		};
	}
}
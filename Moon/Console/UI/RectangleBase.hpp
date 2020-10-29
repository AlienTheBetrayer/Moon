// RectangleBase.hpp
//
// A base class for all UI elements, which will be inherited from

#pragma once

#include "../Rect.hpp"
#include "../Vector2.hpp"

#include "../../Misc.hpp"

#include "RectangleVirtualBase.hpp"

#include "RenderingStyle.hpp"

namespace Moon {
	namespace Console {
		class RectangleBase : public RectangleVirtualBase
		{
		public:
			RectangleBase(void) noexcept;
			explicit RectangleBase(const Rect& bounds) noexcept;

			void ApplyRenderingStyle(const RenderingStyle& style) noexcept;
			void SetBounds(const Rect& bounds) noexcept;
			Rect GetBounds(void) noexcept;

			bool IsCursorWithin(void) noexcept;

			virtual ~RectangleBase(void) noexcept = default;
		private:
			void Initialize(void) noexcept;
		protected:
			Rect m_Bounds;
			RenderingStyle* m_RenderingStyle = nullptr;
		};
	}
}
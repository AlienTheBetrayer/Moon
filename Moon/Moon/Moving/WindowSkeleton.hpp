#pragma once

#include "../Console/Console.hpp"
#include "../Console/Rect.hpp"

namespace Moon {
	namespace Moving {
		class WindowSkeleton {
		public:
			WindowSkeleton(void) noexcept;
			~WindowSkeleton(void) noexcept = default;
			
			void SetBounds(const RectI& bounds) noexcept;
			void SetCurrentBounds(void) noexcept;
			[[nodiscard]] RectI& GetCurrentBounds(void) noexcept;
		private:
			RectI m_Bounds;
		};
	}
}
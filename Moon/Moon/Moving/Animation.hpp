#pragma once

#include <cstdint>
#include <memory>

#include "../Console/Console.hpp"
#include "AnimationStyle.hpp"
#include "WindowSkeleton.hpp"

namespace Moon {
	namespace Moving {
		class Animation
		{
		public:
			Animation(void) noexcept;
			~Animation(void) noexcept = default;

			void ApplyAnimationStyle(const AnimationStyle& animationStyle) noexcept;
			void Set(WindowSkeleton* skeleton1, WindowSkeleton* skeleton2) noexcept;

			void Play(void) const noexcept;
		private:
			std::pair<WindowSkeleton*, WindowSkeleton*> m_Skeletons;
			std::unique_ptr<AnimationStyle> m_AnimationStyle;
		};
	}
}
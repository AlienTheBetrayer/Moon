#include "Animation.hpp"

Moon::Moving::Animation::Animation(void) noexcept
{
	m_AnimationStyle = std::make_unique<AnimationStyle>();
}

void Moon::Moving::Animation::ApplyAnimationStyle(const AnimationStyle& animationStyle) noexcept
{
	*m_AnimationStyle = animationStyle;
}

void Moon::Moving::Animation::Set(WindowSkeleton* skeleton1, WindowSkeleton* skeleton2) noexcept
{
	m_Skeletons = std::make_pair(skeleton1, skeleton2);
}

void Moon::Moving::Animation::Play(void) const noexcept
{
	static const auto absdif = [](const int32_t x0, const int32_t x1) noexcept -> uint32_t {
		return static_cast<uint32_t>(std::abs(x0 - x1));
	};

	RectI& firstBounds = m_Skeletons.first->GetCurrentBounds();
	const RectI& secondBounds = m_Skeletons.second->GetCurrentBounds();

	const Vector2UI bounds_dif = Vector2UI{absdif(firstBounds.left, secondBounds.left), absdif(firstBounds.top, secondBounds.top)};

	switch (m_AnimationStyle->movingType) {
		case Moon::Moving::MovingType::Slide:
			std::thread([&]() -> void {
				for (std::size_t i = 0; i < bounds_dif.x; ++i) {
					if (firstBounds.left < secondBounds.left)
						++firstBounds.left, ++firstBounds.right;
					else
						--firstBounds.left, --firstBounds.right;

					Moon::Console::SetWindowBounds(firstBounds);
					Moon::Misc::Sleep(m_AnimationStyle->time / bounds_dif.x);
				}
				}).detach();

			std::thread([&]() -> void {
				for (std::size_t i = 0; i < bounds_dif.y; ++i) {
					if (firstBounds.top < secondBounds.top)
						++firstBounds.top, ++firstBounds.bottom;
					else
						--firstBounds.top, --firstBounds.bottom;

					Moon::Console::SetWindowBounds(firstBounds);
					Moon::Misc::Sleep(m_AnimationStyle->time / bounds_dif.y);
				}
				}).detach();
			break;	
		case Moon::Moving::MovingType::Quad:

			break;

	}

}
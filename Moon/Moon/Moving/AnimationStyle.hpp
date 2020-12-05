// AnimationStyle.hpp
//
// A style that can be applied to any animations

#pragma once

#include <cstdint>

namespace Moon {
	namespace Moving {
		enum class MovingType {
			Slide, // A type for moving the window to the specified position
			Quad, // A type for resizing the window to the specified size
			SlideQuad
		};

		struct AnimationStyle {
			MovingType movingType = MovingType::Slide;
			uint32_t time = 2500; // How much time the animation is going to take
		};
	}
}
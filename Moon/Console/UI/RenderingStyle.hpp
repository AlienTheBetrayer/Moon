// RenderingStyle.hpp
//
// A rendering style that can be applied to any UI elements

#pragma once

#include <string>

namespace Moon {
	namespace Console {
		struct RenderingStyle {
			char symbol = '#'; // The symbol that's going to be used to render the UI element
			std::string color = "light_gray"; // The foreground color of the render
			bool visible = true; // If this is false, then it won't render the UI element whatsoever
			bool fill = true; // If this is true, it will fill whole UI element, otherwise only outline
		};
	}
}
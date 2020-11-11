// RenderingStyle.hpp
//
// A rendering style that can be applied to any UI elements

#pragma once

#include <string>

namespace Moon {
	namespace Console {
		struct RenderingStyle {
			std::string color = "dark_gray"; // The foreground color of the render
			char symbol = '#'; // The symbol that's going to be used to render the UI element
			bool visible = true; // If this is false, then it won't render the UI element whatsoever
			bool fill = true; // If this is true, it will fill whole UI element, otherwise only outline

			// Pressable-only
			std::string hoverColor = "light_gray"; // The foreground color of the render which is applied when the mouse hovers on it
			std::string pressedColor = "white"; // The foreground clor of the render which is applied when the mouse presses on it
			std::string releasedColor = "dark_gray"; // The foreground color of the render which is applied when the mouse releases
		
			// Text
			enum class TextAlignment { // All Text Alignment options for elements such as TextLabel or TextBox
				TopLeft, TopCenter, TopRight,
				CenterLeft, Center, CenterRight,
				BottomLeft, BottomCenter, BottomRight
			};

			TextAlignment textAlignment = TextAlignment::Center;
			std::string textColor = "white";
			bool fitInOutline = true; // Whether the text is gonna fit inside the outline(fill == false)
		};
	}
}
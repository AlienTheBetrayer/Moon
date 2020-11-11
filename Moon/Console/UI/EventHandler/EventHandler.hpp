// EventHandler.hpp
//
// A class that handles events

#pragma once

#include <vector>
#include <unordered_map>
#include <functional>
#include <thread>

#include "PressedKeys.hpp"

#include "../RectangleVirtualBase.hpp"
#include "../Button/Button.hpp"

#include <iostream>

namespace Moon {
	namespace Event {
		enum class EventType {
			IsMouseOver,
			IsMouseNotOver,
			KeyPressedWithin
		};

		enum class ButtonEventType {
			IsLMBPressed,
			IsLMBReleased,
			OnLMBDown,
			OnLMBRelease,
			IsRMBPressed,
			IsRMBReleased,
			OnRMBDown,
			OnRMBRelease
		};

		enum class WindowEventType {
			IsMouseOver,
			IsMouseNotOver
		};
				
		struct EventArgs {
			const char* status = "bad";// -1 means bad, 0 means ok
			PressedKeys keysPressed;
			Vector2 mousePosition;
		};

		class EventHandler
		{
			using func_t = std::function<void(EventArgs)>;
		public:
			EventHandler(void) = default;
			
			void Hook(Moon::Console::RectangleVirtualBase* element, const EventType evType, const func_t& function) noexcept;
			void HookWindow(const WindowEventType evType, const func_t& function) noexcept;
			void HookButton(Moon::Console::Button* button, const ButtonEventType evType, const func_t& function) noexcept;

			void Animate(Moon::Console::Button& button) noexcept;

			void Unhook(Moon::Console::RectangleVirtualBase* element) noexcept;
			void Unhook(Moon::Console::RectangleVirtualBase* element, const EventType evType) noexcept;
			// make unhook
			
			[[nodiscard]] static EventArgs CheckElementEvent(Moon::Console::RectangleVirtualBase* element, const EventType evType) noexcept;
			[[nodiscard]] static EventArgs CheckWindowEvent(const WindowEventType evType) noexcept;
			[[nodiscard]] static EventArgs CheckButtonEvent(Moon::Console::Button* button, const ButtonEventType evType) noexcept;

			void Run(void) const noexcept;
			void SetDelay(const uint32_t ms) noexcept;

			~EventHandler(void) = default;
		private:
			void RunLoop(void) const noexcept;
		private:
			// All events
			// All elements
			std::unordered_map<Moon::Console::RectangleVirtualBase*, std::unordered_map<EventType, func_t>> m_ElementsEvents;
			
			// Windows
			std::unordered_map<WindowEventType, func_t> m_WindowEvents;

			// Buttons
			std::unordered_map<Moon::Console::Button*, std::unordered_map<ButtonEventType, func_t>> m_ButtonEvents;

			uint32_t m_Delay = 0;
		};
	}
}

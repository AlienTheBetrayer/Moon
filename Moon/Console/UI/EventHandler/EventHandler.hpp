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


namespace Moon {
	namespace Event {
		enum class EventType {
			IsMouseOver,
			IsMouseNotOver,
			KeyPressedWithin
		};

		enum class ButtonEventType {
			IsPressed
		};

		enum class WindowEventType {
			IsMouseOver,
			IsMouseNotOver
		};
				
		struct EventArgs {
			int32_t status = 0; // -1 means bad, 0 means ok
			PressedKeys keysPressed;
		};


		class EventHandler
		{
			using func_t = std::function<void(EventArgs)>;
		public:
			EventHandler(void) = default;
			
			void Hook(Moon::Console::RectangleVirtualBase* element, const EventType evType, const func_t& function) noexcept;
			void HookWindow(const WindowEventType evType, const func_t& function) noexcept;
			void HookButton(Moon::Console::Button* button, const ButtonEventType evType, const func_t& function) noexcept;

			void Unhook(Moon::Console::RectangleVirtualBase* element) noexcept;
			void Unhook(Moon::Console::RectangleVirtualBase* element, const EventType evType) noexcept;
			//m ake unhook
			
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
			std::unordered_map<Moon::Console::RectangleVirtualBase*, std::unordered_map<EventType, func_t>> m_ElementsEvents;
			std::unordered_map<Moon::Console::Button*, std::unordered_map<ButtonEventType, func_t>> m_ButtonEvents;
			std::unordered_map<WindowEventType, func_t> m_WindowEvents;
				
			uint32_t m_Delay = 0;
		};
	}
}

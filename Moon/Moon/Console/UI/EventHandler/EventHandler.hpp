// EventHandler.hpp
//
// A class that handles events

#pragma once

#include <vector>
#include <unordered_map>
#include <functional>
#include <thread>
#include <string>

#include "PressedKeys.hpp"

#include "../RectangleVirtualBase.hpp"
#include "../Button/Button.hpp"
#include "../CheckBox/CheckBox.hpp"
#include "../TextBox/TextBox.hpp"

namespace Moon {
	namespace Event {
		// All event types
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

		enum class CheckBoxEventType {
			Toggled
		};

		enum class TextBoxEventType {
			TextInputEnded,
			OnPress
		};
				
		struct EventArgs {
			const char* status = "bad";
			PressedKeys keysPressed;
			Vector2I mousePosition;
			std::string textboxText;		
		};

		class EventHandler
		{
		public:
			using func_t = std::function<void(EventArgs)>;
				
			EventHandler(void) = default;
			
			void Hook(Moon::Console::RectangleVirtualBase* element, const EventType evType, const func_t& function) noexcept;
			void HookWindow(const WindowEventType evType, const func_t& function) noexcept;
			void HookButton(Moon::Console::Button* button, const ButtonEventType evType, const func_t& function) noexcept;
			void HookCheckBox(Moon::Console::CheckBox* checkBox, const CheckBoxEventType evType, const func_t& function) noexcept;
			void HookTextBox(Moon::Console::TextBox* textBox, const TextBoxEventType evType, const func_t& function) noexcept;

			void Unhook(Moon::Console::RectangleVirtualBase* element) noexcept;
			void Unhook(Moon::Console::RectangleVirtualBase* element, const EventType evType) noexcept;
			// make unhook for everything
			
			[[nodiscard]] static EventArgs CheckElementEvent(Moon::Console::RectangleVirtualBase* element, const EventType evType) noexcept;
			[[nodiscard]] static EventArgs CheckWindowEvent(const WindowEventType evType) noexcept;
			[[nodiscard]] static EventArgs CheckButtonEvent(Moon::Console::Button* button, const ButtonEventType evType) noexcept;
			[[nodiscard]] static EventArgs CheckCheckBoxEvent(Moon::Console::CheckBox* checkBox, const CheckBoxEventType evType) noexcept;
			[[nodiscard]] static EventArgs CheckTextBoxEvent(Moon::Console::TextBox* textBox, const TextBoxEventType evType, bool& debounceVar) noexcept;

			void Run(void) const noexcept;
			void SetDelay(const uint32_t ms) noexcept;

			~EventHandler(void) = default;
		private:
			void RunLoop(void) const noexcept;
		private:
			std::unordered_map<Moon::Console::RectangleVirtualBase*, std::unordered_map<EventType, func_t>> m_ElementsEvents;
			std::unordered_map<WindowEventType, func_t> m_WindowEvents;
			std::unordered_map<Moon::Console::Button*, std::unordered_map<ButtonEventType, func_t>> m_ButtonEvents;
			std::unordered_map<Moon::Console::CheckBox*, std::unordered_map<CheckBoxEventType, func_t>> m_CheckBoxEvents;
			std::unordered_map<Moon::Console::TextBox*, std::unordered_map<TextBoxEventType, func_t>> m_TextBoxEvents;

			uint32_t m_Delay = 0;
		};
	}
}

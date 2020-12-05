// EventHandler.cpp

#include "EventHandler.hpp"

void Moon::Event::EventHandler::Hook(Moon::Console::RectangleVirtualBase* element, const EventType evType, const func_t& function) noexcept
{
	RunLoop();

	m_ElementsEvents[element][evType] = function;
}

void Moon::Event::EventHandler::HookWindow(const WindowEventType evType, const func_t& function) noexcept
{
	RunLoop();
	
	m_WindowEvents[evType] = function;
}

void Moon::Event::EventHandler::HookButton(Moon::Console::Button* button, const ButtonEventType evType, const func_t& function) noexcept
{
	RunLoop();

	m_ButtonEvents[button][evType] = function;
}

void Moon::Event::EventHandler::HookCheckBox(Moon::Console::CheckBox* checkBox, const CheckBoxEventType evType, const func_t& function) noexcept
{
	RunLoop();

	m_CheckBoxEvents[checkBox][evType] = function;
}

void Moon::Event::EventHandler::HookTextBox(Moon::Console::TextBox* textBox, const TextBoxEventType evType, const func_t& function) noexcept
{
	RunLoop();

	m_TextBoxEvents[textBox][evType] = function;
}

void Moon::Event::EventHandler::Unhook(Moon::Console::RectangleVirtualBase* element) noexcept
{
	m_ElementsEvents.erase(element);
}

void Moon::Event::EventHandler::Unhook(Moon::Console::RectangleVirtualBase* element, const EventType evType) noexcept
{
	m_ElementsEvents[element].erase(evType);
}

Moon::Event::EventArgs Moon::Event::EventHandler::CheckElementEvent(Moon::Console::RectangleVirtualBase* element, const Moon::Event::EventType evType) noexcept
{
	EventArgs args;

	switch (evType) {
	case EventType::IsMouseOver:
		if (element->IsCursorWithin()) {
			args.status = "ok";
			args.mousePosition = Moon::Misc::SnapToConsole(Moon::Misc::GetCursorPosition());
		}

		break;
	case EventType::IsMouseNotOver:
		if (!element->IsCursorWithin()) {
			args.status = "ok";
			args.mousePosition = Moon::Misc::SnapToConsole(Moon::Misc::GetCursorPosition());
		}
		
		break;
	case EventType::KeyPressedWithin:
		if (element->IsCursorWithin()) {
			args.status = "ok";
			args.keysPressed = Moon::Misc::GetPressedKeys();
		}

		break;
	}

	return args;
}

Moon::Event::EventArgs Moon::Event::EventHandler::CheckWindowEvent(const WindowEventType evType) noexcept
{
	EventArgs args;
	args.status = 0;

	static const auto isMouseOver = [&args]() {
		RECT cRect;
		GetWindowRect(GetConsoleWindow(), &cRect);

		return (Moon::Misc::IsWithinRect(Moon::Misc::GetCursorPosition(), { cRect.left, cRect.right, cRect.top, cRect.bottom }));
	};

	switch (evType) {
	case WindowEventType::IsMouseOver:
		if (isMouseOver()) {
			args.status = "ok";
			args.mousePosition = Moon::Misc::GetCursorPosition();
		}

		break;
	case WindowEventType::IsMouseNotOver:
		if (!isMouseOver()) {
			args.status = "ok";
			args.mousePosition = Moon::Misc::GetCursorPosition();
		}

		break;
	}

	return args;
}

Moon::Event::EventArgs Moon::Event::EventHandler::CheckButtonEvent(Moon::Console::Button* button, const ButtonEventType evType) noexcept
{
	static bool LMBDownDebounce = true;
	static bool LMBReleaseDebounce = false;	
	static bool RMBDownDebounce = true;
	static bool RMBReleaseDebounce = false;

	EventArgs args;

	if (button->IsCursorWithin() && Moon::Misc::IsKeyPressed(VK_LBUTTON)) {
		LMBReleaseDebounce = true;
	}

	if (!Moon::Misc::IsKeyPressed(VK_LBUTTON)) {
		LMBDownDebounce = true;
	}


	if (button->IsCursorWithin() && Moon::Misc::IsKeyPressed(VK_RBUTTON)) {
		RMBReleaseDebounce = true;
	}

	if (!Moon::Misc::IsKeyPressed(VK_RBUTTON)) {
		RMBDownDebounce = true;
	}

	switch (evType) {
	case ButtonEventType::IsLMBPressed:
		if (!(button->IsCursorWithin() && Moon::Misc::IsKeyPressed(VK_LBUTTON))) {
			args.status = "ok";
		}

		break;
	case ButtonEventType::IsLMBReleased:
		if (!(button->IsCursorWithin() && !Moon::Misc::IsKeyPressed(VK_LBUTTON))) {
			args.status = "ok";
		}

		break;
	case ButtonEventType::OnLMBDown:
		if (button->IsCursorWithin() && Moon::Misc::IsKeyPressed(VK_LBUTTON) && LMBDownDebounce) {
			args.status = "ok";
			LMBDownDebounce = false;
		}

		break;
	case ButtonEventType::OnLMBRelease:
		if (button->IsCursorWithin() && !Moon::Misc::IsKeyPressed(VK_LBUTTON) && LMBReleaseDebounce) {
			args.status = "ok";
			LMBReleaseDebounce = false;
		}

		break;

	case ButtonEventType::IsRMBPressed:
		if (!(button->IsCursorWithin() && Moon::Misc::IsKeyPressed(VK_LBUTTON))) {
			args.status = "ok";
		}

		break;
	case ButtonEventType::IsRMBReleased:
		if (!(button->IsCursorWithin() && !Moon::Misc::IsKeyPressed(VK_RBUTTON))) {
			args.status = "ok";
		}

		break;
	case ButtonEventType::OnRMBDown:
		if (button->IsCursorWithin() && Moon::Misc::IsKeyPressed(VK_RBUTTON) && RMBDownDebounce) {
			args.status = "ok";
			RMBDownDebounce = false;
		}

		break;
	case ButtonEventType::OnRMBRelease:
		if (button->IsCursorWithin() && !Moon::Misc::IsKeyPressed(VK_RBUTTON) && RMBReleaseDebounce) {
			args.status = "ok";
			RMBReleaseDebounce = false;
		}

		break;
	}

	return args;
}

Moon::Event::EventArgs Moon::Event::EventHandler::CheckCheckBoxEvent(Moon::Console::CheckBox* checkBox, const CheckBoxEventType evType) noexcept
{
	static bool LMBDownDebounce = true;
	static bool LMBReleaseDebounce = false;

	EventArgs args;

	if (checkBox->IsCursorWithin() && Moon::Misc::IsKeyPressed(VK_LBUTTON)) {
		LMBReleaseDebounce = true;
	}

	if (!Moon::Misc::IsKeyPressed(VK_LBUTTON)) {
		LMBDownDebounce = true;
	}

	switch (evType) {
	case CheckBoxEventType::Toggled:
			if (checkBox->IsCursorWithin() && Moon::Misc::IsKeyPressed(VK_LBUTTON) && LMBDownDebounce) {
				args.status = "ok";
				checkBox->m_Toggled = !checkBox->m_Toggled;
				LMBDownDebounce = false;
			}
		break;
	}

	return args;
}

Moon::Event::EventArgs Moon::Event::EventHandler::CheckTextBoxEvent(Moon::Console::TextBox* textBox, const TextBoxEventType evType, bool& debounceVar) noexcept
{
	static bool LMBDownDebounce = true;
	static bool LMBReleaseDebounce = false;
	EventArgs args;

	if (textBox->IsCursorWithin() && Moon::Misc::IsKeyPressed(VK_LBUTTON)) {
		LMBReleaseDebounce = true;
	}

	if (!Moon::Misc::IsKeyPressed(VK_LBUTTON)) {
		LMBDownDebounce = true;
	}

	switch (evType) {
	case TextBoxEventType::OnPress:
		if (textBox->IsCursorWithin() && Moon::Misc::IsKeyPressed(VK_LBUTTON) && LMBDownDebounce) {
			if (!debounceVar)
				break;

			args.status = "ok";
			textBox->m_Text = "";
			textBox->ClearText();

			RectI bounds = textBox->GetBounds();
			bounds.left /= 8;
			bounds.right /= 8;
			bounds.top /= 16;
			bounds.bottom /= 16;

			Moon::Console::GotoAxis({ bounds.left + 2, bounds.top + (bounds.bottom - bounds.top) / 2 });

			debounceVar = false;

			const int32_t size = bounds.right - bounds.left - 2;
			std::unique_ptr<char> input = std::make_unique<char>(size);

			std::string fmt = "%" + std::to_string(size - 1) + "s";
			scanf_s(fmt.c_str(), input.get()); // TODO: reads until the space. Make it read until the end of the string

			std::string str(input.get());
			args.textboxText = input.get();
			textBox->m_Text = input.get();
			debounceVar = true;
		}

		break;
	}

	return args;
}

void Moon::Event::EventHandler::Run(void) const noexcept
{
	bool debounce = true;

	for (;;) {
		Moon::Misc::IterateMap<Moon::Console::RectangleVirtualBase*, std::unordered_map<EventType, func_t>>(m_ElementsEvents, [](const auto& element, const auto& map) noexcept -> void {
			Moon::Misc::IterateMap<EventType, func_t>(map, [&](const auto& evType, const auto& function) noexcept -> void {
				const EventArgs args = CheckElementEvent(element, evType);
				if (args.status == "ok")
					function(args);
				});
			});

		Moon::Misc::IterateMap<Moon::Console::Button*, std::unordered_map<ButtonEventType, func_t>>(m_ButtonEvents, [](const auto& element, const auto& map) noexcept -> void {
			Moon::Misc::IterateMap<ButtonEventType, func_t>(map, [&](const auto& evType, const auto& function) noexcept -> void {
				const EventArgs args = CheckButtonEvent(element, evType);
				if (args.status == "ok")
					function(args);
				});
			});

		Moon::Misc::IterateMap<WindowEventType, func_t>(m_WindowEvents, [](const auto& evType, const auto& function) noexcept -> void {
			const EventArgs args = CheckWindowEvent(evType);
			if (args.status == "ok")
				function(args);
			});

		Moon::Misc::IterateMap<Moon::Console::CheckBox*, std::unordered_map<CheckBoxEventType, func_t>>(m_CheckBoxEvents, [](const auto& element, const auto& map) noexcept -> void {
			Moon::Misc::IterateMap<CheckBoxEventType, func_t>(map, [&](const auto& evType, const auto& function) noexcept -> void {
				const EventArgs args = CheckCheckBoxEvent(element, evType);
				if (args.status == "ok")
					function(args);
				});
			});


			if (debounce) {
				Moon::Misc::IterateMap<Moon::Console::TextBox*, std::unordered_map<TextBoxEventType, func_t>>(m_TextBoxEvents, [&debounce](const auto& element, const auto& map) noexcept -> void {
					Moon::Misc::IterateMap<TextBoxEventType, func_t>(map, [&](const auto& evType, const auto& function) noexcept -> void {
						const EventArgs args = CheckTextBoxEvent(element, evType, debounce);
						if (args.status == "ok")
							function(args);
						});
					});
			}

		if (m_Delay)
			Moon::Misc::Sleep(m_Delay);
	}
}

void Moon::Event::EventHandler::SetDelay(const uint32_t ms) noexcept
{
	m_Delay = ms;
}

void Moon::Event::EventHandler::RunLoop(void) const noexcept
{
	static bool first = true;

	if (first) {
		first = false;

		std::thread([&]() {
			Run();
			}).detach();
	}
}

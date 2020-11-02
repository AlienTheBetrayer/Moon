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
	args.status = 0;

	switch (evType) {
	case EventType::IsMouseOver:
		if (!element->IsCursorWithin()) {
			args.status = -1;
			break;
		}

		break;
	case EventType::IsMouseNotOver:
		if (element->IsCursorWithin()) {
			args.status = -1;
			break;
		}
		
		break;
	case EventType::KeyPressedWithin:
		if (!element->IsCursorWithin()) {
			args.status = -1;
			break;
		}

		const auto pressedKeys = Moon::Misc::GetPressedKeys();
		args.keysPressed = pressedKeys;

		break;
	}

	return args;
}

Moon::Event::EventArgs Moon::Event::EventHandler::CheckWindowEvent(const WindowEventType evType) noexcept
{
	EventArgs args;
	args.status = 0;

	switch (evType) {
	case WindowEventType::IsMouseOver:
		RECT cRect;
		GetWindowRect(GetConsoleWindow(), &cRect);

		if (!Moon::Misc::IsWithinRect(Moon::Misc::GetCursorPosition(), { cRect.left, cRect.right, cRect.top, cRect.bottom })) {
			args.status = -1;
			break;
		}

		break;
	case WindowEventType::IsMouseNotOver:
		RECT cRect1;
		GetWindowRect(GetConsoleWindow(), &cRect1);

		if (Moon::Misc::IsWithinRect(Moon::Misc::GetCursorPosition(), { cRect1.left, cRect1.right, cRect1.top, cRect1.bottom })) {
			args.status = -1;
			break;
		}

		break;
	}

	return args;
}

Moon::Event::EventArgs Moon::Event::EventHandler::CheckButtonEvent(Moon::Console::Button* button, const ButtonEventType evType) noexcept
{
	EventArgs args;
	args.status = 0;

	switch (evType) {
	case ButtonEventType::IsPressed:
		if (!(button->IsCursorWithin() && Moon::Misc::IsKeyPressed(VK_LBUTTON))) {
			args.status = -1;
			break;
		}

		break;
	}

	return args;
}

void Moon::Event::EventHandler::Run(void) const noexcept
{	
	for (;;) {
		Moon::Misc::IterateMap<Moon::Console::RectangleVirtualBase*, std::unordered_map<EventType, func_t>>(m_ElementsEvents, [](const auto& element, const auto& map) noexcept -> void {
			Moon::Misc::IterateMap<EventType, func_t>(map, [&](const auto& evType, const auto& function) noexcept -> void {
				const EventArgs args = CheckElementEvent(element, evType);
				if (args.status != -1)
					function(args);
			});
		});

		Moon::Misc::IterateMap<Moon::Console::Button*, std::unordered_map<ButtonEventType, func_t>>(m_ButtonEvents, [](const auto& element, const auto& map) noexcept -> void {
			Moon::Misc::IterateMap<ButtonEventType, func_t>(map, [&](const auto& evType, const auto& function) noexcept -> void {
				const EventArgs args = CheckButtonEvent(element, evType);
				if (args.status != -1)
					function(args);
				});
			});

		Moon::Misc::IterateMap<WindowEventType, func_t>(m_WindowEvents, [](const auto& evType, const auto& function) noexcept -> void {
			const EventArgs args = CheckWindowEvent(evType);
			if (args.status != -1)
				function(args);
		});

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

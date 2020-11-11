
# Moon ![enter image description here](https://img.shields.io/github/license/AlienTheBetrayer/Moon?color=blue)
![Icon](https://raw.githubusercontent.com/AlienTheBetrayer/Moon/main/moonicon.png)

 - [Getting started](#getting-started)
- [Example](#example)	
- [Main idea](#main-idea)
- [Roadmap](#roadmap)

**Moon** is a console engine, that apart from the regular user interface elements and console functions, has a plethora of other stuff that does not directly relate to console.
## Getting started
**Moon** is untested on other development environments so it is recommended to use **Visual Studio 2017** or higher.

Start by cloning this repository or just downloading it, then put **Moon.hpp** header file in the same location where you put **Moon** folder, then just include the header file and you are ready to go.
## Example
```cpp
// If you press the red button, a sound will play within 3 seconds.

Moon::Console::Button button;
button.SetBounds({ 5, 20, 5, 8 });
button.SetColor("light_red");
button.SetFill(false);

Moon::Event::EventHandler evHandler;
evHandler.HookButton(&button, Moon::Event::ButtonEventType::OnLMBDown, [](const auto& args) {
	Moon::Time::SetTimeoutSync([]() {
		Moon::Sound::Play("sound.mp3");
	}, Moon::Misc::RandomRange(1000, 3000));
});

button.Render();
```
## Main idea
The idea of this engine is to provide a really easy way to manipulate console and an ability to work like with the usual UI framework but in the console, and just make the experience coding in console much more convenient.
## Roadmap
- Add more UI elements
- Make all the components feel complete
- Optimizations
- Add more data structs such as Vector2 and their operator overloads
- Better event system
- Animations

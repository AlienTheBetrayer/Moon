// Moon.hpp
//
// A file which is intended to be included only by a user
// Includes all Moon Engine's components

#pragma once

#ifdef _WIN32 
// Moon components
#include "Moon/Debug/Debug.hpp"
#include "Moon/Console/Console.hpp"
#include "Moon/Misc/Misc.hpp"
#include "Moon/Time/Time.hpp"
#include "Moon/Console/UI/EventHandler/EventHandler.hpp"
#include "Moon/Sound/Sound.hpp"

// Other classes
#include "Moon/Console/UI/Renderer/Renderer.hpp"
#include "Moon/Console/UI/RenderingStyle.hpp"
#include "Moon/Console/UI/EventHandler/PressedKeys.hpp"
#include "Moon/Console/Rect.hpp"
#include "Moon/Console/Vector2.hpp"

// Moon UI components
#include "Moon/Console/UI/Rectangle/Rectangle.hpp"
#include "Moon/Console/UI/Button/Button.hpp"
#include "Moon/Console/UI/TextLabel/TextLabel.hpp"

#else
#error This library is only compatible with Windows
#endif
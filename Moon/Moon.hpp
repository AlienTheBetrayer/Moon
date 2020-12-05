// Moon.hpp
//
// A file which is intended to be included only by a user
// Includes all Moon Engine's components

#pragma once

#ifdef _WIN32 

#include "IncludeSettings.hpp"

#ifndef MOON_DISABLE_ALL
// Moon components
#ifndef MOON_DISABLE_DEBUG
#include "Moon/Debug/Debug.hpp"
#endif

#ifndef MOON_DISABLE_CONSOLE
#include "Moon/Console/Console.hpp"
#ifndef MOON_DISABLE_MISC
#include "Moon/Console/UI/EventHandler/EventHandler.hpp"
#endif
#endif

#ifndef MOON_DISABLE_MISC
#include "Moon/Misc/Misc.hpp"
#endif

#ifndef MOON_DISABLE_TIME
#ifndef MOON_DISABLE_MISC
#include "Moon/Time/Time.hpp"
#endif
#include "Moon/Time/Clock.hpp"
#endif

#ifndef MOON_DISABLE_SOUND
#include "Moon/Sound/Sound.hpp"
#endif

#ifndef MOON_DISABLE_MOVING
#include "Moon/Moving/Moving.hpp"
#include "Moon/Moving/Animation.hpp"
#include "Moon/Moving/WindowSkeleton.hpp"
#endif

// Other classes
#if !defined(MOON_DISABLE_CONSOLE) && !defined(MOON_DISABLE_MISC)
#include "Moon/Console/UI/Renderer/Renderer.hpp"
#include "Moon/Console/UI/RenderingStyle.hpp"
#include "Moon/Console/UI/EventHandler/PressedKeys.hpp"
#endif
#include "Moon/Console/Rect.hpp"
#include "Moon/Console/Vector2.hpp"

// Moon UI components
#if !defined(MOON_DISABLE_CONSOLE) && !defined(MOON_DISABLE_MISC)
#include "Moon/Console/UI/Rectangle/Rectangle.hpp"
#include "Moon/Console/UI/Button/Button.hpp"
#include "Moon/Console/UI/TextLabel/TextLabel.hpp"
#include "Moon/Console/UI/CheckBox/CheckBox.hpp"
#include "Moon/Console/UI/TextBox/TextBox.hpp"
#endif
#endif

#else
#error This library is only compatible with Windows
#endif
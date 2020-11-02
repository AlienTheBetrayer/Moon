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

// Other classes
#include "Moon/Console/UI/Renderer/Renderer.hpp"
#include "Moon/Console/UI/EventHandler/EventHandler.hpp"

// Moon UI components
#include "Moon/Console/UI/Rectangle/Rectangle.hpp"
#else
#error This library is only compatible with Windows
#endif
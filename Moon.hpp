// Moon.hpp
//
// A file which is intended to be included only by a user
// Includes all Moon Engine's components

#pragma once

#ifdef _WIN32 
// All Moon includes
// C libraries
#include <cstdint>

// Moon components
#include "Moon/Debug/Debug.hpp"
#include "Moon/Console/Console.hpp"
#include "Moon/Misc.hpp"

// Moon UI components
#include "Moon/Console/UI/Button/Button.hpp"
#include "Moon/Console/UI/Rectangle/Rectangle.hpp"
#else
#error This library is only compatible with Windows
#endif
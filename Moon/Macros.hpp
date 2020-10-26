// Macros.hpp
//
// All Moon Engine's macros

#pragma once

// Version of C++ is 17+
#if (defined(_WIN32) && (defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
#define CPP17GRT
#endif
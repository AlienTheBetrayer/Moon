// Macros.hpp
//
// All Moon Engine's macros

#pragma once

// Version of C++ is 17+
//#if (defined(_WIN32) && (defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
//#define CPP17GRT
//#endif

#ifdef _MSC_VER
#pragma warning(disable : 4067)
#endif

#ifdef _WIN32
#if defined(_MSVC_LANG) && _MSVC_LANG > 201703L || __cplusplus >= 201703L
#define CPP20GRT
#endif

#if defined(_MSVC_LANG) && _MSVC_LANG >= 201703L || __cplusplus >= 201703L
#define CPP17GRT
#endif
#endif
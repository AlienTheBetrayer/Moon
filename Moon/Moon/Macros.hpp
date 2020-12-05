// Macros.hpp
//
// All Moon Engine's macros

#pragma once

#ifdef _WIN32
#if defined(_MSVC_LANG) && _MSVC_LANG > 201703L || __cplusplus >= 201703L
#define CPP20GRT
#endif	

#if defined(_MSVC_LANG) && _MSVC_LANG >= 201703L || __cplusplus >= 201703L
#define CPP17GRT
#endif
#endif
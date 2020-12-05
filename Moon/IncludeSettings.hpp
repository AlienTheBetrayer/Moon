// IncludeSettings.hpp
//
// Modify this file in order to include different parts of the Moon Engine
// or to disable some parts
//
// Keep in mind that if you disable specific component, other components may lose some functionality

#pragma once

/* -- ========== -- Settings start here -- ========== -- */
                                                         
// Disable only one single component                     
                                                         
// #define MOON_DISABLE_ALL // Disable every component and every part. Library simply does not include at all
// #define MOON_DISABLE_CONSOLE // Disable Console component
// #define MOON_DISABLE_DEBUG // Disable Debug component 
// #define MOON_DISABLE_MISC // Disable Miscellaneous component
// #define MOON_DISABLE_SOUND // Disable Sound component 
// #define MOON_DISABLE_TIME // Disable Time component
// #define MOON_DISABLE_MOVING // Disable Moving component
                                                         
                                                         
                                                         
// Enable specific components, and disable everything else
                                                         
// #define MOON_ENABLE_CONSOLE // Enable Console component
// #define MOON_ENABLE_DEBUG // Enable Debug component   
// #define MOON_ENABLE_MISC // Enable Miscellaneous component
// #define MOON_ENABLE_SOUND // Enable Sound component   
// #define MOON_ENABLE_TIME // Enable Time component 
// #define MOON_ENABLE_MOVING // Enable Moving component
                                                         
/* -- ========== -- Settings end here -- ========== --   
                                                         
   Stuff you dont care about -                           
                             |                           
                            \/                           */

#ifdef MOON_ENABLE_CONSOLE
#define MOON_DISABLE_DEBUG
#define MOON_DISABLE_MISC
#define MOON_DISABLE_SOUND
#define MOON_DISABLE_TIME 
#define MOON_DISABLE_MOVING
#endif

#ifdef MOON_ENABLE_DEBUG
#define MOON_DISABLE_CONSOLE
#define MOON_DISABLE_MISC
#define MOON_DISABLE_SOUND
#define MOON_DISABLE_TIME 
#define MOON_DISABLE_MOVING
#endif

#ifdef MOON_ENABLE_MISC
#define MOON_DISABLE_CONSOLE
#define MOON_DISABLE_DEBUG
#define MOON_DISABLE_SOUND
#define MOON_DISABLE_TIME 
#define MOON_DISABLE_MOVING
#endif

#ifdef MOON_ENABLE_SOUND
#define MOON_DISABLE_CONSOLE
#define MOON_DISABLE_DEBUG
#define MOON_DISABLE_MISC
#define MOON_DISABLE_TIME 
#define MOON_DISABLE_MOVING
#endif

#ifdef MOON_ENABLE_TIME
#define MOON_DISABLE_CONSOLE
#define MOON_DISABLE_DEBUG
#define MOON_DISABLE_MISC
#define MOON_DISABLE_SOUND
#define MOON_DISABLE_MOVING
#endif

#ifdef MOON_DISABLE_MOVING
#define MOON_DISABLE_CONSOLE
#define MOON_DISABLE_DEBUG
#define MOON_DISABLE_MISC
#define MOON_DISABLE_SOUND
#define MOON_DISABLE_TIME 
#endif
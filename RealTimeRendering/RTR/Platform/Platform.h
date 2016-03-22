//=====================================================================================
// Platform.h
// Very Rudimentary platform independence layer. Currently incomplete
//=====================================================================================
#pragma once

#define RTR_PLATFORM_WINDOWS 0
#define RTR_PLATFORM_LINUX 1
#define RTR_PLATFORM_OSX 2
#define RTR_PLATFORM_ANDROID 3
#define RTR_PLATFORM_IOS 4
#define RTR_PLATFORM_STEAMOS 5

#define RTR_RENDERER_DIRECTX 0
#define RTR_RENDERER_OPENGL 1

#ifdef _WIN32
#define RTR_PLATFORM RTR_PLATFORM_WINDOWS
#define RTR_RENDERER RTR_RENDERER_DIRECTX
#endif

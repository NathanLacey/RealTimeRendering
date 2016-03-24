//=====================================================================================
// Platform.h
// Very Rudimentary platform independence layer. Currently incomplete
//=====================================================================================
#pragma once

//Platforms
#define RTR_PLATFORM_WINDOWS 1
#define RTR_PLATFORM_LINUX 2
#define RTR_PLATFORM_OSX 3
#define RTR_PLATFORM_ANDROID 4
#define RTR_PLATFORM_IOS 5
#define RTR_PLATFORM_STEAMOS 6
//Compilers
#define RTR_COMPILER_MSVC 1
#define RTR_COMPILER_INTEL 2
#define RTR_COMPILER_GCC 3
#define RTR_COMPILER_CLANG 4
//Processor
#define RTR_CPU_X86 1
#define RTR_CPU_X86_64 2
#define RTR_CPU_ARM 3
#define RTR_CPU_ARM_64 4

//=====================================================================================
// Check the platform being used
//=====================================================================================
#if defined(_WIN32) || defined(_WIN64)
#define RTR_PLATFORM RTR_PLATFORM_WINDOWS
#elif defined(__APPLE__)
#include <TargetConditionals.h>
#if TARGET_OS_IPHONE
#define RTR_PLATFORM RTR_PLATFORM_IOS
#elif TARGET_OS_MAC
#define RTR_PLATFORM RTR_PLATFORM_OSX
#endif
#elif defined(__linux__)
#define RTR_PLATFORM RTR_PLATFORM_LINUX
#elif defined(__ANDROID__)
#define RTR_PLATFORM RTR_PLATFORM_ANDROID
#endif

//=====================================================================================
// Check the compiler being used
//=====================================================================================
#if defined(_MSC_VER)
#define RTR_COMPILER RTR_COMPILER_MSVC
#elif defined(__ICC) || defined(__INTEL_COMPILER)
#define RTR_COMPILER RTR_COMPILER_INTEL
#elif defined(__GNUC__) || defined(__GNUG__)
#define RTR_COMPILER RTR_COMPILER_GCC
#elif defined(__clang__)
#define RTR_COMPILER RTR_COMPILER_CLANG
#endif

//=====================================================================================
// Check what processor being used
//=====================================================================================
#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) ||      \
    defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64)
#define RTR_CPU RTR_CPU_X86_64
#elif defined(i386) || defined(__i386) || defined(__i386__) ||            \
    defined(__i386__) || defined(__i486__) || defined(__i586__) ||        \
    defined(__i686__) || defined(__IA32__) || defined(_M_IX86) ||         \
    defined(__X86__) || defined(_X86_)
#define RTR_CPU RTR_CPU_X86
#elif defined(_arm__) || defined(__TARGET_ARCH_ARM) || defined(_ARM) ||   \
    defined(_M_ARM) || defined(_M_ARMT) || defined(__arm)
#define RTR_CPU RTR_CPU_ARM
#elif defined(__aarch64__)
#define RTR_CPU RTR_CPU_ARM_64
#endif
#pragma once

#ifdef HZ_PLATFORM_WINDOWS
	#ifdef HAZEL_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else
	#define HAZEL_API __declspec(dllimport)
	#endif
#else
	#error Hazel only supports Windows!
#endif

#ifdef HAZEL_DEBUG
	#define HAZEL_ENABLE_ASSERTS
#endif

#ifdef HAZEL_ENABLE_ASSERTS
	#define HAZEL_ASSERT(x, ...) { if(!(x)) { HAZEL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define HAZEL_CORE_ASSERT(x, ...) { if(1(x)) { HAZEL_CORE_ERROR("Assertion Failed {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define HAZEL_ASSERT(x, ...)
	#define HAZEL_CORE_ASSERT(x, ...)

#endif

#define BIT(x) (1 << x)

#define HAZEL_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)


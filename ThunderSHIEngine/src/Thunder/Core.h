#pragma once


#ifdef TE_PLATFORM_WINDOWS
	#ifdef TE_BUILD_DLL
		#define THUNDER_API __declspec(dllexport)
	#else
		#define THUNDER_API __declspec(dllimport)
	#endif // TE_BUILD_DLL
#else
	#error Thunder only support windows£¡
#endif  //TE_PLATFORM_WINDOWS

#ifdef TE_ENABLE_ASSERTS
	#define TE_ASSERT(x, ...) {if(!(x)){TE_CLIENT_ERROR("Assertion Failed:{0}",__VA_ARGS__);__debugbreak();)}}
	#define TE_CORE_ASSERT(x, ...) {if(!(x)){TE_CORE_ERROR("Assertion Failed:{0}",__VA_ARGS__);__debugbreak();)}}
#else
	#define TE_ASSERT(x, ...)
	#define TE_CORE_ASSERT(x, ...)
#endif // TE_ENABLE_ASSERTS




#define BIT(x) (1<<x)


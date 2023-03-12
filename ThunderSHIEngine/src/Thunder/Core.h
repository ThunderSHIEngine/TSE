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

#define BIT(x) (1<<x)


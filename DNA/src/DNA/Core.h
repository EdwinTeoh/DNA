#pragma once

#ifdef DNA_WINDOWS
	#ifdef DNA_BUILD_DLL
		#define DNA_API __declspec(dllexport)
	#else
		#define DNA_API __declspec(dllimport)
	#endif
#else
	#error DNA only on Windows
#endif // DNA_WINDOWS

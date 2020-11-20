#pragma once

#ifdef _DEBUG
	#include <iostream>
	#define LOG(m) std::cout << "Blib: " << m << std::endl
#else // _DEBUG
	#define LOG(m)
#endif // !_DEBUG

#define GM_EXPORT extern "C" __declspec (dllexport)

#define GM_TRUE 1.0

#define GM_FALSE 0.0

#define ID_NONE -1.0

typedef double gmreal_t;

typedef const char* gmstring_t;

typedef void* gmptr_t;

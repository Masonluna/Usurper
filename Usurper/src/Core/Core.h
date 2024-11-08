#pragma once

#include <glad/glad.h>
#include <iostream>

#define US_OPT 1

namespace Usurper {
	enum StatusCode
	{
		SUCCESS,
		FAILURE
	};

	void GLClearError();
	bool GLLogCall(const char* function, const char* file, int line);


#define ASSERT(x) if (!(x)) __debugbreak();

#if US_OPT

#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))
#else
#define GLCall(x) x;

#endif


}
#pragma once

#include <glad/glad.h>
#include <iostream>

#define OPTIMIZE 0

namespace Usurper {
	enum StatusCode
	{
		SUCCESS,
		FAILURE,
		ERROR
	};

	void GLClearError();
	bool GLLogCall(const char* function, const char* file, int line);


#define ASSERT(x) if (!(x)) __debugbreak();

#ifdef OPTIMIZE 0

#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))
#else
#define GLCall(x) x;

#endif


}
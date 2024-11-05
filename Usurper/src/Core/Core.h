#pragma once

#include <glad/glad.h>
#include <iostream>
namespace Usurper {
	enum StatusCode
	{
		SUCCESS,
		FAILURE,
		ERROR
	};

	inline void GLClearError()
	{
		while (glGetError() != GL_NO_ERROR);
	}
	inline bool GLLogCall(const char* function, const char* file, int line)
	{
		while (GLenum error = glGetError())
		{
			std::cout << "[OpenGL Error] (" << error << "): " << function << " "
				<< file << ":line " << line << std::endl;
			return false;
		}
		return true;
	}

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))



}
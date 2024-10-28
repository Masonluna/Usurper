#pragma once

#include <glad/glad.h>

namespace Usurper {

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))

	void GLClearError();
	bool GLLogCall(const char* function, const char* file, int line);


	class Renderer
	{
	public:
		void Init();

	private:
	};


}
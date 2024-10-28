#include "Renderer.h"

#include <iostream>


void Usurper::GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool Usurper::GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error] (" << error << "): " << function << " "
			<< file << ":line " << line << std::endl;
		return false;
	}
	return true;
}

void Usurper::Renderer::Init()
{

}

#include "Core.h"
#include "Log.h"

void Usurper::GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool Usurper::GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		US_ERROR("{0}", error);
		return false;
	}
	return true;
}

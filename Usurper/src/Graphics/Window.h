#pragma once
#include "Renderer.h"
#include <GLFW/glfw3.h>
#include "../Core/Core.h"



namespace Usurper {

	class Window
	{
	public:
		Window();
		Window(int width, int height, int scale, std::string title);
		~Window();
		StatusCode Init();


		GLFWwindow* GetGLFWwindow() const { return m_GLFWwindow; }
	private:
		GLFWwindow* m_GLFWwindow;
		Renderer m_Renderer;
		unsigned int m_Width;
		unsigned int m_Height;
		unsigned int m_Scale;
		std::string m_Title;
	};
}
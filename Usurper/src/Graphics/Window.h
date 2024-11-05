#pragma once
#include "Core/Core.h"
#include "Renderer.h"

#include <GLFW/glfw3.h>


namespace Usurper {

	// Callbacks
	void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
	void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	void processInput(GLFWwindow* window);

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
#include "Window.h"

Usurper::Window::Window()
{
	m_Width = 0;
	m_Height = 0;
	m_Scale = 0;
	m_Title = "";
	m_GLFWwindow = nullptr;
}

Usurper::Window::Window(int width, int height, int scale, std::string title)
	: m_Width(width), m_Height(height), m_Scale(scale), m_Title(title), m_GLFWwindow(nullptr)
{
}

Usurper::Window::~Window()
{
	glfwTerminate();
}

Usurper::StatusCode Usurper::Window::Init()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// GLFW window
	m_GLFWwindow = glfwCreateWindow(m_Width * m_Scale, m_Height * m_Scale, m_Title.c_str(), NULL, NULL);
	if (!m_GLFWwindow) {
		US_ERROR("Failed to create GLFW window");
		glfwTerminate();
		return FAILURE;
	}
	glfwMakeContextCurrent(m_GLFWwindow);

	// Glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		US_ERROR("Failed to initialize GLAD");
		glfwTerminate();
		return FAILURE;
	}
	return SUCCESS;
}

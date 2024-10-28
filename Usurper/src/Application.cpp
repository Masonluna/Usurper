#include "Application.h"
#include <iostream>

Usurper::Application::Application(const ApplicationSpec& spec)
	: m_Spec(spec), m_Renderer()
{
	m_Window = Window(spec.width, spec.height, spec.scale, spec.title);
}
Usurper::Application::~Application()
{
}
void Usurper::Application::Run()
{
	// Initialize Window
	if (m_Window.Init() == SUCCESS) {
		std::cout << "Successfully Initialized GLFW window" << std::endl;
	}
	m_GLFWwindow = m_Window.GetGLFWwindow();
	// Initialize Renderer
	// Initialize Game
	// Initialize Detla t

	// Start Game Loop
	while (!glfwWindowShouldClose(m_GLFWwindow)) {
		Loop();
	}
	// Game ends, cleanup
	// Close
}
void Usurper::Application::OnRender()
{
	GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}
void Usurper::Application::OnUpdate()
{
	ProcessInput();
}

void Usurper::Application::Loop()
{
	OnUpdate();
	OnRender();

	glfwSwapBuffers(m_GLFWwindow);
	glfwPollEvents();
}

void Usurper::Application::ProcessInput()
{
	if (glfwGetKey(m_GLFWwindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(m_GLFWwindow, true);
	}
}

#pragma once
#include "Graphics/Window.h"
#include "Graphics/VertexArray.h"
#include "Camera.h"
#include "Graphics/stb_image.h"

#include <string>
#include <iostream>

namespace Usurper {
	struct ApplicationSpec
	{
		int width = 300;
		int height = width / 16 * 10;
		int scale = 4;
		std::string title = "Usurper";
	};

	class Application
	{

	public:
		Application(const ApplicationSpec& spec = ApplicationSpec());
		~Application();

		void Run();

		void OnRender();
		void OnUpdate();
		void Loop();
		void ProcessInput();

	private:
		ApplicationSpec m_Spec;
		Renderer m_Renderer;
		Window m_Window;
		GLFWwindow* m_GLFWwindow = nullptr;
	};
}
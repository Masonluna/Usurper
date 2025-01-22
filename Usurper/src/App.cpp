#include <Scribble2D/Scribble2D.h>

namespace Usurper
{
	class HelloLayer : public Scribble::Layer
	{
	public:
		HelloLayer()
			: Layer("Hello")
		{
			m_Renderer.Init();
		}

		void OnUpdate(Scribble::Timestep ts) override
		{
			m_Renderer.DrawQuad(glm::vec2(20.0f, 20.0f), 150.0f, 150.0f, 10.0f, glm::vec3(0.0f, 1.0f, 0.0f));
		}

	private:
		Scribble::Renderer m_Renderer;
	};


	class App : public Scribble::Application
	{
	public:
		App(Scribble::WindowSpecs specs)
			: Scribble::Application(specs)
		{
			PushLayer(new HelloLayer());
		}
		~App() {}
	};

}

Scribble::Application* Scribble::CreateApplication()
{
	Scribble::WindowSpecs specs("App", 1920, 1080);
	return new Usurper::App(specs);
}
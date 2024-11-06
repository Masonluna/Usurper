#include "Core/Core.h"
#include "Application.h"


namespace Usurper {
	void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
	void CursorPosCallback(GLFWwindow* window, double xposIn, double yposIn);
	void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
	unsigned int LoadTexture(const char* path);

	Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
	float lastX = 0.0f;
	float lastY = 0.0f;
	bool firstMouse = true;

	// timing
	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
}

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

	// Initialize state
	lastX = m_Spec.width / 2.0f;
	lastY = m_Spec.height / 2.0f;

	// Initialize Window
	if (m_Window.Init() == SUCCESS) {
		std::cout << "Successfully Initialized window" << std::endl;
	}
	m_GLFWwindow = m_Window.GetGLFWwindow();

	// TODO: SET UP CALLBACKS
	glfwSetFramebufferSizeCallback(m_GLFWwindow, FramebufferSizeCallback);
	glfwSetCursorPosCallback(m_GLFWwindow, CursorPosCallback);
	glfwSetScrollCallback(m_GLFWwindow, ScrollCallback);

	// Initialize Game
	// Initialize Detla t

	float vertices[] = {
		// position				// color			// tex coord
		0.25f, 0.25f, 0.0f,		1.0f, 0.0f, 0.0f,	1.0f, 1.0f,
		0.25f, -0.25f, 0.0f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f,
		-0.25f, -0.25f, 0.0f,	0.0f, 0.0f, 1.0f,	0.0f, 0.0f,
		-0.25f, 0.25f, 0.0f,	1.0f, 1.0f, 0.0f,	0.0f, 1.0f
	};

	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	glm::vec3 position(0.0f, 0.0f, 0.0f);

	// ========== STATE ==========

	Shader shader("3.3.shader.vs.glsl", "3.3.shader.fs.glsl");

	VertexArray va;
	VertexBuffer vb(vertices, sizeof(vertices));
	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indices, 6);

	m_Mesh = std::unique_ptr<Mesh>(new Mesh(va, vb, ib));

	// Start Game Loop
	while (!glfwWindowShouldClose(m_GLFWwindow)) {
		Loop();
	}
	// Game ends, cleanup
	// Close
}
void Usurper::Application::OnRender()
{

	// Clear
	m_Renderer.Clear();

	// Draw
	//m_Renderer.Draw(vb, ib, shader);
	// Swap
	glfwSwapBuffers(m_GLFWwindow);

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



void Usurper::FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	GLCall(glViewport(0, 0, width, height));
}

void Usurper::CursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse) {
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}

void Usurper::ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(static_cast<float>(yoffset));

}

void Usurper::Application::ProcessInput()
{
	if (glfwGetKey(m_GLFWwindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(m_GLFWwindow, true);

	if (glfwGetKey(m_GLFWwindow, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(m_GLFWwindow, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(m_GLFWwindow, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(m_GLFWwindow, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);
	if (glfwGetKey(m_GLFWwindow, GLFW_KEY_E) == GLFW_PRESS)
		camera.ProcessKeyboard(UP, deltaTime);
	if (glfwGetKey(m_GLFWwindow, GLFW_KEY_Q) == GLFW_PRESS)
		camera.ProcessKeyboard(DOWN, deltaTime);
}

unsigned int Usurper::LoadTexture(const char* path)
{
	unsigned int textureID;
	GLCall(glGenTextures(1, &textureID));
	int width, height, nrComponents;
	unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
	if (data)
	{
		GLenum format;
		if (nrComponents == 1)
			format = GL_RED;
		else if (nrComponents == 3)
			format = GL_RGB;
		else if (nrComponents == 4)
			format = GL_RGBA;

		GLCall(glBindTexture(GL_TEXTURE_2D, textureID));
		GLCall(glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data));
		GLCall(glGenerateMipmap(GL_TEXTURE_2D));

		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

		stbi_image_free(data);
	}
	else {
		std::cout << "Texture failed to load at path: " << path << std::endl;
		stbi_image_free(data);
	}

	return textureID;
}
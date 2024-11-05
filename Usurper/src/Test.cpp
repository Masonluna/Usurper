//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
// 
//void processInput(GLFWwindow* window);
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);


//const unsigned int SCR_WIDTH = 1024;
//const unsigned int SCR_HEIGHT = 768;

/*int main()
{
	// =========== INIT ==========
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	
	// ---------- Window Init ----------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "USURPER", NULL, NULL);
	if (!window) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	// Callbacks set here
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// ---------- GLAD Init ----------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		return -1;
	}

	// ========== RENDER ==========
	while (!glfwWindowShouldClose(window)) {
		
		// Input processing
		processInput(window);

		// Set state
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw

		// Buffer swap and I/O event polling
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

void framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
}*/

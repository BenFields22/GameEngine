 #include "src/graphics/window.h"
 

int main()
{
	using namespace sparky;
	using namespace graphics;

	Window window("Sparky", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	//std::cout << glGetString(GL_VERSION) << std::endl;

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.closed())
	{
		//std::cout << window.getWidth() << " " << window.getHeight() << std::endl;

		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		//std::cout << x << "," << y << std::endl;
		//::cout << window.isButtonPressed(GLFW_MOUSE_BUTTON_LEFT) << std::endl;
		
		if (window.isKeyPressed(GLFW_KEY_ESCAPE))
		{
			exit(EXIT_FAILURE);
		}
		else if (window.isKeyPressed(GLFW_KEY_A))
		{
			std::cout << "The letter a was pressed" << std::endl;
		}
#if 1
		glBegin(GL_QUADS);
		glVertex2f(-.5f, -.5f);
		glVertex2f(0.5f, -.5f);
		glVertex2f(0.5f, .5f);
		glVertex2f(-.5f, .5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);

#endif		
		window.update();
	}

	//system("PAUSE");
	return 0;
}
 #include "src/graphics/window.h"
#include "src\maths\maths.h"



int main()
{
	using namespace sparky;
	using namespace graphics;
	using namespace maths;

	Window window("Sparky", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//**********TESTING**********
	//std::cout << glGetString(GL_VERSION) << std::endl;
	/*vec3 a(1.0f, 2.0f,5.0f);
	vec3 b(2,4,6);
	vec3 c = a + b;
	vec4 a(0.2f, 0.3f, 0.8f, 1.0f);
	vec4 b(0.5f, 0.2f, 0.1f, 1.0f);
	vec4 c = a + b;
	*/
	//**************************

	while (!window.closed())
	{

		window.clear();

		//******TEST PRINT OUTS******************
		//std::cout << window.getWidth() << " " << window.getHeight() << std::endl;
		//double x, y;
		//window.getMousePosition(x, y);
		//std::cout << c << std::endl;
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
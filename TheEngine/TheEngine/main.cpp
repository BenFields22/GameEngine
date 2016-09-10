 #include "src/graphics/window.h"
#include "src\maths\maths.h"
//#include "src\utils\fileutils.h"
#include "src\graphics\shader.h"


int main()
{
	using namespace sparky;
	using namespace graphics;
	using namespace maths;


	Window window("Sparky", 960, 540);
	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);


	GLfloat vertices[] = 
	{
		0,0,0,
		8,0,0,
		0,3,0,
		0,3,0,
		8,3,0,
		8,0,0

	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);


	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));

	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));


	//**********TESTING**********
	//std::cout << glGetString(GL_VERSION) << std::endl;

	/*vec3 a(1.0f, 2.0f,5.0f);
	std::string file = read_file("main.cpp");
	std::cout << file << std::endl;
	system("PAUSE");
	return 0;

	vec3 b(2,4,6);
	vec3 c = a + b;

	vec4 a(0.2f, 0.3f, 0.8f, 1.0f);
	vec4 b(0.5f, 0.2f, 0.1f, 1.0f);
	vec4 c = a + b;

	mat4 position = mat4::translation(vec3(2, 3, 4));
	position.multiply(mat4::scale(vec3(1,2,3)));
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

		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.update();
	}

	//system("PAUSE");
	return 0;
}
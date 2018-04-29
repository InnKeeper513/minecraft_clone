#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window{

	int width;
	int height;
	GLFWwindow *window;
	const char* title_name;
	static bool keys[1024];
	
	public:

	Window(int width, int height, const char* title);
	~Window();
	int getWidth();
	int getHeight();
	void update();
	void clear() const;
	bool closed() const;

	// Register Functions
	
	private:
	friend void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);	

};
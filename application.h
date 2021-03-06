#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>
#include "object.h"
#include "vec3d.h"
#include "window.h"
#include <map>
#include <iterator>
#include <string>

class Application {

	int screenWidth, screenHeight;
	char* title;
	Window* curWin;

public:
	Application(char* title);
	~Application();
	virtual void render() = 0;
	virtual void tick(float) = 0;

	// Methods for input

	void addWindow(int screenWidth, int screenHeight, char* title);
	Window* getCurWindow();

	virtual void init() = 0;
	void run();

};

#endif

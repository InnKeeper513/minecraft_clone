// Physics_Engine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "test.h"


int main()
{

	Test *test = new Test();
	test->run();
	return 0;
}


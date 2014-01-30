#pragma once
//--OpenGl includes
//#include <gl/glfw.h>
//--Standart c++ includes
#include <string>
#include <map>
//--Project includes
#include "Window.h"
class WindowManager {
public:
	/**
	Represents all the necessary data to create a window
	*/
	struct WindowData{
		std::string windowTitle = "Window";

		glm::vec2 windowSize = glm::vec2(800, 600);
		
		GLuint redBits = 8;
		GLuint blueBits = 8;
		GLuint greenBits = 8;

		GLuint alphaBits = 8;

		GLuint depthBits = 24;

		bool resizeable = true;

		GLFWmonitor* monitor = NULL;

		GLFWwindow* share = NULL;

		bool focus = true;

		std::map<int, int> extraFlags;
	};

    WindowManager();
    ~WindowManager();
	/**Creates a window 
	@param WindowData - The necessary data to create a window

	@return The window ID. (-1 if an error occurs)

	@throws std::runtime_error if an error occured while trying to create an window.

	@TODO Each window must have its own thread.
	*/
	GLuint createWindow(WindowData& data);

	bool deleteWindow(GLuint id);

	Window* getWindow(GLuint id);

private:
	GLuint getNextWindowID();

	std::map<GLuint, Window*> windows;
	GLuint nextId = 0;
};


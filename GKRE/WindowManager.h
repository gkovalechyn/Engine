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
    WindowManager();
    ~WindowManager();
	/**Creates a window 
	@param The window title.

	@return The window ID.
	*/
	GLuint createWindow(std::string windowName);

	bool deleteWindow(GLuint id);

	Window* getWindow(GLuint id);
private:
	GLuint getNextWindowID();

	std::map<GLuint, Window> windows;
	GLuint nextId = 0;
};


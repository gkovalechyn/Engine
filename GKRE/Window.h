#pragma once
//--OpenGl includes
#include <windows.h>
#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>

//--Rendering includes
#include "Program.h"

class Window {
public:
    Window(const GLuint id);

	void setSize(glm::vec2 size);
	
	void resize(glm::vec2 newSize);

	void setPosition(glm::vec2 position);
    ~Window();

private:
	glm::vec2 windowSize;
	Program shaders;
};


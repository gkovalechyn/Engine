#include "Window.h"


Window::Window(const GLuint _id, const GLFWwindow* _handle) : id(_id), handle(_handle) {
}


Window::~Window() {
}

GLuint Window::getId(){
	return this->id;
}

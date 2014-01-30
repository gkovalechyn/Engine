#include "Window.h"


Window::Window(const GLuint _id, GLFWwindow* _handle) : id(_id), handle(_handle) {
}


Window::~Window() {
}

GLuint Window::getId(){
	return this->id;
}

void Window::render(){
	double mx = 0, my = 0;
	glfwGetCursorPos(handle, &mx, &my);

	if (glfwGetCurrentContext() != handle){
		glfwMakeContextCurrent(handle);
	}

	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (std::vector<RenderableEntity*>::iterator it = toBeDrawn.begin(); it != toBeDrawn.end(); it++){
		(*it)->draw();
	}

	for (std::vector<ClickableObject*>::iterator it = clickables.begin(); it != clickables.end(); it++){
		//@TODO Check if mouse is inside
		ClickableObject* c = *it;
		if (c->isEnabled()){
			if (c->isInside(glm::vec2(mx, my))){
				c->onHover();
			}
			if (glfwClick)
		}
	}
}

void Window::resize(glm::vec2 newSize){

}

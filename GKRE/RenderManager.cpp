#include "RenderManager.h"


RenderManager::RenderManager() {
}


RenderManager::~RenderManager() {
}

Camera* RenderManager::getCamera(){
	return this->camera;
}

void RenderManager::init(){
	GLenum glewInitError = NULL;
	//glfw
	if (!glfwInit()){
		throw std::runtime_error("Could not initialize GLFW!");
		//@TODO Additional logging
	}

	//Initialize main window.
	this->wManager = new WindowManager();
	this->mainWindowId = wManager->createWindow(WindowManager::WindowData());

	glewExperimental = GL_TRUE;
	glewInitError = glewInit();

	if (glewInitError != GLEW_OK){
		throw std::runtime_error("Could not initialize GLEW!");
		//@TODO Additional logging
	}

	//enable depth buffering
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	//@TODO logging of these things
	// print out some info about the graphics drivers
	//std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
	//std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	//std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
	//std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

	// make sure OpenGL version 3.2 API is available
	if (!GLEW_VERSION_3_2){
		throw std::runtime_error("OpenGL 3.2 API is not available.");
	}
}

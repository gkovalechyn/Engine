#pragma once

#include "Camera.h"
#include "WindowManager.h"
/**
This is the main class of the rendering engine.
*/
class RenderManager {
public:
    RenderManager();
    ~RenderManager();

	Camera* getCamera();

	WindowManager* getWindowManager();
	/**
	Initializes the OpenGL wrappers and creates the main window.
	The window creation is necessary otherwise glew won't initialize.
	*/
	void init();

private:
	Camera* camera = NULL;
	WindowManager* wManager = NULL;
	GLuint mainWindowId = -1;
};


#pragma once

#include "Camera.h"
#include "WindowManager.h"
class RenderManager {
public:
    RenderManager();
    ~RenderManager();

	Camera* getCamera();

	WindowManager* getWindowManager();

	void init();

private:
	Camera* camera = NULL;
	WindowManager* wManager = NULL;
};


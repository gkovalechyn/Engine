#pragma once

#include "Camera.h"
class RenderManager {
public:
    RenderManager();
    ~RenderManager();

	Camera getCamera();

private:
	Camera camera;
};


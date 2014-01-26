#pragma once
//--OpenGl includes
#include <windows.h>
#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>
//--C++ includes
#include <vector>
//--Rendering includes
#include "Program.h"
#include "RenderableEntity.h"
#include "ClickableObject.h"

class Window {
public:
    Window(const GLuint id);

	void setSize(glm::vec2 size);
	
	void resize(glm::vec2 newSize);

	void setPosition(glm::vec2 position);

	void show();
	/**
	Clickable objects will be rendered, there is no need for adding them to the renderable
	entities using the addRenderableEntity function;
	*/
	void addClickableObject(ClickableObject* obj);

	void addRenderableEntity(RenderableEntity* ent);
    ~Window();

private:
	std::vector<RenderableEntity*> toBeDrawn;
	std::vector<ClickableObject*> clickables;

	glm::vec2 windowSize = glm::vec2(800,600);

	Program *shaders = NULL;

	const GLuint id;
};


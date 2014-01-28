#pragma once
//--OpenGl includes
#include <windows.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
//--C++ includes
#include <vector>
//--Rendering includes
#include "Program.h"
#include "RenderableEntity.h"
#include "ClickableObject.h"

class Window {
public:
    Window(const GLuint id, const GLFWwindow* handle);

	void setSize(glm::vec2 size);
	
	void resize(glm::vec2 newSize);

	void setPosition(glm::vec2 position);

	/**
	Clickable objects will be rendered, there is no need for adding them to the renderable
	entities using the addRenderableEntity function;
	*/
	void addClickableObject(ClickableObject* obj);
	/**
	These RenderableEntities are supposed to be the background of the menus and other astetic
	parts of the display.
	*/
	void addRenderableEntity(RenderableEntity* ent);

	GLuint getId();

    ~Window();

private:
	const GLFWwindow* handle;
	std::vector<RenderableEntity*> toBeDrawn;
	std::vector<ClickableObject*> clickables;

	glm::vec2 windowSize = glm::vec2(800,600);

	const GLuint id;
};


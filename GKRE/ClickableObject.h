#pragma once
//--Standart includes
#include <string>
//-OpenGl includes
#include <GL/glfw.h>
#include <glm/glm.hpp>
//--Project includes
#include "RenderableEntity.h"

class ClickableObject : RenderableEntity{
public:
	ClickableObject();
    ~ClickableObject();

	void setName(std::string name);

	void setTooltip(std::string tooltip);

	void setSize(glm::vec2 size);

	bool isInside(glm::vec2 pos);
	/**
	This function is called when the user clicks on this object.
	*/
	virtual void onClick() = 0;
private:
	//the size and position of this object on the screen
	glm::vec2 size;
	glm::vec2 pos;

protected:
	std::string name;
	std::string tooltip;
};


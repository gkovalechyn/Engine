#pragma once
//--Standart includes
#include <string>
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
	/**
	This function is called when the mouse hovers over this object.
	*/
	virtual void onHover() = 0;
private:
	//the size and position of this object on the screen
	glm::vec2 size;
	glm::vec2 pos;

protected:
	std::string name;
	std::string tooltip;
};


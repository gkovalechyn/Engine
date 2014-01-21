#pragma once
//--C++ includes

//--Project includes
#include "Model.h"
class RenderableEntity : public Model{
public:
	enum RenderType{
		TWO_D = 0x1,
		THREE_D = 0x2,
		GUI_BACKGROUND = 0x4,
		CLICKABLE_GUI = 0x8
	};
    RenderableEntity(RenderType type);
    ~RenderableEntity();

	virtual void draw() = 0;
private:
	const RenderType type;
	Model model;
};


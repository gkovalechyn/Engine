#pragma once

#include "Model.h"

/**
Represents a 3D model used for drawing 3D meshes
*/
class Model3 : public Model{
public:
    Model3();
    ~Model3();

	void render() override;
};


#pragma once

#include <GL\glew.h>
#include <glm/gtc/matrix_transform.hpp>

#include <exception>

#include "Texture.h"
#include "Program.h"

/**
Represents a 2D entity used for drawing on the screen, instead of the 3D model (Model.h)
used for drawing 3D objects.
*/
class Model2D {
public:
	Model2D();
	~Model2D();
	void render();

	// Sets the starting draw point of this model
	void setDrawStart(GLint drawStart);
	// Sets the amount of vertexes that should be drawn
	void setDrawCount(GLint drawDount);

	void setTexture(Texture* tex);

	void setVertexBuffer(GLfloat* buffer, GLuint vectorLength);

	void setDrawType(GLenum drawType);

	void setShaders(Program* shader);

	/**
	Sets the camera to be used when rendering this model
	*/
	void setCamera(Camera& c);

	//-matrix related
	/**
	Rotates this model around this vector
	*/
	void rotate(float degrees, glm::vec3 vector);

	/**
	Translates this model PLUS this vector
	*/
	void translate(glm::vec3 position);

	/**
	Scales this model based on this value
	*/
	void scale(float mult);

	void scale(float x, float y, float z);

	/**
	Applies this matrix directly to this model's model matrix.
	*/
	void apply(glm::mat4 transformation);

	/**
	Initializes the model generating the buffers
	*/
	void init();

	GLint getDrawStart();
	GLint getDrawCount();
	GLenum getDrawType();

};


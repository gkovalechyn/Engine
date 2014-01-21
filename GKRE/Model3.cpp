#include "Model3.h"


Model3::Model3() {
}


Model3::~Model3() {
}

void Model3::render(){
	shader->use();
	//set the shader uniforms
	shader->setUniform("tex", 0); //set to 0 because the texture will be bound to GL_TEXTURE0
	shader->setUniform("model", model);
	shader->setUniform("camera", c.matrix());
	//bind the texture
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->texture->object());

	//bind the VAO
	glBindVertexArray(vao);
	//draw the triangles
	glDrawArrays(drawType, drawStart, drawCount);

	//unbind everything
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);

	shader->stopUsing();
}

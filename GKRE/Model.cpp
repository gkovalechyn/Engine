#include "Model.h"


Model::Model() {
	c.setPosition(glm::vec3(5, 5, -10));
	c.lookAt(glm::vec3(0, 0, 5));
}


Model::~Model() {
    try {
        if (vbo != 0) {
            glDeleteBuffers(1, &vbo);
        }

        if (vao != 0) {
            glDeleteVertexArrays(1, &vao);
        }
    } catch (std::exception ex) {
		//replace with proper debug menu.
		//std::cout<< "MEMORY LEAK!" << std::endl;
		//std::cout<< ex.what() << std::endl;
    }
}


// Sets the starting draw point of this model
void Model::setDrawStart(GLint drawStart) {
    this->drawStart = drawStart;
}


// Sets the amount of vertexes that should be drawn
void Model::setDrawCount(GLint drawCount) {
    this->drawCount = drawCount;
}


void Model::setVertexBuffer(GLfloat* buffer, GLuint vectorLength) {
    this->vertexBufferData = buffer;
    this->arrayLength = vectorLength;
}

void Model::setDrawType(GLenum drawType) {
    this->drawType = drawType;
}

void Model::setTexture(Texture* tex) {
    this->texture = tex;
}

void Model::setShaders(Program* p) {
    this->shader = p;
}

void Model::init() {
	/*
    if (this->arrayLength == -1) {
        throw std::exception("Array length not set!");
    }
    if (this->drawCount == -1) {
        throw std::exception("drawCount not set!");
    }
    if (this->drawStart == -1) {
        throw std::exception("drawStart not set!");
    }
    if (this->drawType == -1) {
        throw std::exception("drawType not set!");
    }
    if (this->vertexBufferData == NULL) {
        throw std::exception("vertexBufferData not set!");
    }
    if (this->texture == NULL) {
        throw std::exception("Texture not set!");
    }
    if (this->shader == NULL) {
        throw std::exception("Shader not set!");
    }
	*/
	//everything should be fine by now
	assert(this->drawCount != -1);
	assert(this->drawStart != -1);
	assert(this->drawType != -1);
	assert(this->vertexBufferData != NULL);
	assert(this->texture != NULL);
	assert(this->shader != NULL);
    //generate the buffers
    glGenBuffers(1, &vbo);
    glGenVertexArrays(1, &vao);

    //bind the vao and the vbo and create the vertexBuffer
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindVertexArray(vao);

    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * arrayLength, vertexBufferData, GL_STATIC_DRAW);

    //@TODO enable the shader variables
    // connect the xyz to the "vert" attribute of the vertex shader
    glEnableVertexAttribArray(shader->attrib("vert"));
    glVertexAttribPointer(shader->attrib("vert"), 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), NULL);

    // connect the uv coords to the "vertTexCoord" attribute of the vertex shader
    glEnableVertexAttribArray(shader->attrib("vertTexCoord"));
    glVertexAttribPointer(shader->attrib("vertTexCoord"), 2, GL_FLOAT, GL_TRUE, 5 * sizeof(GLfloat), (const GLvoid*)(3 * sizeof(GLfloat)));
    //unbind the vao
    glBindVertexArray(0);
}

GLint Model::getDrawCount() {
    return this->drawCount;
}

GLint Model::getDrawStart() {
    return this->drawStart;
}

GLenum Model::getDrawType() {
    return this->drawType;
}

void Model::setCamera(Camera& c){
	this->c = c;
}

void Model::rotate(float degrees, glm::vec3 vector){
	assert(vector.length() != 0);
	model = glm::rotate(model, degrees, vector);
}

void Model::translate(glm::vec3 position){
	model = glm::translate(model, position);
}

void Model::scale(float mult){
	assert(mult > 0);
	model = glm::scale(model, glm::vec3(mult));
}

void Model::scale(float x, float y, float z){
	assert(x > 0 && y > 0 && z > 0);
	model = glm::scale(model, glm::vec3(x, y, z));
}

void Model::apply(glm::mat4 transformation){
	model *= transformation;
}

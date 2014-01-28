/*
main

Copyright 2012 Thomas Dalling - http://tomdalling.com/

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

// third-party libraries
#include <windows.h>
#include <GL/glew.h>
#include <GLFW\glfw3.h>
#include <glm/glm.hpp>

// standard C++ libraries
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <cmath>
//--
#include "../Texture.h"
#include "../Bitmap.h"
#include "../Model.h"
#include "Program.h"
// constants
const glm::vec2 SCREEN_SIZE(800, 600);
Texture* texture;
Texture* oTexture;
Model* model;
Model* oModel;
Program* shader;
//Window handle
GLFWwindow* handle = NULL;
// draws a single frame
static void render() {
    // clear everything
    glClearColor(0, 0, 0, 1); // black
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //render the models

    model->render();

	oModel->render();
    // swap the display buffers (displays what was just drawn)
    glfwSwapBuffers(handle);
	//--Handle the events
	glfwPollEvents();
}


void loadDefaultTexture() {
    Bitmap bmp = Bitmap::bitmapFromFile("bitmap1.bmp");
	Bitmap bmp2 = Bitmap::bitmapFromFile("bitmap2.bmp");

    bmp.flipVertically();
	bmp2.flipVertically();

    texture = new Texture(bmp, GL_NEAREST, GL_REPEAT);
	oTexture = new Texture(bmp2, GL_NEAREST, GL_REPEAT);
}

void loadModel() {
    model = new Model();
	oModel = new Model();
    GLfloat vertexBufferData[] = {
        //  X     Y     Z       U     V
        // bottom
        -1.0f, -1.0f, -1.0f, 0.0f, 0.0f,
        1.0f, -1.0f, -1.0f, 1.0f, 0.0f,
        -1.0f, -1.0f, 1.0f, 0.0f, 1.0f,
        1.0f, -1.0f, -1.0f, 1.0f, 0.0f,
        1.0f, -1.0f, 1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f, 0.0f, 1.0f,

        // top
        -1.0f, 1.0f, -1.0f, 0.0f, 0.0f,
        -1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, -1.0f, 1.0f, 0.0f,
        1.0f, 1.0f, -1.0f, 1.0f, 0.0f,
        -1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f,

        // front
        -1.0f, -1.0f, 1.0f, 1.0f, 0.0f,
        50.0f, -1.0f, 1.0f, 0.0f, 0.0f,
        -1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, -1.0f, 1.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        -1.0f, 1.0f, 1.0f, 1.0f, 1.0f,

        // back
        -1.0f, -1.0f, -1.0f, 0.0f, 0.0f,
        -1.0f, 1.0f, -1.0f, 0.0f, 1.0f,
        1.0f, -1.0f, -1.0f, 1.0f, 0.0f,
        1.0f, -1.0f, -1.0f, 1.0f, 0.0f,
        -1.0f, 1.0f, -1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, -1.0f, 1.0f, 1.0f,

        // left
        -1.0f, -1.0f, 1.0f, 0.0f, 1.0f,
        -1.0f, 1.0f, -1.0f, 1.0f, 0.0f,
        -1.0f, -1.0f, -1.0f, 0.0f, 0.0f,
        -1.0f, -1.0f, 1.0f, 0.0f, 1.0f,
        -1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, -1.0f, 1.0f, 0.0f,

        // right
        1.0f, -1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, -1.0f, -1.0f, 1.0f, 0.0f,
        1.0f, 1.0f, -1.0f, 0.0f, 0.0f,
        1.0f, -1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, -1.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 1.0f, 0.0f, 1.0f
    };

    model->setDrawStart(0);
    model->setDrawCount(6*2*3);
    model->setDrawType(GL_TRIANGLES);
    model->setVertexBuffer(vertexBufferData, sizeof(vertexBufferData) / sizeof(GLfloat));
    model->setShaders(shader);
    model->setTexture(texture);

	oModel->setDrawStart(0);
	oModel->setDrawCount(6 * 2 * 3);
	oModel->setDrawType(GL_TRIANGLES);
	oModel->setVertexBuffer(vertexBufferData, sizeof(vertexBufferData) / sizeof(GLfloat));
	oModel->setShaders(shader);
	oModel->setTexture(oTexture);

	oModel->translate(glm::vec3(5, 3, 10));

    model->init();
	oModel->init();
}

void loadShaders(const char* vertFilename, const char* fragFilename) {
    std::vector<Shader> shaders;
    shaders.push_back(Shader::shaderFromFile(vertFilename, GL_VERTEX_SHADER));
    shaders.push_back(Shader::shaderFromFile(fragFilename, GL_FRAGMENT_SHADER));
    shader = new Program(shaders);
}


// the program starts here
void appMain() {
    // initialise GLFW
    if (!glfwInit())
    { throw std::runtime_error("glfwInit failed"); }

    // open a window with GLFW
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	//--Set the bits
	glfwWindowHint(GLFW_RED_BITS, 16);
	glfwWindowHint(GLFW_GREEN_BITS, 16);
	glfwWindowHint(GLFW_BLUE_BITS, 16);

	glfwWindowHint(GLFW_ALPHA_BITS, 8);

	glfwWindowHint(GLFW_DEPTH_BITS, 24);
	
	//width, height, title, monitor, resource sharing
	handle = glfwCreateWindow((int)SCREEN_SIZE.x, (int)SCREEN_SIZE.y, "Test window", NULL, NULL);

	if (handle == NULL) {
		throw std::runtime_error("glfwOpenWindow failed. Can your hardware handle OpenGL 3.2?");
	}

	glfwMakeContextCurrent(handle);
    // initialise GLEW
    glewExperimental = GL_TRUE; //stops glew crashing on OSX :-/
	if (glewInit() != GLEW_OK) {
		throw std::runtime_error("GLEW init falied!");
    }

    //enable depth buffering
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    // print out some info about the graphics drivers
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

    // make sure OpenGL version 3.2 API is available
    if (!GLEW_VERSION_3_2){
		throw std::runtime_error("OpenGL 3.2 API is not available."); 
	}

    //-- load default stuff
    loadDefaultTexture();
    loadShaders("VertexShader.txt","FragmentShader.txt");
    //loadShaders("vertex-shader.txt","fragment-shader.txt");
    loadModel();

    // run while the window is open
    while (!glfwWindowShouldClose(handle)) {
        // draw one frame
        render();
    }

    // clean up and exit
    glfwTerminate();

    delete texture;
	delete oTexture;
    delete shader;
    delete model;
	delete oModel;
}



int main(int argc, char *argv[]) {
    try {
        appMain();
    } catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        getchar();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
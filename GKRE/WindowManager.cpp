#include "WindowManager.h"


WindowManager::WindowManager() {
}


WindowManager::~WindowManager() {
}

GLuint WindowManager::getNextWindowID() {
    return ++nextId;
}

GLuint WindowManager::createWindow(WindowData& data) {
    try {
        GLFWwindow* handle = NULL;
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        //--Set the bits
        glfwWindowHint(GLFW_RED_BITS, data.redBits);
        glfwWindowHint(GLFW_GREEN_BITS, data.greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, data.blueBits);

        glfwWindowHint(GLFW_ALPHA_BITS, data.alphaBits);

        glfwWindowHint(GLFW_DEPTH_BITS, data.depthBits);

        //width, height, title, monitor, resource sharing
        handle = glfwCreateWindow((int)data.windowSize.x, (int)data.windowSize.y, data.windowTitle.c_str(), data.monitor, data.share);

        if (handle != NULL) {
            GLuint id = this->getNextWindowID();
            Window* window = new Window(id, handle);

            this->windows.insert(std::pair<GLuint, Window*>(id, window));

            if (data.focus) {
                glfwMakeContextCurrent(handle);
            }

            return id;
        } else {
            throw std::runtime_error("Could not create window " + data.windowTitle);
        }
    } catch (std::runtime_error& error) {
        //@TODO LOGGING
        return -1;
    }
}

bool WindowManager::deleteWindow(GLuint id) {
    if (this->windows.find(id) != windows.end()) {
        windows.erase(id);
        return true;
    } else {
        return false;
    }
}

Window* WindowManager::getWindow(GLuint id) {
    return this->windows.at(id);
}

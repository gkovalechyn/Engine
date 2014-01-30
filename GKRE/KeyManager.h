#pragma once

#include "Window.h"
class KeyManager {
	//[in]	window	The window that received the event.
	//[in]	key	The keyboard key that was pressed or released.
	//[in]	scancode	The system - specific scancode of the key.
	//[in]	action	GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT.
	//[in]	mods	Bit field describing which modifier keys were held down.
	typedef void(*keyPressFunction)(int, int, int, int);


	//[in]	window	The window that received the event.
	//[in]	button	The mouse button that was pressed or released.
	//[in]	action	One of GLFW_PRESS or GLFW_RELEASE.
	//[in]	mods	Bit field describing which modifier keys were held down.
	typedef void(*MousePressFunction)(int, int, int);

	//[in]	window	The window that received the event.
	//[in]	xoffset	The scroll offset along the x - axis.
	//[in]	yoffset	The scroll offset along the y - axis.
	typedef void(*MouseScrollFunction)(double, double);


	//[in]	window	The window that received the event.
	//[in]	xpos	The new x - coordinate, in screen coordinates, of the cursor.
	//[in]	ypos	The new y - coordinate, in screen coordinates, of the cursor.
	typedef void(MouseEnterFunction)(double, double);
public:
    KeyManager();
    ~KeyManager();
	void addCursorEnterListener(Window* window, MouseEnterFunction f);

	void addKeyPressListener(Window* window, keyPressFunction f);

	void addMouseScrollListener(Window* window, MouseScrollFunction f);

	void addMousePressListener(Window* window, MousePressFunction f);
private:
	long msSinceLastMouseClick = 0;
	std::vector<std::pair<Window*, keyPressFunction>> keyPresses;
	std::vector<std::pair<Window*, keyPressFunction>> mousePresses;
	std::vector<std::pair<Window*, keyPressFunction>> mouseScroll;
};


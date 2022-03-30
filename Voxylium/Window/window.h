/*------------------------------------------------------------------------------------------
 * MIT License
 *
 * Copyright (c) 2022 Juna Knop
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * -----------------------------------------------------------------------------------------
 */

#ifndef _WINDOW_H_
#define _WINDOW_H_

// Tell glfw to include vulkan
#define GLFW_INCLUDE_VULKAN

/*
 * Headers
 */
#include "voxylium_exception.h"
#include "GLFW/glfw3.h"

/**
 * Represents a glfw window
 */
class Window {
 public:
	/**
	 * Initialize glfw library and create/open window
	 * @param windowName Name of window
	 */
	Window(const char* windowName);

	/**
	 * Destructor closes the window and terminates the GLFW library
	 */
	~Window();

	/**
	 * Needs to be called as long as the window needs to process events
	 * @return TRUE if window is open
	 * @return FALSE if window is closed
	 */
	bool update();

 private:
	const char* description;
	const GLFWvidmode* videoMode;
	GLFWwindow* window;
};

#endif //_WINDOW_H_

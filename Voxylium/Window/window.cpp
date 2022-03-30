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

#include "Window/window.h"

Window::Window(const char* windowName) {
	// Initialize the glfw library, if initialization fails throw exception
	if (!glfwInit()) {
		// Get glfw error description
		glfwGetError(&description);
		// Throw exception
		ThrowVoxyliumExc(1, std::string("GLFW couldn't be initialized")
								.append(description == nullptr ? "No glfw info" : description).c_str());
	}

	// Create a full screen window
	videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	if (!videoMode) {
		// Get glfw error description
		glfwGetError(&description);
		// Throw exception
		ThrowVoxyliumExc(2, std::string("Unable to obtain video mode of primary monitor: ")
								.append(description == nullptr ? "No GLFW info" : description).c_str());
	}
	// Set glfw window hints
	glfwWindowHint(GLFW_RED_BITS, videoMode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, videoMode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, videoMode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, videoMode->refreshRate);

	// Create window
	window = glfwCreateWindow(videoMode->width, videoMode->height, windowName, glfwGetPrimaryMonitor(), nullptr);
	if (!window) {
		// Get glfw error description
		glfwGetError(&description);
		// Throw exception
		ThrowVoxyliumExc(3, std::string("Window couldn't be opened: ")
								.append(description == nullptr ? "No GLFW info" : description).c_str());
	}
}

Window::~Window() {
	// Close window
	glfwDestroyWindow(window);
	// Terminate the glfw library
	glfwTerminate();
}

bool Window::update() {
	// Check if window is open
	if (!glfwWindowShouldClose(window)) {
		// Process events that are already in the event queue
		glfwPollEvents();
		// Check for errors in event poll
		glfwGetError(&description);
		if (description != nullptr) {
			ThrowVoxyliumExc(4, std::string("Error while processing window events: ").append(description).c_str());
		}

		return true;
	}

	// If window is closed
	return false;
}
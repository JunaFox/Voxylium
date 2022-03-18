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

#ifndef VOXYLIUM_VOXYLIUM_EXCEPTION_H
#define VOXYLIUM_VOXYLIUM_EXCEPTION_H

#include <exception>
#include <string>

#define __CUSTOM_THROW(ec, info) \
    throw VoxyliumException(ec, __FILE__, __FUNCTION__, __LINE__, info)

/**
 * @brief Throws a voxylium exception
 * @param ec Error code
 * @param info Info about error
 */
#define ThrowVoxyliumExc(ec, info) __CUSTOM_THROW(ec, info)

/**
 * \brief Represents a voxylium exception
 */
class VoxyliumException : public std::exception {
public:
	/**
	 * Constructor for a voxylium exception
	 * @param ec error code
	 * @param file_ file name, where the exception occurred
	 * @param line_ line, where the exception occurred
	 * @param func_ function, that caused the exception
	 * @param info_ info about the exception
	 */
    VoxyliumException(int ec_, const char* file_, const char* func_, int line_, const char* info_) :
		ec(ec_),
		file(file_),
        line(line_),
        func(func_),
        info(info_),
		message("------------------->Voxylium Exception<---------------------"
				"\nError occurred in: " + std::string(file) +
				"\nAt function: " + std::string(func) +
				"\nAt line: " + std::to_string(line) +
				"\nError code: " + std::to_string(ec) +
				"\nGiven information: " + std::string(info) +
				"\n------------------->       END        <----------------------")
    {
    }

    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }

private:
	/// File name, where the exception occurred
    const char* file;
	/// Line, where the exception occurred
    const int line;
	/// Error code
    const int ec;
    const char* func;
	/// Information about the error
    const char* info;
	/// Error message
	const std::string message;
};

#endif //VOXYLIUM_VOXYLIUM_EXCEPTION_H

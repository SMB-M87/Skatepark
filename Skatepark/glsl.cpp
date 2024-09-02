#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "glsl.h"

namespace OpenGL
{
	char* glsl::readFile(const char* filename)
	{
		// Open the file
		FILE* fp = fopen(filename, "r");
		if (!fp) {
			std::cerr << "Failed to open file: " << filename << std::endl;
			return nullptr;
		}

		// Move the file pointer to the end of the file and determing the length
		fseek(fp, 0, SEEK_END);
		size_t  file_length = ftell(fp);
		fseek(fp, 0, SEEK_SET);

		char* contents = new char[file_length + 1];
		if (!contents) {
			std::cerr << "Failed to allocate memory for file contents." << std::endl;
			fclose(fp);
			return nullptr;
		}
		for (unsigned int i = 0; i < file_length + 1; i++)
			contents[i] = 0;

		// Here's the actual read
		size_t bytes_read = fread(contents, 1, file_length, fp);
		contents[bytes_read] = '\0';
		fclose(fp);

		return contents;
	}

	bool glsl::compiledStatus(GLint shaderID)
	{
		GLint compiled = 0;
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compiled);

		if (compiled) {
			return true;
		}
		else {
			GLint logLength;
			glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logLength);
			if (logLength > 0) {
				char* msgBuffer = new char[logLength];
				glGetShaderInfoLog(shaderID, logLength, NULL, msgBuffer);
				std::cerr << "Shader compilation error:\n" << msgBuffer << std::endl;
				delete[] msgBuffer;
			}
			else
			{
				std::cerr << "Shader compilation failed with unknown error." << std::endl;
			}
			return false;
		}
	}

	GLuint glsl::makeVertexShader(const char* shaderSource)
	{
		GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShaderID, 1, (const GLchar**)&shaderSource, NULL);
		glCompileShader(vertexShaderID);

		bool compiledCorrectly = compiledStatus(vertexShaderID);
		if (compiledCorrectly)
		{
			return vertexShaderID;
		}
		return -1;
	}

	GLuint glsl::makeFragmentShader(const char* shaderSource)
	{
		GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShaderID, 1, (const GLchar**)&shaderSource, NULL);
		glCompileShader(fragmentShaderID);

		bool compiledCorrectly = compiledStatus(fragmentShaderID);
		if (compiledCorrectly) {
			return fragmentShaderID;
		}
		return -1;
	}

	GLuint glsl::makeShaderProgram(GLuint vertexShaderID, GLuint fragmentShaderID)
	{
		GLuint shaderID = glCreateProgram();
		glAttachShader(shaderID, vertexShaderID);
		glAttachShader(shaderID, fragmentShaderID);
		glLinkProgram(shaderID);

		GLint linkStatus;
		glGetProgramiv(shaderID, GL_LINK_STATUS, &linkStatus);
		if (linkStatus == GL_TRUE) {
			return shaderID;
		}
		else {
			GLint logLength;
			glGetProgramiv(shaderID, GL_INFO_LOG_LENGTH, &logLength);
			if (logLength > 0) {
				char* msgBuffer = new char[logLength];
				glGetProgramInfoLog(shaderID, logLength, NULL, msgBuffer);
				std::cerr << "Shader program linking error:\n" << msgBuffer << std::endl;
				delete[] msgBuffer;
			}
			else {
				std::cerr << "Shader program linking failed with unknown error." << std::endl;
			}
			glDeleteProgram(shaderID);
			return 0;
		}
	}
}
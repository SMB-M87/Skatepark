#ifndef LOADER_H
#define LOADER_H

#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <glm/glm.hpp>

namespace OpenGL
{
	class Loader {
	public:
		static bool Object(
			const char* path,
			std::vector<glm::vec3>& out_vertices,
			std::vector<glm::vec2>& out_uvs,
			std::vector<glm::vec3>& out_normals
		);

		static GLuint BMP(const char* imagepath);

		static GLuint BMPCube(std::vector<const char*>);
	};
}
#endif
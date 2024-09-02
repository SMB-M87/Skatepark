#include "speed_bump.h"

namespace OpenGL 
{
	SpeedBump::SpeedBump(
		glm::vec3 position_value,
		glm::vec3 rotate_value,
		glm::vec3 color_value,
		float scale_value
	) : shapes{}, Shape(
		position_value,
		rotate_value,
		color_value,
		scale_value
	) {
		// Quarter Pipes
		shapes.push_back(OpenGL::Cylinder(true, 75, 90, 0.5f, 0.5f, { position.x, position.y + 0.5f, position.z + 0.732f }, { 180.0f, 90.0f, 90.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "Texture/concrete.bmp"));
		shapes.push_back(OpenGL::Cylinder(true, 75, 90, 0.5f, 0.5f, { position.x, position.y + 0.5f, position.z - 0.732f }, { 180.0f, 270.0f, 90.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "Texture/concrete.bmp"));

		// Center
		shapes.push_back(OpenGL::Cuboid({ -0.25f, 0.370f, 0.232f }, { 0.25f, 0.370f, 0.232f }, { -0.25f, 0.370f, -0.232f }, { 0.25f, 0.370f, -0.232f }, { -0.25f, 0.0f, 0.232f }, { 0.25f, 0.0f, 0.232f }, { -0.25f, 0.0f, -0.232f }, { 0.25f, -0.0f, -0.232f }, { position.x, position.y, position.z }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "Texture/concrete.bmp"));
	
		// Top
		shapes.push_back(OpenGL::Cylinder(false, 180, 90, 0.25f, 0.5f, { position.x, position.y + 0.370f, position.z }, { 0.0f, 90.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "Texture/concrete.bmp"));
	}

	void SpeedBump::Init() {
		for (auto& shape : shapes)
			shape.Init();
	}

	void SpeedBump::Update(glm::mat4 projection_matrix, glm::mat4 view_matrix) {
		for (auto& shape : shapes)
			shape.Update(projection_matrix, view_matrix);
	}

	void SpeedBump::Render(glm::vec3 camera, glm::vec3 sun) {
		for (auto& shape : shapes)
			shape.Render(camera, sun);
	}
}
// Bowl is helaas niet 1 op 1 nagemaakt met realiteit :(

#include "bowl.h"

namespace OpenGL
{
	Bowl::Bowl(
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
		shapes.push_back(OpenGL::Cylinder(true, 90, 90, 1.0f, 6.0f, { position.x, position.y, position.z }, { 90.0f, 90.0f, 90.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "Texture/concrete.bmp"));
		shapes.push_back(OpenGL::Cylinder(true, 90, 90, 1.0f, 2.0f, { position.x + 3.0f, position.y, position.z - 1.0f }, { 0.0f, 0.0f, -90.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "Texture/concrete.bmp"));
		shapes.push_back(OpenGL::Cylinder(true, 90, 90, 1.0f, 2.0f, { position.x - 3.0f, position.y, position.z - 1.0f }, { 0.0f, 180.0f, -90.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "Texture/concrete.bmp"));
		shapes.push_back(OpenGL::Cylinder(true, 90, 90, 1.0f, 6.0f, { position.x, position.y, position.z - 2.0f }, { 180.0f, 90.0f, 90.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "Texture/concrete.bmp"));

		// Straight Copings
		shapes.push_back(OpenGL::Cylinder(false, 270, 90, 0.025f, 6.0f, { position.x, position.y, position.z + 1.0f }, { -90.0f, 90.0f, 0.0f}, { 0.7f, 0.7f, 0.7f }, 1.0f, "Texture/metallic.bmp", 128.0f));
		shapes.push_back(OpenGL::Cylinder(false, 270, 90, 0.025f, 2.0f, { position.x + 4.0f, position.y, position.z - 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "Texture/metallic.bmp", 128.0f));
		shapes.push_back(OpenGL::Cylinder(false, 270, 90, 0.025f, 2.0f, { position.x - 4.0f, position.y, position.z - 1.0f }, { 0.0f, 0.0f, -90.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "Texture/metallic.bmp", 128.0f));
		shapes.push_back(OpenGL::Cylinder(false, 270, 90, 0.025f, 6.0f, { position.x, position.y, position.z - 3.0f }, { 0.0f, 90.0f, 0.0f}, { 0.7f, 0.7f, 0.7f }, 1.0f, "Texture/metallic.bmp", 128.0f));

		// Transition's
		shapes.push_back(OpenGL::Sphere(true, 90, 90, 90, 90, { 0.0f, 0.0f, 0.0f }, { position.x - 3.0f, position.y, position.z }, { 180.0f, 180.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "Texture/concrete.bmp"));
		shapes.push_back(OpenGL::Sphere(true, 90, 90, 90, 90, { 0.0f, 0.0f, 0.0f }, { position.x + 3.0f, position.y, position.z }, { 180.0f, 180.0f, 90.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "Texture/concrete.bmp"));
		shapes.push_back(OpenGL::Sphere(true, 90, 90, 90, 90, { 0.0f, 0.0f, 0.0f }, { position.x - 3.0f, position.y, position.z - 2.0f }, { 0.0f, 180.0f, 270.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "Texture/concrete.bmp"));
		shapes.push_back(OpenGL::Sphere(true, 90, 90, 90, 90, { 0.0f, 0.0f, 0.0f }, { position.x + 3.0f, position.y, position.z - 2.0f }, { 0.0f, 180.0f, 180.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "Texture/concrete.bmp"));

		// Round Copings
		shapes.push_back(OpenGL::Torus(90, 90, 270, 90, 1.0f, 0.025f, position, { position.x - 3.0f, position.y, position.z }, { -270.0f, 180.0f, 0.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "Texture/metallic.bmp", 128.0f));
		shapes.push_back(OpenGL::Torus(90, 90, 270, 90, 1.0f, 0.025f, position, { position.x + 3.0f, position.y, position.z }, { 270.0f, 0.0f, -90.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "Texture/metallic.bmp", 128.0f));
		shapes.push_back(OpenGL::Torus(90, 90, 270, 90, 1.0f, 0.025f, position, { position.x - 3.0f, position.y, position.z - 2.0f }, { -90.0f, 0.0f, 90.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "Texture/metallic.bmp", 128.0f));
		shapes.push_back(OpenGL::Torus(90, 90, 270, 90, 1.0f, 0.025f, position, { position.x + 3.0f, position.y, position.z - 2.0f }, { 270.0f, 0.0f, 0.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "Texture/metallic.bmp", 128.0f));

		// Flat Bottom Surface
		shapes.push_back(OpenGL::Polygon( 3.0f, 1.0f, { position.x, position.y, position.z - 1.0f }, { 90.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f}, 1.0f, "Texture/concrete.bmp"));

		// Surrounding Corners
		shapes.push_back(OpenGL::Cuboid({ -0.375f, 0.75f, 2.0f }, { 0.375f, 0.75f, 2.0f }, { -0.375f, 0.75f, -2.0f }, { 0.375f, 0.75f, -2.0f }, { -0.375f, -0.75f, 2.0f }, { 0.375f, -0.75f, 2.0f }, { -0.375f, -0.75f, -2.0f }, { 0.375f, -0.75f, -2.0f }, { position.x - 4.375f, position.y - 0.75f, position.z - 1.0f}, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "Texture/concrete.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -0.375f, 0.75f, 2.0f }, { 0.375f, 0.75f, 2.0f }, { -0.375f, 0.75f, -2.0f }, { 0.375f, 0.75f, -2.0f }, { -0.375f, -0.75f, 2.0f }, { 0.375f, -0.75f, 2.0f }, { -0.375f, -0.75f, -2.0f }, { 0.375f, -0.75f, -2.0f }, { position.x + 4.375f, position.y - 0.75f, position.z - 1.0f}, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "Texture/concrete.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -0.5f, 0.75f, 4.75f }, { 0.5f, 0.75f, 4.75f }, { -0.5f, 0.75f, -4.75f }, { 0.5f, 0.75f, -4.75f }, { -0.5f, -0.75f, 4.75f }, { 0.5f, -0.75f, 4.75f }, { -0.5f, -0.75f, -4.75f }, { 0.5f, -0.75f, -4.75f }, { position.x, position.y - 0.75f, position.z - 3.5f}, { 0.0f, 90.0f, 0.0f}, { 0.5f, 0.5f, 0.5f }, 1.0f, "Texture/concrete.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -0.2f, 0.75f, 4.75f }, { 0.2f, 0.75f, 4.75f }, { -0.2f, 0.75f, -4.75f }, { 0.2f, 0.75f, -4.75f }, { -0.2f, -0.75f, 4.75f }, { 0.2f, -0.75f, 4.75f }, { -0.2f, -0.75f, -4.75f }, { 0.2f, -0.75f, -4.75f }, { position.x, position.y - 0.75f, position.z + 1.2f}, { 0.0f, 90.0f, 0.0f}, { 0.5f, 0.5f, 0.5f }, 1.0f, "Texture/concrete.bmp"));
	}

	void Bowl::Init() {
		for (auto& shape : shapes)
			shape.Init();
	}

	void Bowl::Update(glm::mat4 projection_matrix, glm::mat4 view_matrix) {
		for (auto& shape : shapes)
			shape.Update(projection_matrix, view_matrix);
	}

	void Bowl::Render(glm::vec3 camera, glm::vec3 sun) {
		for (auto& shape : shapes)
			shape.Render(camera, sun);
	}
}
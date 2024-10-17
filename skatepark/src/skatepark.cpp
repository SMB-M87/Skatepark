#include "skatepark.h"

namespace OpenGL
{
	Skatepark::Skatepark(
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
		// Asphalt
		shapes.push_back(OpenGL::Polygon(6.25f, 9.0f, { position.x - 1.375f, position.y - 0.5f, position.z + 17.1f }, { 90.0f, 0.0f, 0.0f }, { 0.25f, 0.25f, 0.25f }, 1.0f, "resource/texture/asphalt.bmp"));
		shapes.push_back(OpenGL::Polygon(1.25f, 2.5f, { position.x - 8.875f, position.y - 0.5f, position.z + 10.6f }, { 90.0f, 0.0f, 0.0f }, { 0.25f, 0.25f, 0.25f }, 1.0f, "resource/texture/asphalt.bmp"));

		// Grass
		shapes.push_back(OpenGL::Cuboid({ -1.4385f, 0.75f, 0.65f }, { 1.4385f, 0.0f, 0.65f }, { -1.4385f, 0.0f, -0.65f }, { 1.4385f, 0.0f, -0.65f }, { -1.4385f, 0.0f, 0.65f }, { 1.4385f, 0.0f, 0.65f }, { -1.4385f, 0.0f, -0.65f }, { 1.4385f, 0.0f, -0.65f }, { position.x - 6.188f, position.y - 1.5f, position.z + 7.45f }, { 0.0f, 180.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Prism(1.4375f, 0.75f, 2.5f, 0.0f, -1.4375f, { position.x - 6.1875f, position.y -0.75f, position.z + 4.3f }, { 0.0f, 180.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Polygon(1.25f, 3.15f, { position.x - 8.875f, position.y - 0.5f, position.z + 4.95f }, { 90.0f, 0.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.4385f, 1.125f, 0.4f }, { 1.4385f, 0.35f, 0.4f }, { -1.4385f, 0.75f, -0.4f }, { 1.4385f, 0.0f, -0.4f }, { -1.4385f, 0.0f, 0.4f }, { 1.4385f, 0.0f, 0.4f }, { -1.4385f, 0.0f, -0.4f }, { 1.4385f, 0.0f, -0.4f }, { position.x - 6.188f, position.y - 1.5f, position.z + 1.4f }, { 0.0f, 180.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.25f, 0.35f, 0.4f }, { 1.25f, 0.0f, 0.4f }, { -1.25f, 0.0f, -0.4f }, { 1.25f, 0.0f, -0.4f }, { -1.25f, 0.0f, 0.4f }, { 1.25f, 0.0f, 0.4f }, { -1.25f, 0.0f, -0.4f }, { 1.25f, 0.0f, -0.4f }, { position.x - 8.875f, position.y - 1.5f, position.z + 1.4f }, { 0.0f, 180.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.4385f, 1.5f, 2.5f }, { 1.4385f, 0.35f, 2.5f }, { -1.4385f, 1.125f, -2.5f }, { 1.4385f, 0.35f, -2.5f }, { -1.4385f, 0.0f, 2.5f }, { 1.4385f, 0.0f, 2.5f }, { -1.4385f, 0.0f, -2.5f }, { 1.4385f, 0.0f, -2.5f }, { position.x - 6.188f, position.y - 1.5f, position.z - 1.5f}, { 0.0f, 180.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.25f, 0.35f, 2.5f }, { 1.25f, 0.0f, 2.5f }, { -1.25f, 0.35f, -2.5f }, { 1.25f, 0.0f, -2.5f }, { -1.25f, 0.0f, 2.5f }, { 1.25f, 0.0f, 2.5f }, { -1.25f, 0.0f, -2.5f }, { 1.25f, 0.0f, -2.5f }, { position.x - 8.875f, position.y - 1.5f, position.z - 1.5f }, { 0.0f, 180.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.4385f, 0.0f, 2.8f }, { 1.4385f, 0.0f, 2.8f }, { -1.4385f, 1.5f, -2.8f }, { 1.4385f, 0.35f, -2.8f }, { -1.4385f, 0.0f, 2.8f }, { 1.4385f, 0.0f, 2.8f }, { -1.4385f, 0.0f, -2.8f }, { 1.4385f, 0.0f, -2.8f }, { position.x - 6.188f, position.y - 1.5f, position.z - 6.8f }, { 0.0f, 180.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.25f, 0.0f, 2.8f }, { 1.25f, 0.0f, 2.8f }, { -1.25f, 0.35f, -2.8f }, { 1.25f, 0.0f, -2.8f }, { -1.25f, 0.0f, 2.8f }, { 1.25f, 0.0f, 2.8f }, { -1.25f, -0.01f, -2.8f }, { 1.25f, -0.01f, -2.8f }, { position.x - 8.875f, position.y - 1.5f, position.z - 6.8f }, { 0.0f, 180.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -4.75f, 0.0f, 2.8f }, { 4.75f, 0.0f, 2.8f }, { -4.75f, 1.5f, -2.8f }, { 4.75f, 1.5f, -2.8f }, { -4.75f, 0.0f, 2.8f }, { 4.75f, 0.0f, 2.8f }, { -4.75f, 0.0f, -2.8f }, { 4.75f, 0.0f, -2.8f }, { position.x, position.y - 1.5f, position.z - 6.8f }, { 0.0f, 180.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.4385f, 0.0f, 2.8f }, { 1.4385f, 0.0f, 2.8f }, { -1.4385f, 0.85f, -2.8f }, { 1.4385f, 1.5f, -2.8f }, { -1.4385f, 0.0f, 2.8f }, { 1.4385f, 0.0f, 2.8f }, { -1.4385f, 0.0f, -2.8f }, { 1.4385f, 0.0f, -2.8f }, { position.x + 6.1885f, position.y - 1.5f, position.z - 6.8f }, { 0.0f, 180.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.4385f, 0.0f, 2.8f }, { 1.4385f, 0.0f, 2.8f }, { -1.4385f, 0.35f, -2.8f }, { 1.4385f, 0.85f, -2.8f }, { -1.4385f, -0.01f, 2.8f }, { 1.4385f, -0.01f, 2.8f }, { -1.4385f, -0.01f, -2.8f }, { 1.4385f, -0.01f, -2.8f }, { position.x + 9.0655f, position.y - 1.5f, position.z - 6.8f }, { 0.0f, 180.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.4385f, 1.5f, 2.5f }, { 1.4385f, 0.85f, 2.5f }, { -1.4385f, 1.5f, -2.5f }, { 1.4385f, 0.85f, -2.5f }, { -1.4385f, 0.0f, 2.5f }, { 1.4385f, 0.0f, 2.5f }, { -1.4385f, 0.0f, -2.5f }, { 1.4385f, 0.0f, -2.5f }, { position.x + 6.1885f, position.y - 1.5f, position.z - 1.5f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.4385f, 0.85f, 2.5f }, { 1.4385f, 0.55f, 2.5f }, { -1.4385f, 0.85f, -2.5f }, { 1.4385f, 0.35f, -2.5f }, { -1.4385f, 0.0f, 2.5f }, { 1.4385f, 0.0f, 2.5f }, { -1.4385f, 0.0f, -2.5f }, { 1.4385f, 0.0f, -2.5f }, { position.x + 9.0655f, position.y - 1.5f, position.z - 1.5f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.4385f, 1.1f, 0.4f }, { 1.4385f, 0.85f, 0.4f }, { -1.4385f, 1.5f, -0.4f }, { 1.4385f, 0.85f, -0.4f }, { -1.4385f, 0.0f, 0.4f }, { 1.4385f, 0.0f, 0.4f }, { -1.4385f, 0.0f, -0.4f }, { 1.4385f, 0.0f, -0.4f }, { position.x + 6.1885f, position.y - 1.5f, position.z + 1.4f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.4385f, 0.85f, 0.4f }, { 1.4385f, 0.85f, 0.4f }, { -1.4385f, 0.85f, -0.4f }, { 1.4385f, 0.55f, -0.4f }, { -1.4385f, 0.0f, 0.4f }, { 1.4385f, 0.0f, 0.4f }, { -1.4385f, 0.0f, -0.4f }, { 1.4385f, 0.0f, -0.4f }, { position.x + 9.0655f, position.y - 1.5f, position.z + 1.4f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.4385f, 0.75f, 0.375f }, { 1.4385f, 0.85f, 0.375f }, { -1.4385f, 1.1f, -0.375f }, { 1.4385f, 0.85f, -0.375f }, { -1.4385f, 0.0f, 0.375f }, { 1.4385f, 0.0f, 0.375f }, { -1.4385f, 0.0f, -0.375f }, { 1.4385f, 0.0f, -0.375f }, { position.x + 6.1885f, position.y - 1.5f, position.z + 2.175f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.4385f, 0.85f, 0.375f }, { 1.4385f, 1.35f, 0.375f }, { -1.4385f, 0.85f, -0.375f }, { 1.4385f, 0.85f, -0.375f }, { -1.4385f, 0.0f, 0.375f }, { 1.4385f, 0.0f, 0.375f }, { -1.4385f, 0.0f, -0.375f }, { 1.4385f, 0.0f, -0.375f }, { position.x + 9.0655f, position.y - 1.5f, position.z + 2.175f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.4385f, 0.75f, 2.125f }, { 1.4385f, 0.85f, 2.125f }, { -1.4385f, 0.75f, -2.125f }, { 1.4385f, 0.85f, -2.125f }, { -1.4385f, 0.0f, 2.125f }, { 1.4385f, 0.0f, 2.125f }, { -1.4385f, 0.0f, -2.125f }, { 1.4385f, 0.0f, -2.125f }, { position.x + 6.1885f, position.y - 1.5f, position.z + 4.675f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.4385f, 0.85f, 2.125f }, { 1.4385f, 1.35f, 2.125f }, { -1.4385f, 0.85f, -2.125f }, { 1.4385f, 1.35f, -2.125f }, { -1.4385f, 0.0f, 2.125f }, { 1.4385f, 0.0f, 2.125f }, { -1.4385f, 0.0f, -2.125f }, { 1.4385f, 0.0f, -2.125f }, { position.x + 9.0655f, position.y - 1.5f, position.z + 4.675f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.4385f, 0.3f, 0.3f }, { 1.4385f, 0.85f, 0.3f }, { -1.4385f, 0.75f, -0.3f }, { 1.4385f, 0.85f, -0.3f }, { -1.4385f, 0.0f, 0.3f }, { 1.4385f, 0.0f, 0.3f }, { -1.4385f, 0.0f, -0.3f }, { 1.4385f, 0.0f, -0.3f }, { position.x + 6.1885f, position.y - 1.5f, position.z + 7.1f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.4385f, 0.85f, 0.3f }, { 1.4385f, 1.4f, 0.3f }, { -1.4385f, 0.85f, -0.3f }, { 1.4385f, 1.35f, -0.3f }, { -1.4385f, 0.0f, 0.3f }, { 1.4385f, 0.0f, 0.3f }, { -1.4385f, 0.0f, -0.3f }, { 1.4385f, 0.0f, -0.3f }, { position.x + 9.0655f, position.y - 1.5f, position.z + 7.1f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -2.777f, 0.325371f, 9.35f }, { 0.223f, 0.55f, 9.35f }, { -2.777f, 0.325371f, -9.35f }, { 2.777f, 1.4f, -9.35f }, { -2.777f, 0.0f, 9.35f }, { 0.223f, 0.0f, 9.35f }, { -2.777f, 0.0f, -9.35f }, { 2.777f, 0.0f, -9.35f }, { position.x + 7.727f, position.y - 1.5f, position.z + 16.75f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.5f, 0.325371f, 2.0f }, { 1.5f, 0.85f, 2.0f }, { -1.5f, 0.325371f, -2.0f }, { 1.5f, 0.55f, -2.0f }, { -1.5f, 0.0f, 2.0f }, { 1.5f, 0.0f, 2.0f }, { -1.5f, 0.0f, -2.0f }, { 1.5f, 0.0f, -2.0f }, { position.x + 6.45f, position.y - 1.5f, position.z + 28.1f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -7.5375f, 0.325371f, 2.0f }, { 7.5375f, 0.325371f, 2.0f }, { -7.5375f, 0.0f, -2.0f }, { 7.5375f, 0.325371f, -2.0f }, { -7.5375f, 0.0f, 2.0f }, { 7.5375f, 0.0f, 2.0f }, { -7.5375f, 0.0f, -2.0f }, { 7.5375f, 0.0f, -2.0f }, { position.x - 2.5875f, position.y - 1.5f, position.z + 28.1f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.7f, 0.0f }, 1.0f, "resource/texture/grass.bmp"));

		// Sand
		shapes.push_back(OpenGL::Polygon(1.25f, 6.5f, { position.x - 8.875f, position.y - 0.5f, position.z + 19.6f }, { 90.0f, 0.0f, 0.0f }, { 0.76f, 0.7f, 0.5f }, 1.0f, "resource/texture/sand.bmp"));

		// Elevation
		shapes.push_back(OpenGL::Cuboid({ -0.2f, 0.75f, 1.875f }, { 0.2f, 0.75f, 1.875f }, { -0.2f, 0.75f, -1.875f }, { 0.2f, 0.75f, -1.875f }, { -0.2f, -0.75f, 1.875f }, { 0.2f, -0.75f, 1.875f }, { -0.2f, -0.75f, -1.875f }, { 0.2f, -0.75f, -1.875f }, { position.x + 2.875f, position.y - 0.75f, position.z + 1.6f }, { 0.0f, 90.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -0.2f, 0.75f, 1.875f }, { 0.2f, 0.75f, 1.875f }, { -0.2f, 0.75f, -1.875f }, { 0.2f, 0.75f, -1.875f }, { -0.2f, -0.75f, 1.875f }, { 0.2f, -0.75f, 1.875f }, { -0.2f, -0.75f, -1.875f }, { 0.2f, -0.75f, -1.875f }, { position.x - 2.875f, position.y - 0.75f, position.z + 1.6f }, { 0.0f, 90.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -2.5f, 0.375f, 4.75f }, { 2.5f, 0.375f, 4.75f }, { -2.5f, 0.375f, -4.75f }, { 2.5f, 0.375f, -4.75f }, { -2.5f, -0.375f, 4.75f }, { 2.5f, -0.375f, 4.75f }, { -2.5f, -0.375f, -4.75f }, { 2.5f, -0.375f, -4.75f }, { position.x, position.y - 1.125f, position.z + 4.3f }, { 0.0f, 90.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));

		bowl = {};
		bump = {};

		// Elevation Bank's
		shapes.push_back(OpenGL::Prism(1.0f, 0.75f, 1.0f, 0.0f, -1.0f, { position.x, position.y, position.z + 2.4f }, { 0.0f, 270.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/graffiti.bmp"));
		shapes.push_back(OpenGL::Prism(0.65f, 0.75f, 3.5f, 0.0f, -0.65f, { position.x + 1.25f, position.y - 0.75f, position.z + 7.45f }, { 0.0f, 270.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/graffiti.bmp"));
		shapes.push_back(OpenGL::Prism(0.65f, 0.75f, 0.3f, 0.0f, -0.65f, { position.x - 4.45f, position.y - 0.75f, position.z + 7.45f }, { 0.0f, 270.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/graffiti1.bmp"));

		// Elevation Quarter's
		shapes.push_back(OpenGL::Cylinder(true, 90, 90, 0.75f, 3.75f, { position.x + 2.875f, position.y, position.z + 2.55f }, { 180.0f, 90.0f, 90.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));
		shapes.push_back(OpenGL::Cylinder(false, 270, 90, 0.025f, 3.75f, { position.x + 2.875f, position.y, position.z + 1.8f }, { 0.0f, 90.0f, 0.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "resource/texture/metallic.bmp", 128.0f));
		shapes.push_back(OpenGL::Cylinder(true, 90, 90, 0.75f, 3.75f, { position.x - 2.875f, position.y, position.z + 2.55f }, { 180.0f, 90.0f, 90.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));
		shapes.push_back(OpenGL::Cylinder(false, 270, 90, 0.025f, 3.75f, { position.x - 2.875f, position.y, position.z + 1.8f }, { 0.0f, 90.0f, 0.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "resource/texture/metallic.bmp", 128.0f));

		// Elevation Manual Pad
		shapes.push_back(OpenGL::Cuboid({ -0.65f, 0.65f, 0.15f }, { 0.65f, 0.65f, 0.15f }, { -0.65f, 0.65f, 0.0f }, { 0.65f, 0.65f, 0.0f }, { -0.65f, -0.65f, 0.15f }, { 0.65f, -0.65f, 0.15f }, { -0.65f, -0.65f, 0.0f }, { 0.65f, -0.65f, 0.0f }, { position.x + 3.6f, position.y - 0.6f, position.z + 5.85f }, { 90.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/graffiti2.bmp"));

		// Flat-Down Ledge
		shapes.push_back(OpenGL::Cuboid({ -0.15f, 0.3f, 0.8f }, { 0.15f, 0.3f, 0.8f }, { -0.15f, 0.3f, -0.8f }, { 0.15f, 0.3f, -0.8f }, { -0.15f, 0.0f, 0.8f }, { 0.15f, 0.0f, 0.8f }, { -0.15f, 0.0f, -0.8f }, { 0.15f, 0.0f, -0.8f }, { position.x + 1.5f, position.y - 0.75f, position.z + 6.0f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/graffiti2.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -0.15f, 0.3f, 0.65f }, { 0.15f, 0.3f, 0.65f }, { -0.15f, -0.45f, -0.65f }, { 0.15f, -0.45f, -0.65f }, { -0.15f, 0.0f, 0.65f }, { 0.15f, 0.0f, 0.65f }, { -0.15f, -0.75f, -0.65f }, { 0.15f, -0.75f, -0.65f }, { position.x + 1.5f, position.y - 0.75f, position.z + 7.45f }, { 0.0f, 180.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/graffiti2.bmp"));

		// Square Rail
		shapes.push_back(OpenGL::Cuboid({ -0.0175f, 0.00675f, 0.40675f }, { 0.0175f, 0.00675f, 0.40675f }, { -0.0175f, 0.00675f, -0.40675f }, { 0.0175f, 0.00675f, -0.40675f }, { -0.0175f, -0.00675f, 0.40675f }, { 0.0175f, -0.00675f, 0.40675f }, { -0.0175f, -0.00675f, -0.40675f }, { 0.0175f, -0.00675f, -0.40675f }, { position.x -1.4f, position.y - 0.59575f, position.z + 6.39325f }, { 0.0f, 0.0f, 0.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "resource/texture/metallic.bmp", "resource/shader/shader.vert", "resource/shader/shader.frag", 128.0f));
		shapes.push_back(OpenGL::Cuboid({ -0.0175f, 0.1475f, 0.00675f }, { 0.0175f, 0.1475f, 0.00675f }, { -0.0175f, 0.1475f, -0.00675f }, { 0.0175f, 0.1475f, -0.00675f }, { -0.0175f, 0.0f, 0.00675f }, { 0.0175f, 0.0f, 0.00675f }, { -0.0175f, 0.0f, -0.00675f }, { 0.0175f, 0.0f, -0.00675f }, { position.x - 1.4f, position.y - 0.75f, position.z + 6.79325f }, { 0.0f, 0.0f, 0.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "resource/texture/metallic.bmp", "resource/shader/shader.vert", "resource/shader/shader.frag", 128.0f));
		shapes.push_back(OpenGL::Cuboid({ -0.0175f, 0.1475f, 0.00675f }, { 0.0175f, 0.1475f, 0.00675f }, { -0.0175f, 0.1475f, -0.00675f }, { 0.0175f, 0.1475f, -0.00675f }, { -0.0175f, 0.0f, 0.00675f }, { 0.0175f, 0.0f, 0.00675f }, { -0.0175f, 0.0f, -0.00675f }, { 0.0175f, 0.0f, -0.00675f }, { position.x - 1.4f, position.y - 0.75f, position.z + 6.39325f }, { 0.0f, 0.0f, 0.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "resource/texture/metallic.bmp", "resource/shader/shader.vert", "resource/shader/shader.frag", 128.0f));
		shapes.push_back(OpenGL::Cuboid({ -0.0175f, 0.1475f, 0.00675f }, { 0.0175f, 0.1475f, 0.00675f }, { -0.0175f, 0.1475f, -0.00675f }, { 0.0175f, 0.1475f, -0.00675f }, { -0.0175f, 0.0f, 0.00675f }, { 0.0175f, 0.0f, 0.00675f }, { -0.0175f, 0.0f, -0.00675f }, { 0.0175f, 0.0f, -0.00675f }, { position.x - 1.4f, position.y - 0.75f, position.z + 5.99325f }, { 0.0f, 0.0f, 0.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "resource/texture/metallic.bmp", "resource/shader/shader.vert", "resource/shader/shader.frag", 128.0f));

		// Stair Ledge
		shapes.push_back(OpenGL::Cuboid({ -0.65f, 0.525f, 0.15f }, { 0.65f, 0.525f, 0.15f }, { -0.65f, 0.525f, -0.15f }, { 0.65f, 0.525f, -0.15f }, { -0.65f, -0.525f, 0.15f }, { 0.65f, -0.525f, 0.15f }, { -0.65f, -0.525f, -0.15f }, { 0.65f, -0.525f, -0.15f }, { position.x - 2.4f, position.y - 0.975f, position.z + 7.45f }, { 0.0f, 90.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/graffiti.bmp"));

		// Stair
		shapes.push_back(OpenGL::Cuboid({ -0.8f, 0.4875f, 0.09375f }, { 0.8f, 0.4875f, 0.09375f }, { -0.8f, 0.4875f, -0.09375f }, { 0.8f, 0.4875f, -0.09375f }, { -0.8f, -0.4875f, 0.09375f }, { 0.8f, -0.4875f, 0.09375f }, { -0.8f, -0.4875f, -0.09375f }, { 0.8f, -0.4875f, -0.09375f }, { position.x - 3.35f, position.y - 1.40625f, position.z + 7.2875f }, { 90.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/graffiti2.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -0.8f, 0.325f, 0.09375f }, { 0.8f, 0.325f, 0.09375f }, { -0.8f, 0.325f, -0.09375f }, { 0.8f, 0.325f, -0.09375f }, { -0.8f, -0.325f, 0.09375f }, { 0.8f, -0.325f, 0.09375f }, { -0.8f, -0.325f, -0.09375f }, { 0.8f, -0.325f, -0.09375f }, { position.x - 3.35f, position.y - 1.21875f, position.z + 7.125f }, { 90.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/graffiti3.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -0.8f, 0.1625f, 0.09375f }, { 0.8f, 0.1625f, 0.09375f }, { -0.8f, 0.1625f, -0.09375f }, { 0.8f, 0.1625f, -0.09375f }, { -0.8f, -0.1625f, 0.09375f }, { 0.8f, -0.1625f, 0.09375f }, { -0.8f, -0.1625f, -0.09375f }, { 0.8f, -0.1625f, -0.09375f }, { position.x - 3.35f, position.y - 1.03125f, position.z + 6.9625f }, { 90.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/graffiti1.bmp"));
		shapes.push_back(OpenGL::Polygon(0.8f, 0.1626f, { position.x - 3.35f, position.y - 0.5f, position.z + 7.93775f }, { 90.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f}, 1.0f, "resource/texture/graffiti.bmp"));

		// Stair Square Rail
		shapes.push_back(OpenGL::Cuboid({ -0.0175f, 0.00675f, 0.6635f }, { 0.0175f, 0.00675f, 0.6635f }, { -0.0175f, -0.74325f, -0.6635f }, { 0.0175f, -0.74325f, -0.6635f }, { -0.0175f, -0.00675f, 0.6635f }, { 0.0175f, -0.00675f, 0.6635f }, { -0.0175f, -0.75675f, -0.6635f }, { 0.0175f, -0.75675f, -0.6635f }, { position.x - 4.1675f, position.y - 0.4f, position.z + 7.45f }, { 0.0f, 180.0f, 0.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "resource/texture/metallic.bmp", "resource/shader/shader.vert", "resource/shader/shader.frag", 128.0f));
		shapes.push_back(OpenGL::Cuboid({ -0.0175f, 0.338375f, 0.00675f }, { 0.0175f, 0.338375f, 0.00675f }, { -0.0175f, 0.34855f, -0.00675f }, { 0.0175f, 0.34855f, -0.00675f }, { -0.0175f, -0.002f, 0.00675f }, { 0.0175f, -0.002f, 0.00675f }, { -0.0175f, 0.002f, -0.00675f }, { 0.0175f, 0.002f, -0.00675f }, { position.x - 4.1675f, position.y - 1.125f, position.z + 7.45 }, { 0.0f, 0.0f, 0.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "resource/texture/metallic.bmp", "resource/shader/shader.vert", "resource/shader/shader.frag", 128.0f));
		shapes.push_back(OpenGL::Cuboid({ -0.0175f, 0.336375f, 0.00675f }, { 0.0175f, 0.336375f, 0.00675f }, { -0.0175f, 0.34325f, -0.00675f }, { 0.0175f, 0.34325f, -0.00675f }, { -0.0175f, 0.0f, 0.00675f }, { 0.0175f, 0.0f, 0.00675f }, { -0.0175f, 0.0f, -0.00675f }, { 0.0175f, 0.0f, -0.00675f }, { position.x - 4.1675f, position.y - 0.75f, position.z + 6.79325f }, { 0.0f, 0.0f, 0.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "resource/texture/metallic.bmp", "resource/shader/shader.vert", "resource/shader/shader.frag", 128.0f));
		shapes.push_back(OpenGL::Cuboid({ -0.0175f, 0.34325f, 0.00675f }, { 0.0175f, 0.34325f, 0.00675f }, { -0.0175f, 0.35175f, -0.00675f }, { 0.0175f, 0.35175f, -0.00675f }, { -0.0175f, 0.0f, 0.00675f }, { 0.0175f, 0.0f, 0.00675f }, { -0.0175f, 0.0f, -0.00675f }, { 0.0175f, 0.0f, -0.00675f }, { position.x - 4.1675f, position.y - 1.5f, position.z + 8.10675f }, { 0.0f, 0.0f, 0.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "resource/texture/metallic.bmp", "resource/shader/shader.vert", "resource/shader/shader.frag", 128.0f));

		// Long Raw Ledge
		shapes.push_back(OpenGL::Cuboid({ -0.1f, 0.15f, 9.5f }, { 0.1f, 0.15f, 9.5f }, { -0.1f, 0.15f, -9.5f }, { 0.1f, 0.15f, -9.5f }, { -0.1f, -0.15f, 9.5f }, { 0.1f, -0.15f, 9.5f }, { -0.1f, -0.15f, -9.5f }, { 0.1f, -0.15f, -9.5f }, { position.x + 4.85f, position.y - 1.35f, position.z + 16.6f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));

		//Round Rail
		shapes.push_back(OpenGL::Cylinder(false, 360, 90, 0.025f, 1.513f, { position.x + 3.3f, position.y - 1.35f, position.z + 12.0f }, { 0.0f, 0.0f, 0.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "resource/texture/metallic.bmp", 128.0f));
		shapes.push_back(OpenGL::Cuboid({ -0.0175f, 0.1475f, 0.00675f }, { 0.0175f, 0.1475f, 0.00675f }, { -0.0175f, 0.1475f, -0.00675f }, { 0.0175f, 0.1475f, -0.00675f }, { -0.0175f, 0.0f, 0.00675f }, { 0.0175f, 0.0f, 0.00675f }, { -0.0175f, 0.0f, -0.00675f }, { 0.0175f, 0.0f, -0.00675f }, { position.x + 3.3f, position.y - 1.5f, position.z + 11.2575f }, { 0.0f, 0.0f, 0.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "resource/texture/metallic.bmp", "resource/shader/shader.vert", "resource/shader/shader.frag", 128.0f));
		shapes.push_back(OpenGL::Cuboid({ -0.0175f, 0.1475f, 0.00675f }, { 0.0175f, 0.1475f, 0.00675f }, { -0.0175f, 0.1475f, -0.00675f }, { 0.0175f, 0.1475f, -0.00675f }, { -0.0175f, 0.0f, 0.00675f }, { 0.0175f, 0.0f, 0.00675f }, { -0.0175f, 0.0f, -0.00675f }, { 0.0175f, 0.0f, -0.00675f }, { position.x + 3.3f, position.y - 1.5f, position.z + 12.0f }, { 0.0f, 0.0f, 0.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "resource/texture/metallic.bmp", "resource/shader/shader.vert", "resource/shader/shader.frag", 128.0f));
		shapes.push_back(OpenGL::Cuboid({ -0.0175f, 0.1475f, 0.00675f }, { 0.0175f, 0.1475f, 0.00675f }, { -0.0175f, 0.1475f, -0.00675f }, { 0.0175f, 0.1475f, -0.00675f }, { -0.0175f, 0.0f, 0.00675f }, { 0.0175f, 0.0f, 0.00675f }, { -0.0175f, 0.0f, -0.00675f }, { 0.0175f, 0.0f, -0.00675f }, { position.x + 3.3f, position.y - 1.5f, position.z + 12.7425f }, { 0.0f, 0.0f, 0.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "resource/texture/metallic.bmp", "resource/shader/shader.vert", "resource/shader/shader.frag", 128.0f));

		// Low Ledge
		shapes.push_back(OpenGL::Cuboid({ -0.125f, 0.05f, 0.75f }, { 0.125f, 0.05f, 0.75f }, { -0.125f, 0.05f, -0.75f }, { 0.125f, 0.05f, -0.75f }, { -0.125f, -0.05f, 0.75f }, { 0.125f, -0.05f, 0.75f }, { -0.125f, -0.05f, -0.75f }, { 0.125f, -0.05f, -0.75f }, { position.x + 4.6225f, position.y - 1.45f, position.z + 16.0f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));

		// Short High Ledge
		shapes.push_back(OpenGL::Cuboid({ -0.175f, 0.15f, 0.4f }, { 0.175f, 0.15f, 0.4f }, { -0.175f, 0.15f, -0.4f }, { 0.175f, 0.15f, -0.4f }, { -0.175f, -0.15f, 0.4f }, { 0.175f, -0.15f, 0.4f }, { -0.175f, -0.15f, -0.4f }, { 0.175f, -0.15f, -0.4f }, { position.x + 3.0f, position.y - 1.35f, position.z + 18.5f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));

		// Bank Kicker
		shapes.push_back(OpenGL::Prism(1.0f, 1.0f, 0.75f, -0.65f, -0.35f, { position.x + 0.7f, position.y - 0.5f, position.z + 16.3f }, { 0.0f, 90.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));

		// Funbox
		shapes.push_back(OpenGL::Cuboid({ -1.5f, 1.0f, 1.0f }, { 1.5f, 1.0f, 1.0f }, { -1.5f, 1.0f, -1.0f }, { 1.5f, 1.0f, -1.0f }, { -5.0f, -1.0f, 4.0f }, { 5.0f, -1.0f,  4.0f }, { -5.0f, -1.0f, -1.0f }, { 5.0f, -1.0f, -1.0f }, { position.x - 4.4f, position.y - 1.2f, position.z + 16.3f }, { 0.0f, 90.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 0.35f, "resource/texture/concrete.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.65f, 0.45f, 0.15f }, { 1.65f, 0.45f, 0.15f }, { -1.65f, 0.45f, -0.15f }, { 1.65f, 0.45f, -0.15f }, { -1.65f, -0.45f, 0.15f }, { 1.65f, -0.45f, 0.15f }, { -1.65f, -0.45f, -0.15f }, { 1.65f, -0.45f, -0.15f }, { position.x - 4.9f, position.y - 1.05f, position.z + 16.3f }, { 0.0f, 90.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -0.3f, 0.45f, 0.225f }, { 0.3f, 0.45f, 0.225f }, { -0.3f, 0.45f, 0.0f }, { 0.3f, 0.45f, 0.0f }, { -0.3f, -0.45f, 0.225f }, { 0.3f, -0.45f, 0.225f }, { -0.3f, -0.45f, 0.0f }, { 0.3f, -0.45f, 0.0f }, { position.x - 5.35f, position.y - 1.275f, position.z + 16.25f }, { 90.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));

		// Low manual pad
		shapes.push_back(OpenGL::Cuboid({ -0.3f, 0.55f, 0.125f }, { 0.3f, 0.55f, 0.125f }, { -0.3f, 0.55f, 0.0f }, { 0.3f, 0.55f, 0.0f }, { -0.3f, -0.55f, 0.125f }, { 0.3f, -0.55f, 0.125f }, { -0.3f, -0.55f, 0.0f }, { 0.3f, -0.55f, 0.0f }, { position.x - 7.325f, position.y - 1.375f, position.z + 16.25f }, { 90.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));

		// Back Bank's
		shapes.push_back(OpenGL::Prism(1.0f, 1.25f, 1.0f, 0.0f, -1.0f, { position.x + 0.925f, position.y - 0.25f, position.z + 23.3f }, { 0.0f, 90.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.0f, 1.25f, 0.35f }, { 1.0f, 1.25f, 0.35f }, { -1.0f, 1.25f, -0.35f }, { 1.0f, 1.25f, -0.35f }, { -1.0f, 0.0f, 0.35f }, { 1.0f, 0.0f, 0.35f }, { -1.0f, 0.0f, -0.35f }, { 1.0f, 0.0f, -0.35f }, { position.x + 0.925f, position.y - 1.5f, position.z + 24.65f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));

		shapes.push_back(OpenGL::Prism(1.0f, 1.25f, 1.0f, 0.0f, -1.0f, { position.x - 4.075f, position.y - 0.25f, position.z + 23.3f }, { 0.0f, 90.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));
		shapes.push_back(OpenGL::Cuboid({ -1.0f, 1.25f, 0.35f }, { 1.0f, 1.25f, 0.35f }, { -1.0f, 1.25f, -0.35f }, { 1.0f, 1.25f, -0.35f }, { -1.0f, 0.0f, 0.35f }, { 1.0f, 0.0f, 0.35f }, { -1.0f, 0.0f, -0.35f }, { 1.0f, 0.0f, -0.35f }, { position.x - 4.075f, position.y - 1.5f, position.z + 24.65f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));

		// Back Quarter's
		shapes.push_back(OpenGL::Cylinder(true, 90, 90, 1.0f, 1.5f, { position.x + 2.675f, position.y - 0.5f, position.z + 23.0f }, { 180.0f, 90.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));
		shapes.push_back(OpenGL::Cylinder(false, 270, 90, 0.025f, 1.5f, { position.x + 2.675f, position.y - 0.5f, position.z + 24.0f }, { 0.0f, 270.0f, 0.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "resource/texture/metallic.bmp", 128.0f));
		shapes.push_back(OpenGL::Cuboid({ -0.75f, 1.0f, 0.35f }, { 0.75f, 1.0f, 0.35f }, { -0.75f, 1.0f, -0.35f }, { 0.75f, 1.0f, -0.35f }, { -0.75f, 0.0f, 0.35f }, { 0.75f, 0.0f, 0.35f }, { -0.75f, 0.0f, -0.35f }, { 0.75f, 0.0f, -0.35f }, { position.x + 2.675f, position.y - 1.5f, position.z + 24.35f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));

		shapes.push_back(OpenGL::Cylinder(true, 90, 90, 2.0f, 3.0f, { position.x - 1.575f, position.y + 0.5f, position.z + 22.3f }, { 180.0f, 90.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));
		shapes.push_back(OpenGL::Cylinder(false, 270, 90, 0.025f, 3.0f, { position.x - 1.575f, position.y + 0.5f, position.z + 24.3f }, { 0.0f, 270.0f, 0.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "resource/texture/metallic.bmp", 128.0f));
		shapes.push_back(OpenGL::Cuboid({ -1.5f, 2.0f, 0.35f }, { 1.5f, 2.0f, 0.35f }, { -1.5f, 2.0f, -0.35f }, { 1.5f, 2.0f, -0.35f }, { -1.5f, 0.0f, 0.35f }, { 1.5f, 0.0f, 0.35f }, { -1.5f, 0.0f, -0.35f }, { 1.5f, 0.0f, -0.35f }, { position.x - 1.575f, position.y - 1.5f, position.z + 24.65f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));

		shapes.push_back(OpenGL::Cylinder(true, 90, 90, 1.0f, 2.0f, { position.x - 6.075f, position.y - 0.5f, position.z + 23.0f }, { 180.0f, 90.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));
		shapes.push_back(OpenGL::Cylinder(false, 270, 90, 0.025f, 2.0f, { position.x - 6.075f, position.y - 0.5f, position.z + 24.0f }, { 0.0f, 270.0f, 0.0f }, { 0.7f, 0.7f, 0.7f }, 1.0f, "resource/texture/metallic.bmp", 128.0f));
		shapes.push_back(OpenGL::Cuboid({ -1.0f, 1.0f, 0.35f }, { 1.0f, 1.0f, 0.35f }, { -1.0f, 1.0f, -0.35f }, { 1.0f, 1.0f, -0.35f }, { -1.0f, 0.0f, 0.35f }, { 1.0f, 0.0f, 0.35f }, { -1.0f, 0.0f, -0.35f }, { 1.0f, 0.0f, -0.35f }, { position.x - 6.075f, position.y - 1.5f, position.z + 24.35f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "resource/texture/concrete.bmp"));
	}

	void Skatepark::Init() {
		bowl.Init();
		bump.Init();

		for (auto& shape : shapes)
			shape.Init();
	}

	void Skatepark::Update(glm::mat4 projection_matrix, glm::mat4 view_matrix) {
		bowl.Update(projection_matrix, view_matrix);
		bump.Update(projection_matrix, view_matrix);

		for (auto& shape : shapes)
			shape.Update(projection_matrix, view_matrix);
	}

	void Skatepark::Render(glm::vec3 camera, glm::vec3 sun) {
		bowl.Render(camera, sun);
		bump.Render(camera, sun);

		for (auto& shape : shapes)
			shape.Render(camera, sun);
	}
}
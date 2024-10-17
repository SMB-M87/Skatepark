#include "sphere.h"

namespace OpenGL
{
	Sphere::Sphere(
		bool cap_value,
		int sphere_degrees_value,
		int sphere_slices_value,
		int circle_degrees_value,
		int circle_slices_value,
		glm::vec3 center_value,
		glm::vec3 position_value,
		glm::vec3 rotate_value,
		glm::vec3 color_value,
		float scale_value,
		const char* texture,
		float shininess,
		bool shading
	) : cap(cap_value), 
		sphere_degrees(sphere_degrees_value > 2 && sphere_degrees_value <= 180 ? sphere_degrees_value : 180),
		sphere_slices(sphere_slices_value > 2 && sphere_slices_value <= sphere_degrees && ((180 % sphere_slices_value) == 0) ? sphere_slices_value : 36),
		sphere_slice_ratio(sphere_degrees / static_cast<float>(sphere_slices)),
		circle_degrees(circle_degrees_value > 2 && circle_degrees_value <= 360 ? circle_degrees_value : 360),
		circle_slices(circle_slices_value > 2 && circle_slices_value <= circle_degrees && ((360 % circle_slices_value) == 0) ? circle_slices_value : 36),
		circle_slice_ratio(circle_degrees / static_cast<float>(circle_slices)),
		center(center_value),
		Shape(
			position_value,
			rotate_value,
			color_value,
			scale_value,
			texture,
			shininess,
			shading
		) {
		texScale = 0.5f / (sphere_slices * circle_slices);

		for (int sphere = 0; sphere < sphere_slices; sphere++)
		{
			float sphere_angle = glm::radians(static_cast<float>(sphere * sphere_slice_ratio));
			float next_sphere_angle = glm::radians(static_cast<float>((sphere + 1) * sphere_slice_ratio));

			for (int circle = 0; circle < circle_slices; circle++)
			{
				float circle_angle = glm::radians(static_cast<float>(circle * circle_slice_ratio));
				float next_circle_angle = glm::radians(static_cast<float>((circle + 1) * circle_slice_ratio));

				glm::vec3 vertex1(
					glm::cos(circle_angle) * glm::sin(sphere_angle),
					glm::sin(circle_angle) * glm::sin(sphere_angle),
					glm::cos(sphere_angle)
				);
				glm::vec3 vertex2(
					glm::cos(circle_angle) * glm::sin(next_sphere_angle),
					glm::sin(circle_angle) * glm::sin(next_sphere_angle),
					glm::cos(next_sphere_angle)
				);
				glm::vec3 vertex3(
					glm::cos(next_circle_angle) * glm::sin(next_sphere_angle),
					glm::sin(next_circle_angle) * glm::sin(next_sphere_angle),
					glm::cos(next_sphere_angle)
				);
				glm::vec3 vertex4(
					glm::cos(next_circle_angle) * glm::sin(sphere_angle),
					glm::sin(next_circle_angle) * glm::sin(sphere_angle),
					glm::cos(sphere_angle)
				);
				glm::vec3 normal1 = glm::normalize(vertex1);
				glm::vec3 normal2 = glm::normalize(vertex2);
				glm::vec3 normal3 = glm::normalize(vertex3);
				glm::vec3 normal4 = glm::normalize(vertex4);
				if (cap) {
					normal1 = -normal1;
					normal2 = -normal2;
					normal3 = -normal3;
					normal4 = -normal4;
				}

				float u = circle_angle / (2 * glm::pi<float>());
				float v = sphere_angle / glm::pi<float>();
				glm::vec2 uv1(u * texScale, v * texScale);
				glm::vec2 uv2(u * texScale, ((sphere_angle + sphere_slice_ratio) / glm::pi<float>()) * texScale);
				glm::vec2 uv3(((circle_angle + circle_slice_ratio) / (2 * glm::pi<float>())) * texScale, ((sphere_angle + sphere_slice_ratio) / glm::pi<float>()) * texScale);
				glm::vec2 uv4(((circle_angle + circle_slice_ratio) / (2 * glm::pi<float>())) * texScale, v * texScale);

				vertices.push_back(Format3D(vertex1, normal1, uv1));
				vertices.push_back(Format3D(vertex2, normal2, uv2));
				vertices.push_back(Format3D(vertex3, normal3, uv3));

				vertices.push_back(Format3D(vertex3, normal3, uv3));
				vertices.push_back(Format3D(vertex4, normal4, uv4));
				vertices.push_back(Format3D(vertex1, normal1, uv1));

				if (cap)
				{
					glm::vec3 cap1(glm::cos(sphere_angle), glm::sin(sphere_angle), -1.0f);
					glm::vec3 cap2(glm::cos(sphere_angle), glm::sin(sphere_angle), 1.0f);
					glm::vec3 cap3(glm::cos(next_sphere_angle), glm::sin(next_sphere_angle), 1.0f);
					glm::vec3 cap4(glm::cos(next_sphere_angle), glm::sin(next_sphere_angle), -1.0f);
					float xy = circle < ((circle_slices / 2) - 1) ? 1.0f : -1.0f;

					if ((circle_degrees >= 90 && (circle == ((circle_slices / 4) - 1)) || (circle_degrees >= 270 && circle == (((circle_slices / 4) * 3) - 1)))) {
						glm::vec3 frontSideVertex1(0.0f, cap1.y * xy, cap1.x);
						glm::vec3 frontSideVertex2(0.0f, xy, cap2.x);
						glm::vec3 frontSideVertex3(0.0f, xy, cap3.x);
						glm::vec3 frontSideVertex4(0.0f, cap4.y * xy, cap4.x);
						glm::vec3 normal = glm::normalize(glm::cross(frontSideVertex1 - frontSideVertex2, frontSideVertex1 - frontSideVertex3));

						float u1 = (circle_angle / circle_degrees) * 0.5f;
						float u2 = ((circle_angle + circle_slice_ratio) / circle_degrees) * 0.5f;
						float v = 0.5f;
						glm::vec2 uv1(u1 * texScale, v * texScale);
						glm::vec2 uv2(u1 * texScale, (1.0f - v) * texScale);
						glm::vec2 uv3(u2 * texScale, (1.0f - v) * texScale);
						glm::vec2 uv4(u2 * texScale, v * texScale);

						vertices.push_back(Format3D(frontSideVertex1, normal, uv1));
						vertices.push_back(Format3D(frontSideVertex2, normal, uv2));
						vertices.push_back(Format3D(frontSideVertex3, normal, uv3));

						vertices.push_back(Format3D(frontSideVertex3, normal, uv3));
						vertices.push_back(Format3D(frontSideVertex4, normal, uv4));
						vertices.push_back(Format3D(frontSideVertex1, normal, uv1));
					}
					else if ((circle_degrees >= 90 && circle == 0) || (circle_degrees >= 180 && circle == ((circle_slices / 2) - 1))) {
						glm::vec3 topSideVertex1(cap1.y * xy, 0.0f, cap1.x);
						glm::vec3 topSideVertex2(xy, 0.0f, cap2.x);
						glm::vec3 topSideVertex3(xy, 0.0f, cap3.x);
						glm::vec3 topSideVertex4(cap4.y * xy, 0.0f, cap4.x);
						glm::vec3 normal = glm::normalize(glm::cross(topSideVertex1 - topSideVertex2, topSideVertex1 - topSideVertex3));

						float u1 = (circle_angle / circle_degrees) * 0.5f;
						float u2 = ((circle_angle + circle_slice_ratio) / circle_degrees) * 0.5f;
						float v = 0.5f;
						glm::vec2 uv1(u1 * texScale, v * texScale);
						glm::vec2 uv2(u1 * texScale, (1.0f - v) * texScale);
						glm::vec2 uv3(u2 * texScale, (1.0f - v) * texScale);
						glm::vec2 uv4(u2 * texScale, v * texScale);

						vertices.push_back(Format3D(topSideVertex1, -normal, uv1));
						vertices.push_back(Format3D(topSideVertex2, -normal, uv2));
						vertices.push_back(Format3D(topSideVertex3, -normal, uv3));

						vertices.push_back(Format3D(topSideVertex3, -normal, uv3));
						vertices.push_back(Format3D(topSideVertex4, -normal, uv4));
						vertices.push_back(Format3D(topSideVertex1, -normal, uv1));
					}
				}
			}
		}
	}
}
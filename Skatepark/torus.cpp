//      Inspiration: https://gamedev.stackexchange.com/questions/16845/how-do-i-generate-a-torus-mesh
//					 https://webglfundamentals.org/webgl/lessons/webgl-qna-how-to-create-a-torus.html
// 
//			Functie: https://www.desmos.com/calculator/qtuexzquz1?lang=nl

#include "torus.h"

namespace OpenGL
{
	Torus::Torus(
		int torus_degrees_value,
		int torus_slices_value,
		int circle_degrees_value,
		int circle_slices_value,
		float outer_radius_value,
		float inner_radius_value,
		glm::vec3 center_value,
		glm::vec3 position_value,
		glm::vec3 rotate_value,
		glm::vec3 color_value,
		float scale_value,
		const char* texture,
		float shininess
	) : torus_degrees(torus_degrees_value),
		torus_slices(torus_slices_value > 2 && torus_slices_value < 361 && ((360 % torus_slices_value) == 0) ? torus_slices_value : 36),
		torus_slice_ratio(torus_degrees / torus_slices),
		circle_degrees(circle_degrees_value),
		circle_slices(circle_slices_value > 2 && circle_slices_value < 361 && ((360 % circle_slices_value) == 0) ? circle_slices_value : 36),
		circle_slice_ratio(circle_degrees_value / circle_slices),
		outer_radius(outer_radius_value), 
		inner_radius(inner_radius_value), 
		center(center_value), 
		Shape(
			position_value,
			rotate_value,
			color_value,
			scale_value,
			texture,
			shininess
	) {
		float texScaleU = 1.0f / torus_slices;
		float texScaleV = 1.0f / circle_slices;

		for (int torus = 0; torus < torus_slices; torus++) {
			float angle_torus = glm::radians(static_cast<float>(torus * torus_slice_ratio));
			float next_angle_torus = glm::radians(static_cast<float>((torus + 1) * torus_slice_ratio));

			for (int circle = 0; circle < circle_slices; circle++) {
				float angle_circle = glm::radians(static_cast<float>(circle * circle_slice_ratio));
				float next_angle_circle = glm::radians(static_cast<float>((circle + 1) * circle_slice_ratio));

				glm::vec3 vertex1 = {
					(outer_radius + inner_radius * glm::cos(angle_circle)) * glm::cos(angle_torus),
					(outer_radius + inner_radius * glm::cos(angle_circle)) * glm::sin(angle_torus),
					inner_radius * glm::sin(angle_circle)
				};

				glm::vec3 vertex2 = {
					(outer_radius + inner_radius * glm::cos(angle_circle)) * glm::cos(next_angle_torus),
					(outer_radius + inner_radius * glm::cos(angle_circle)) * glm::sin(next_angle_torus),
					inner_radius * glm::sin(angle_circle)
				};

				glm::vec3 vertex3 = {
					(outer_radius + inner_radius * glm::cos(next_angle_circle)) * glm::cos(angle_torus),
					(outer_radius + inner_radius * glm::cos(next_angle_circle)) * glm::sin(angle_torus),
					inner_radius * glm::sin(next_angle_circle)
				};

				glm::vec3 vertex4 = {
					(outer_radius + inner_radius * glm::cos(next_angle_circle))* glm::cos(next_angle_torus),
					(outer_radius + inner_radius * glm::cos(next_angle_circle))* glm::sin(next_angle_torus),
					inner_radius* glm::sin(next_angle_circle)
				};
				glm::vec3 normal = glm::normalize(glm::cross(vertex1 - vertex2, vertex1 - vertex3));

				float u1 = (static_cast<float>(torus) / torus_slices) * texScaleU;
				float u2 = (static_cast<float>(torus + 1) / torus_slices) * texScaleU;
				float v1 = (static_cast<float>(circle) / circle_slices) * texScaleV;
				float v2 = (static_cast<float>(circle + 1) / circle_slices) * texScaleV;

				glm::vec2 uv1(u1, v1);
				glm::vec2 uv2(u1, v2);
				glm::vec2 uv3(u2, v1);
				glm::vec2 uv4(u2, v2);

				vertices.push_back({ vertex1, normal, uv1 });
				vertices.push_back({ vertex2, normal, uv2 });
				vertices.push_back({ vertex3, normal, uv3 });

				vertices.push_back({ vertex3, normal, uv3 });
				vertices.push_back({ vertex4, normal, uv4 });
				vertices.push_back({ vertex2, normal, uv2 });
			}
		}

		texScale = 0.5f / (torus_slices * torus_slices);
	}
}
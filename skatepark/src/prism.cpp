#include "prism.h"

namespace OpenGL
{
    Prism::Prism(
        float width_value,
        float height_value,
        float depth_value,
        float apex_value,
        float corner_value,
        glm::vec3 position_value,
        glm::vec3 rotate_value,
        glm::vec3 color_value,
        float scale_value,
        const char* texture,
        float shininess
    ) : Shape(
        position_value,
		rotate_value,
        color_value,
		scale_value,
        texture,
        shininess
    ) {
        glm::vec3 vertice[] = {
            // Front face
            glm::vec3(-width_value, -height_value, depth_value),   // Bottom-left  0
            glm::vec3(width_value, -height_value, depth_value),    // Bottom-right 1
            glm::vec3(corner_value, apex_value,  depth_value),     // Top-left     2

            // Back face
            glm::vec3(-width_value, -height_value, -depth_value),  // Bottom-left  3
            glm::vec3(width_value, -height_value, -depth_value),   // Bottom-right 4
            glm::vec3(corner_value, apex_value, -depth_value)      // Top-right    5
        };

        glm::vec3 normals[] = {
            glm::normalize(glm::cross(vertice[0] - vertice[1], vertice[2] - vertice[1])),
            glm::normalize(glm::cross(vertice[2] - vertice[1], vertice[0] - vertice[1])),
            glm::normalize(glm::cross(vertice[5] - vertice[1], vertice[2] - vertice[1])),
            glm::normalize(glm::cross(vertice[0] - vertice[1], vertice[3] - vertice[1])),
            glm::normalize(glm::cross(vertice[0] - vertice[3], vertice[2] - vertice[3]))
        };

        vertices = {
            // Front
            Format3D(vertice[0], normals[1], glm::vec2(0, 0)), // Bottom-left
            Format3D(vertice[1], normals[1], glm::vec2(1, 0)), // Bottom-right
            Format3D(vertice[2], normals[1], glm::vec2(0.5f, 1)), // Top-left

            // Back
            Format3D(vertice[3], normals[0], glm::vec2(0, 0)), // Bottom-left
            Format3D(vertice[4], normals[0], glm::vec2(1, 0)), // Bottom-right
            Format3D(vertice[5], normals[0], glm::vec2(0.5f, 1)), // Top-right

            // Bottom
            Format3D(vertice[0], normals[3], glm::vec2(0, 0)), // Bottom-left
            Format3D(vertice[1], normals[3], glm::vec2(1, 0)), // Bottom-right
            Format3D(vertice[4], normals[3], glm::vec2(1, 1)), // Top-right
            Format3D(vertice[3], normals[3], glm::vec2(0, 1)), // Top-left

            // Top-Right-Rear
            Format3D(vertice[1], normals[2], glm::vec2(1, 0)), // Bottom-right
            Format3D(vertice[4], normals[2], glm::vec2(1, 1)), // Top-right
            Format3D(vertice[5], normals[2], glm::vec2(0.5f, 1)), // Top-right
            Format3D(vertice[2], normals[2], glm::vec2(0.5f, 0)), // Bottom-left

            // Top-Left-Rear
            Format3D(vertice[3], normals[4], glm::vec2(0, 0)), // Bottom-left
            Format3D(vertice[0], normals[4], glm::vec2(0, 1)), // Top-left
            Format3D(vertice[2], normals[4], glm::vec2(0.5f, 1)), // Top-left
            Format3D(vertice[5], normals[4], glm::vec2(0.5f, 0)) // Bottom-right
        };

        indices = {
            0, 1, 2,              // Front
            4, 3, 5,              // Back            
            6, 7, 8, 8, 9, 6,     // Bottom
            10, 11, 12, 12, 13, 10, // Top-Right-Rear 
            14, 15, 16, 16, 17, 14  // Top-Left-Rear
        };

        texScale = 1.0f / std::max(std::max(width_value, height_value), depth_value);
    }
}

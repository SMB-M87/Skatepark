#include "cuboid.h"

namespace OpenGL
{
    Cuboid::Cuboid(
        glm::vec3 front_top_left,
        glm::vec3 front_top_right,
        glm::vec3 back_top_left,
        glm::vec3 back_top_right,
        glm::vec3 front_bottom_left,
        glm::vec3 front_bottom_right,
        glm::vec3 back_bottom_left,
        glm::vec3 back_bottom_right,
        glm::vec3 position_value,
        glm::vec3 rotate_value,
        glm::vec3 color_value,
        float scale_value,
        const char* texture,
        const char* vertex,
        const char* fragment,
        float shininess,
        bool shading
    ) : Shape(
        position_value,
        rotate_value,
        color_value,
        scale_value,
        texture,
        shininess,
        shading,
        vertex,
        fragment
    ) {
        glm::vec3 normals[] = {
            glm::normalize(glm::cross(front_top_left - front_bottom_left, front_top_left - front_top_right)),
            glm::normalize(glm::cross(back_top_right - back_bottom_left, back_bottom_right - back_bottom_left)),
            glm::normalize(glm::cross(front_top_right - front_bottom_right, front_top_right - back_top_right)),
            glm::normalize(glm::cross(front_top_left - back_top_left, front_top_left - front_bottom_left)),
            glm::normalize(glm::cross(front_top_left - back_top_left, front_top_right - back_top_left)),
            glm::normalize(glm::cross(front_bottom_left - back_bottom_left, front_bottom_left - front_bottom_right))
        };

        vertices = {
            Format3D(front_bottom_left, normals[0], glm::vec2(0, 0)),
            Format3D(front_bottom_right, normals[0], glm::vec2(1, 0)),
            Format3D(front_top_right, normals[0], glm::vec2(1, 1)),
            Format3D(front_top_left, normals[0], glm::vec2(0, 1)),

            Format3D(back_bottom_right, normals[1], glm::vec2(0, 0)),
            Format3D(back_bottom_left, normals[1], glm::vec2(1, 0)),
            Format3D(back_top_left, normals[1], glm::vec2(1, 1)),
            Format3D(back_top_right, normals[1], glm::vec2(0, 1)),

            Format3D(front_bottom_right, normals[2], glm::vec2(0, 0)),
            Format3D(back_bottom_right, normals[2], glm::vec2(1, 0)),
            Format3D(back_top_right, normals[2], glm::vec2(1, 1)),
            Format3D(front_top_right, normals[2], glm::vec2(0, 1)),

            Format3D(back_bottom_left, normals[3], glm::vec2(0, 0)),
            Format3D(front_bottom_left, normals[3], glm::vec2(1, 0)),
            Format3D(front_top_left, normals[3], glm::vec2(1, 1)),
            Format3D(back_top_left, normals[3], glm::vec2(0, 1)),

            Format3D(front_top_left, normals[4], glm::vec2(0, 0)),
            Format3D(front_top_right, normals[4], glm::vec2(1, 0)),
            Format3D(back_top_right, normals[4], glm::vec2(1, 1)),
            Format3D(back_top_left, normals[4], glm::vec2(0, 1)),

            Format3D(front_bottom_right, normals[5], glm::vec2(0, 0)),
            Format3D(front_bottom_left, normals[5], glm::vec2(1, 0)),
            Format3D(back_bottom_left, normals[5], glm::vec2(1, 1)),
            Format3D(back_bottom_right, normals[5], glm::vec2(0, 1))
        };

        indices = {
            0, 1, 2, 2, 3, 0, // Front
            4, 5, 6, 6, 7, 4, // Back
            8, 9, 10, 10, 11, 8, // Right
            12, 13, 14, 14, 15, 12, // Left
            16, 17, 18, 18, 19, 16, // Top
            20, 21, 22, 22, 23, 20  // Bottom
        };

        texScale = 1.0f / std::max(std::max(front_top_left.x - front_top_right.x, front_top_left.y - front_bottom_left.y), front_top_left.z - back_top_left.z);
    }
}
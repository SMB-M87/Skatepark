#include "polygon.h"

namespace OpenGL
{
    Polygon::Polygon(
        float width,
        float height,
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
            glm::vec3(-width, -height, 1.0f),
            glm::vec3(width, -height, 1.0f),
            glm::vec3(width, height, 1.0f),
            glm::vec3(-width, height, 1.0f)
        };

        glm::vec3 normals[] = {
            glm::normalize(glm::cross(vertice[2] - vertice[0], vertice[1] - vertice[0]))
        };

        glm::vec2 uvs[] = {
            glm::vec2(0, 0),
            glm::vec2(1, 0),
            glm::vec2(1, 1),
            glm::vec2(0, 1)
        };

        vertices = {
            Format3D(vertice[0], normals[0], uvs[0]),
            Format3D(vertice[1], normals[0], uvs[1]),
            Format3D(vertice[2], normals[0], uvs[2]),
            Format3D(vertice[3], normals[0], uvs[3])
        };

        indices = {
            0, 1, 2, 2, 3, 0
        };

        texScale = 1.0f / std::max(vertice[0].x - vertice[2].x, vertice[1].y - vertice[3].y);
    }
}
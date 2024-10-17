#ifndef CUBOID_H
#define CUBOID_H

#include "shape.h"

namespace OpenGL
{
    class Cuboid : public Shape{
    public:
        Cuboid(
            glm::vec3 front_top_left = { -1.0f, 1.0f, 1.0f },
            glm::vec3 front_top_right = { 1.0f, 1.0f, 1.0f },
            glm::vec3 back_top_left = { -1.0f,  1.0f, -1.0f },
            glm::vec3 back_top_right = { 1.0f,  1.0f, -1.0f },
            glm::vec3 front_bottom_left = { -1.0f, -1.0f,  1.0f },
            glm::vec3 front_bottom_right = { 1.0f, -1.0f,  1.0f },
            glm::vec3 back_bottom_left = { -1.0f, -1.0f, -1.0f },
            glm::vec3 back_bottom_right = { 1.0f, -1.0f, -1.0f },
            glm::vec3 position_value = { -1.0f, 2.0f, 30.0f },
            glm::vec3 rotate_value = { 0.0f, 0.0f, 0.0f },
            glm::vec3 color_value = { 0.5f, 0.5f, 0.5f },
            float scale_value = 1.0f,
            const char* texture = "empty",
            const char* vertex = "resource/shader/shader.vert",
            const char* fragment = "resource/shader/shader.frag",
            float shininess = 1.0f,
            bool shading = true
        );
    };
}
#endif
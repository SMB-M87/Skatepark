#ifndef PRISM_H
#define PRISM_H

#include "shape.h"

namespace OpenGL
{
    class Prism : public Shape {
    public:
        Prism(
            float width_value = 1.0f,
            float height_value = 1.0f,
            float depth_value = 1.0f,
            float apex_value = 0.0f,
            float corner_value = -1.0f,
            glm::vec3 position_value = { 2.0f, 2.0f, 30.0f },
            glm::vec3 rotate_value = { 0.0f, 0.0f, 0.0f },
            glm::vec3 color_value = { 0.5f, 0.5f, 0.5f },
            float scale_value = 1.0f,
            const char* texture = "empty",
            float shininess = 1.0f
        );
    };
}
#endif
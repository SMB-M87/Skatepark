#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"

namespace OpenGL
{
    class Polygon : public Shape {
    public:
        Polygon(
            float width,
            float height,
            glm::vec3 position_value = { 0.0f, 0.0f, 0.0f },
            glm::vec3 rotate_value = { 0.0f, 0.0f, 0.0f },
            glm::vec3 color_value = { 0.5f, 0.5f, 0.5f },
            float scale_value = 1.0f,
            const char* texture = "empty",
            float shininess = 1.0f
        );
    };
}
#endif
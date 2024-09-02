#ifndef CYLINDER_H
#define CYLINDER_H

#include "shape.h"

namespace OpenGL
{
    class Cylinder : public Shape {
    private:
        bool hollow;
        int circle_degrees, circle_slices;
        float circle_slice_ratio, radius, height, half_height;

    public:
        Cylinder(
            bool hollow_value = false,
            int circle_degrees_value = 360,
            int circle_slices_value = 36,
            float radius_value = 1.0f,
            float height_value = 2.0f,
            glm::vec3 position_value = { -4.0f, 2.0f, 30.0f },
            glm::vec3 rotate_value = { 0.0f, 0.0f, 0.0f },
            glm::vec3 color_value = { 0.5f, 0.5f, 0.5f },
            float scale_value = 1.0f,
            const char* texture = "empty",
            float shininess = 1.0f
        );
    };
}
#endif
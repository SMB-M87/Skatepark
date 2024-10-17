#ifndef TORUS_H
#define TORUS_H

#include "shape.h"

namespace OpenGL
{
    class Torus : public Shape {
    private:
        int torus_degrees, torus_slices, circle_degrees, circle_slices;
        float torus_slice_ratio, circle_slice_ratio, outer_radius, inner_radius;
        glm::vec3 center;

    public:
        Torus(
            int torus_degrees_value = 360,
            int torus_slices_value = 36,
            int circle_degree_value = 360,
            int circle_slices_value = 36,
            float outer_radius_value = 1.0f,
            float inner_radius_value = 0.5f,
            glm::vec3 center_value = { 0.0f, 0.0f, 0.0f },
            glm::vec3 position_value = { -10.0f, 2.0f, 30.0f },
            glm::vec3 rotate_value = { 0.0f, 0.0f, 0.0f },
            glm::vec3 color_value = { 0.5f, 0.5f, 0.5f },
            float scale_value = 1.0f,
            const char* texture = "empty",
            float shininess = 1.0f
        );
    };
}
#endif
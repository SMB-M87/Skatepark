#ifndef SPHERE_H
#define SPHERE_H

#include "shape.h"

namespace OpenGL
{
    class Sphere : public Shape {
    private:
        bool cap;
        int sphere_degrees, sphere_slices, circle_degrees, circle_slices;
        float sphere_slice_ratio, circle_slice_ratio;
        glm::vec3 center;

    public:
        Sphere(
            bool cap_value = false,
            int sphere_degrees_value = 180,
            int sphere_slices_value = 36,
            int circle_degrees_value = 360,
            int circle_slices_value = 36,
            glm::vec3 center_value = { 0.0f, 0.0f, 0.0f },
            glm::vec3 position_value = { -7.0f, 2.0f, 30.0f },
            glm::vec3 rotate_value = { 0.0f, 0.0f, 0.0f },
            glm::vec3 color_value = { 0.5f, 0.5f, 0.5f },
            float scale_value = 1.0f,
            const char* texture = "empty",
            float shininess = 1.0f,
            bool shading = true
        );
    };
}
#endif
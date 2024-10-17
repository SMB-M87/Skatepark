#ifndef SKATEBOARD_H
#define SKATEBOARD_H

#include "shape.h"
#include "loader.h"

namespace OpenGL
{
    class Skateboard : public Shape {
    protected:
        vector<glm::vec3> loaded_vertices;
        vector<glm::vec2> loaded_uvs;
        vector<glm::vec3> loaded_normals;

    public:
        Skateboard(
            glm::vec3 position_value = { 5.0f, 2.0f, 30.0f },
            glm::vec3 rotate_value = { 0.0f, 0.0f, 0.0f },
            glm::vec3 color_value = { 0.5f, 0.5f, 0.5f },
            float scale_value = 1.0f,
            const char* texture = "empty",
            float shininess = 1.0f
        );
    };
}
#endif
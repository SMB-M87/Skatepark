#include "skateboard.h"

namespace OpenGL
{
    Skateboard::Skateboard(
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
        bool res = Loader::Object("resource/object/skateboard.obj", loaded_vertices, loaded_uvs, loaded_normals);

        for (size_t i = 0; i < loaded_vertices.size(); ++i) {
            vertices.push_back(Format3D(loaded_vertices[i], loaded_normals[i]));
        }

        // Indices
        for (size_t i = 0; i < loaded_vertices.size(); ++i) {
            indices.push_back(static_cast<GLushort>(i));
        }
    }
}
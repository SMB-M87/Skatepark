#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include "loader.h"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "glsl.h"

namespace OpenGL
{
    const GLuint ZERO_ID{ 0 };

    struct Format3D
    {
        glm::vec3 position;
        glm::vec3 normals;
        glm::vec2 uvs;

        Format3D(glm::vec3 pos, glm::vec3 normal)
        {
            position = pos;
            normals = normal;
        }

        Format3D(glm::vec3 pos, glm::vec3 normal, glm::vec2 uv)
        {
            position = pos;
            normals = normal;
            uvs = uv;
        }
    };

    class Shape {
    protected:
        const char* TEXTURE;
        const char* VERTEX;
        const char* FRAGMENT;

        GLuint ID, VBO, IBO, VAO, TEX;
        vector<Format3D> vertices;
        vector<GLushort> indices;
        glm::mat4 projection, view, model;
        glm::vec3 origin_position, origin_rotate;
        float origin_scale, texScale, shininess;
        bool shading;

        void InitShader();
        void InitVBO();
        void InitIBO();
        void InitVAO();

    public:
        glm::vec3 position, rotate, color;
        float scale;

        Shape(
            glm::vec3 position_value = { 0.0f, 0.0f, 0.0f },
            glm::vec3 rotate_value = { 0.0f, 0.0f, 0.0f },
            glm::vec3 color_value = { 0.5f, 0.5f, 0.5f },
            float scale_value = 0.3f,
            const char* texture = "empty",
            float shininess = 1.0f,
            bool shading = true,
            const char* vertex = "shader.vert",
            const char* fragment = "shader.frag"
        );
        virtual ~Shape();

        virtual void Init();
        virtual void Update(glm::mat4 projection_matrix, glm::mat4 view_matrix);
        virtual void Reset();
        virtual void Render(glm::vec3 camera, glm::vec3 sun);
    };
}
#endif
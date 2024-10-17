#include "skybox.h"
#include <iostream>

namespace OpenGL
{
    Skybox::Skybox(
        const char* rightTexture,
        const char* leftTexture,
        const char* topTexture,
        const char* bottomTexture,
        const char* frontTexture,
        const char* backTexture
    ) : Cuboid(
        glm::vec3(-100.0f, 100.0f, 100.0f),
        glm::vec3(100.0f, 100.0f, 100.0f),
        glm::vec3(-100.0f, 100.0f, -100.0f),
        glm::vec3(100.0f, 100.0f, -100.0f),
        glm::vec3(-100.0f, -100.0f, 100.0f),
        glm::vec3(100.0f, -100.0f, 100.0f),
        glm::vec3(-100.0f, -100.0f, -100.0f),
        glm::vec3(100.0f, -100.0f, -100.0f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.5f, 0.5f, 0.5f),
        1.0f,
        "empty",
        "resource/shader/skybox.vert",
        "resource/shader/skybox.frag"
    ) {
        images = { rightTexture, leftTexture, topTexture, bottomTexture, frontTexture, backTexture };
        texScale = 1.0f;
    }

    void Skybox::InitCubemap() {
        TEX = Loader::BMPCube(images);
    }

    void Skybox::Render(glm::vec3 camera, glm::vec3 sun) {
        glCullFace(GL_FRONT);
        glDepthFunc(GL_LEQUAL);
        glUseProgram(ID);

        glBindVertexArray(VAO);
        glm::mat4 skyboxView = view;
        skyboxView[3] = glm::vec4(0.0f, 0.0f, 0.0f, skyboxView[3].w);
        glUniformMatrix4fv(glGetUniformLocation(ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(glGetUniformLocation(ID, "view"), 1, GL_FALSE, glm::value_ptr(skyboxView));

        if (TEX != 0) {
            glUniform1i(glGetUniformLocation(ID, "texture"), 0);
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_CUBE_MAP, TEX);
        }

        if (!indices.empty())
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
            glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_SHORT, 0);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }
        else
            glDrawArrays(GL_TRIANGLES, 0, vertices.size());

        glBindVertexArray(0);
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        if (TEX != 0)
            glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
        if (!indices.empty())
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glUseProgram(ZERO_ID);
        glCullFace(GL_BACK);
        glDepthFunc(GL_LESS);
    }
}
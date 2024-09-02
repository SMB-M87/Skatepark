#ifndef SKATEPARK_H
#define SKATEPARK_H

#include "bowl.h"
#include "prism.h"
#include "speed_bump.h"

namespace OpenGL
{
    class Skatepark : public Shape {
    private:
        OpenGL::Bowl bowl;
        OpenGL::SpeedBump bump;
        vector<OpenGL::Shape> shapes;

    public:
        Skatepark(
            glm::vec3 position_value = { 0.0f, 0.0f, 0.0f },
            glm::vec3 rotate_value = { 0.0f, 0.0f, 0.0f },
            glm::vec3 color_value = { 0.5f, 0.5f, 0.5f },
            float scale_value = 1.0f
        );

        virtual void Init() override;
        virtual void Update(glm::mat4 projection_matrix, glm::mat4 view_matrix) override;
        virtual void Render(glm::vec3 camera, glm::vec3 sun) override;
    };
}
#endif
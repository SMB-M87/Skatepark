#ifndef BOWL_H
#define BOWL_H

#include "torus.h"
#include "sphere.h"
#include "polygon.h"
#include "cuboid.h"
#include "cylinder.h"

namespace OpenGL
{
    class Bowl : public Shape {
    private:
        vector<OpenGL::Shape> shapes;

    public:
        Bowl(
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
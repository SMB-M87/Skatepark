#ifndef SKYBOX_H
#define SKYBOX_H

#include "cuboid.h"

namespace OpenGL
{
    class Skybox : public Cuboid {
    private:
        std::vector<const char*> images;
    public:
        Skybox(
            const char* rightTexture = "Texture/Skybox/right.bmp",
            const char* leftTexture = "Texture/Skybox/left.bmp",
            const char* topTexture = "Texture/Skybox/top.bmp",
            const char* bottomTexture = "Texture/Skybox/bottom.bmp",
            const char* frontTexture = "Texture/Skybox/front.bmp",
            const char* backTexture = "Texture/Skybox/back.bmp"
        );
        void InitCubemap();
        virtual void Render(glm::vec3 camera, glm::vec3 sun) override;
    };
}
#endif
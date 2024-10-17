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
            const char* rightTexture = "resource/texture/right.bmp",
            const char* leftTexture = "resource/texture/left.bmp",
            const char* topTexture = "resource/texture/top.bmp",
            const char* bottomTexture = "resource/texture/bottom.bmp",
            const char* frontTexture = "resource/texture/front.bmp",
            const char* backTexture = "resource/texture/back.bmp"
        );
        void InitCubemap();
        virtual void Render(glm::vec3 camera, glm::vec3 sun) override;
    };
}
#endif
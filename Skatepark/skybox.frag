#version 460 core
#extension GL_NV_shadow_samplers_cube : enable

in vec3 o_TexCoord;

uniform samplerCube texture;

out vec4 o_FragColor;

void main() {
    o_FragColor = textureCube(texture, o_TexCoord);
}
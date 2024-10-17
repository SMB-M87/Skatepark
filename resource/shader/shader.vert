#version 330 core

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;
uniform vec3 color;

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 uv;

out vec3 o_Pos;
out vec3 o_Normal;
out vec2 o_Texture;
out vec3 o_Color;

void main() {
    vec4 viewModelPos = model * vec4(position, 1.0);

    o_Pos = viewModelPos.xyz;
    o_Normal = normalize(mat3(model) * normal);
    o_Texture = uv;
    o_Color = color;

    gl_Position = projection * view * viewModelPos;
}
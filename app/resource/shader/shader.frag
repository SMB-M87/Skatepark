#version 330 core

in vec3 o_Pos;
in vec3 o_Normal;
in vec2 o_Texture;
in vec3 o_Color;

uniform vec3 sun;
uniform vec3 camera;
uniform sampler2D texture;
uniform bool hasTexture;
uniform vec2 texScale;
uniform float shininess;
uniform int shading;

out vec3 o_FragColor;

void main() {
    vec3 viewDir = normalize(camera - o_Pos);
    vec3 lightDir = normalize(sun - o_Pos);
    vec3 reflectDir = reflect(-lightDir, o_Normal);
    float distance = length(camera - o_Pos);

    vec4 texColor = vec4(1.0);
    if (hasTexture) {
        vec2 scaledTexCoord = o_Texture * (1.0f / texScale); 
        texColor = texture2D(texture, scaledTexCoord);
    }

    if (shading == 1) {
        float diffuse = dot(o_Normal, lightDir);
        float specular = pow(max(dot(viewDir, reflectDir), 0.0f), clamp(shininess, 1.0f, 128.0f)) * (shininess < 64.0f ? 0.01 : 3.0f);
        float attenuation = 1.0 / (1.0 + distance * distance * 0.01);
        o_FragColor = (diffuse + specular * attenuation) * (hasTexture ? texColor.rgb : o_Color);
    } else {
        o_FragColor = (hasTexture ? texColor.rgb : o_Color);
    }
}
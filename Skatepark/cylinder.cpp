#include "cylinder.h"

namespace OpenGL
{
    Cylinder::Cylinder(
        bool hollow_value,
        int circle_degrees_value,
        int circle_slices_value,
        float radius_value,
        float height_value,
        glm::vec3 position_value,
        glm::vec3 rotate_value,
        glm::vec3 color_value,
        float scale_value,
        const char* texture,
        float shininess
    ) : hollow(hollow_value), 
        circle_degrees(circle_degrees_value > 2 && circle_degrees_value <= 360 ? circle_degrees_value : 360),
        circle_slices(circle_slices_value > 2 && circle_slices_value <= circle_degrees && ((360 % circle_slices_value) == 0) ? circle_slices_value : 36),
        circle_slice_ratio(circle_degrees / static_cast<float>(circle_slices)),
        radius(radius_value),
        height(height_value),
        half_height(height_value / 2.0f),
        Shape(
            position_value,
            rotate_value,
            color_value,
            scale_value,
            texture,
            shininess
    ) {
        texScale = 0.25f / std::max(radius * 2.0f, height);

        for (int circle = 0; circle < circle_slices; circle++)
        {
            float angle = glm::radians(static_cast<float>(circle * circle_slice_ratio));
            float next_angle = glm::radians(static_cast<float>((circle + 1) * circle_slice_ratio));

            glm::vec3 vertex1(glm::cos(angle) * radius, glm::sin(angle) * radius, -half_height);
            glm::vec3 vertex2(glm::cos(angle) * radius, glm::sin(angle) * radius, half_height);
            glm::vec3 vertex3(glm::cos(next_angle) * radius, glm::sin(next_angle) * radius, half_height);
            glm::vec3 vertex4(glm::cos(next_angle) * radius, glm::sin(next_angle) * radius, -half_height);
            glm::vec3 normal1 = glm::normalize(hollow ? glm::cross(vertex1 - vertex2, vertex1 - vertex3) : glm::cross(vertex1 - vertex3, vertex1 - vertex2));
            glm::vec3 normal2 = glm::normalize(hollow ? glm::cross(vertex2 - vertex3, vertex2 - vertex4) : glm::cross(vertex2 - vertex4, vertex2 - vertex3));

            float u = (angle / (2 * glm::pi<float>())) * 2.0f;
            float v = 0.0f;
            glm::vec2 uv1(u * texScale, v * texScale);
            glm::vec2 uv2((u + circle_slice_ratio / (2 * glm::pi<float>())) * 2.0f * texScale, v * texScale);
            glm::vec2 uv3((u + circle_slice_ratio / (2 * glm::pi<float>())) * 2.0f * texScale, 1.0f * texScale);
            glm::vec2 uv4(u * texScale, 1.0f * texScale);

            vertices.push_back(Format3D(vertex1, normal1, uv1));
            vertices.push_back(Format3D(vertex2, normal1, uv2));
            vertices.push_back(Format3D(vertex3, normal1, uv3));

            vertices.push_back(Format3D(vertex3, normal2, uv3));
            vertices.push_back(Format3D(vertex4, normal2, uv4));
            vertices.push_back(Format3D(vertex1, normal2, uv1));

            if (hollow && circle_degrees <= 180) {
                glm::vec3 normals = glm::normalize(glm::cross(vertex2 - vertex1, vertex3 - vertex1));
                float y = glm::dot(normals, glm::vec3(0.0f, 0.0f, 1.0f)) > 0.0f ? -radius : radius;

                glm::vec3 leftSideVertex1(vertex1.x, vertex1.y, -half_height);
                glm::vec3 leftSideVertex2(vertex2.x, y, -half_height);
                glm::vec3 leftSideVertex3(vertex3.x, y, -half_height);
                glm::vec3 leftSideVertex4(vertex4.x, vertex4.y, -half_height);
                glm::vec3 leftNormal = glm::normalize(glm::cross(leftSideVertex1 - leftSideVertex3, leftSideVertex1 - leftSideVertex2));

                float u1 = angle / (2 * glm::pi<float>());
                float u2 = (angle + circle_slice_ratio) / (2 * glm::pi<float>());
                float v = 0.5f;
                glm::vec2 leftUv1(u1 * texScale, v * texScale);
                glm::vec2 leftUv2(u2 * texScale, v * texScale);
                glm::vec2 leftUv3(u2 * texScale, v * texScale);
                glm::vec2 leftUv4(u1 * texScale, v * texScale);

                vertices.push_back(Format3D(leftSideVertex1, leftNormal, leftUv1));
                vertices.push_back(Format3D(leftSideVertex2, leftNormal, leftUv2));
                vertices.push_back(Format3D(leftSideVertex3, leftNormal, leftUv3));

                vertices.push_back(Format3D(leftSideVertex3, leftNormal, leftUv3));
                vertices.push_back(Format3D(leftSideVertex4, leftNormal, leftUv4));
                vertices.push_back(Format3D(leftSideVertex1, leftNormal, leftUv1));

                glm::vec3 rightSideVertex1(vertex1.x, vertex1.y, half_height);
                glm::vec3 rightSideVertex2(vertex2.x, y, half_height);
                glm::vec3 rightSideVertex3(vertex3.x, y, half_height);
                glm::vec3 rightSideVertex4(vertex4.x, vertex4.y, half_height);
                glm::vec3 rightNormal = glm::normalize(glm::cross(rightSideVertex1 - rightSideVertex2, rightSideVertex1 - rightSideVertex3));

                glm::vec2 rightUv1(u1 * texScale, v * texScale);
                glm::vec2 rightUv2(u2 * texScale, v * texScale);
                glm::vec2 rightUv3(u2 * texScale, v * texScale);
                glm::vec2 rightUv4(u1 * texScale, v * texScale);

                vertices.push_back(Format3D(rightSideVertex1, rightNormal, rightUv1));
                vertices.push_back(Format3D(rightSideVertex2, rightNormal, rightUv2));
                vertices.push_back(Format3D(rightSideVertex3, rightNormal, rightUv3));

                vertices.push_back(Format3D(rightSideVertex3, rightNormal, rightUv3));
                vertices.push_back(Format3D(rightSideVertex4, rightNormal, rightUv4));
                vertices.push_back(Format3D(rightSideVertex1, rightNormal, rightUv1));
            }
        }

        if (!hollow)
        {
            for (int circle = 0; circle < circle_slices; circle++)
            {
                float angle = glm::radians(static_cast<float>(circle * circle_slice_ratio));
                float next_angle = glm::radians(static_cast<float>((circle + 1) * circle_slice_ratio));

                glm::vec3 vertex1(glm::cos(angle) * radius, glm::sin(angle) * radius, half_height);
                glm::vec3 vertex2(glm::cos(next_angle) * radius, glm::sin(next_angle) * radius, half_height);
                glm::vec3 vertex3(glm::vec3(0.0f, 0.0f, half_height));
                glm::vec3 normal = glm::vec3(0.0f, 0.0f, 1.0f);

                float u = angle / (2 * glm::pi<float>());
                float v = 0.5f;
                glm::vec2 uv1(u * texScale, v * texScale);
                glm::vec2 uv2((u + circle_slice_ratio / (2 * glm::pi<float>())) * texScale, v * texScale);
                glm::vec2 uv3(0.5f * texScale, v * texScale);

                vertices.push_back(Format3D(vertex1, normal, uv1));
                vertices.push_back(Format3D(vertex2, normal, uv2));
                vertices.push_back(Format3D(vertex3, normal, uv3));

                vertex1 = glm::vec3(glm::cos(angle) * radius, glm::sin(angle) * radius, -half_height);
                vertex2 = glm::vec3(glm::cos(next_angle) * radius, glm::sin(next_angle) * radius, -half_height);
                vertex3 = glm::vec3(0.0f, 0.0f, -half_height);
                normal = glm::vec3(0.0f, 0.0f, -1.0f);

                vertices.push_back(Format3D(vertex1, normal, uv1));
                vertices.push_back(Format3D(vertex2, normal, uv2));
                vertices.push_back(Format3D(vertex3, normal, uv3));
            }
        }
    }
}
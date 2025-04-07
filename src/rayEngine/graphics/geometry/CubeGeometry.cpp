#include "CubeGeometry.h"
#include <iostream>

namespace Engine {

CubeGeometry::CubeGeometry(float width, float height, float depth)
    : Geometry({}, {}) {

    float w = width * 0.5f;
    float h = height * 0.5f;
    float d = depth * 0.5f;

    vertices = {
        // Front face
        Vertex(glm::vec3(-w, -h, d), glm::vec3(0, 0, 1), glm::vec2(0.0f, 0.0f)),
        Vertex(glm::vec3( w, -h, d), glm::vec3(0, 0, 1), glm::vec2(1.0f, 0.0f)),
        Vertex(glm::vec3( w,  h, d), glm::vec3(0, 0, 1), glm::vec2(1.0f, 1.0f)),
        Vertex(glm::vec3(-w,  h, d), glm::vec3(0, 0, 1), glm::vec2(0.0f, 1.0f)),

        // Back face
        Vertex(glm::vec3( w, -h, -d), glm::vec3(0, 0, -1), glm::vec2(0.0f, 0.0f)),
        Vertex(glm::vec3(-w, -h, -d), glm::vec3(0, 0, -1), glm::vec2(1.0f, 0.0f)),
        Vertex(glm::vec3(-w,  h, -d), glm::vec3(0, 0, -1), glm::vec2(1.0f, 1.0f)),
        Vertex(glm::vec3( w,  h, -d), glm::vec3(0, 0, -1), glm::vec2(0.0f, 1.0f)),

        // Left face
        Vertex(glm::vec3(-w, -h, -d), glm::vec3(-1, 0, 0), glm::vec2(0.0f, 0.0f)),
        Vertex(glm::vec3(-w, -h,  d), glm::vec3(-1, 0, 0), glm::vec2(1.0f, 0.0f)),
        Vertex(glm::vec3(-w,  h,  d), glm::vec3(-1, 0, 0), glm::vec2(1.0f, 1.0f)),
        Vertex(glm::vec3(-w,  h, -d), glm::vec3(-1, 0, 0), glm::vec2(0.0f, 1.0f)),

        // Right face
        Vertex(glm::vec3( w, -h,  d), glm::vec3(1, 0, 0), glm::vec2(0.0f, 0.0f)),
        Vertex(glm::vec3( w, -h, -d), glm::vec3(1, 0, 0), glm::vec2(1.0f, 0.0f)),
        Vertex(glm::vec3( w,  h, -d), glm::vec3(1, 0, 0), glm::vec2(1.0f, 1.0f)),
        Vertex(glm::vec3( w,  h,  d), glm::vec3(1, 0, 0), glm::vec2(0.0f, 1.0f)),

        // Top face
        Vertex(glm::vec3(-w,  h,  d), glm::vec3(0, 1, 0), glm::vec2(0.0f, 0.0f)),
        Vertex(glm::vec3( w,  h,  d), glm::vec3(0, 1, 0), glm::vec2(1.0f, 0.0f)),
        Vertex(glm::vec3( w,  h, -d), glm::vec3(0, 1, 0), glm::vec2(1.0f, 1.0f)),
        Vertex(glm::vec3(-w,  h, -d), glm::vec3(0, 1, 0), glm::vec2(0.0f, 1.0f)),

        // Bottom face
        Vertex(glm::vec3(-w, -h, -d), glm::vec3(0, -1, 0), glm::vec2(0.0f, 0.0f)),
        Vertex(glm::vec3( w, -h, -d), glm::vec3(0, -1, 0), glm::vec2(1.0f, 0.0f)),
        Vertex(glm::vec3( w, -h,  d), glm::vec3(0, -1, 0), glm::vec2(1.0f, 1.0f)),
        Vertex(glm::vec3(-w, -h,  d), glm::vec3(0, -1, 0), glm::vec2(0.0f, 1.0f))
    };

    indices = {
        // Front face
        0, 1, 2,
        2, 3, 0,

        // Back face
        4, 5, 6,
        6, 7, 4,

        // Left face
        8, 9, 10,
        10, 11, 8,

        // Right face
        12, 13, 14,
        14, 15, 12,

        // Top face
        16, 17, 18,
        18, 19, 16,

        // Bottom face
        20, 21, 22,
        22, 23, 20
    };

    SetupBuffers();
}

} // namespace Engine

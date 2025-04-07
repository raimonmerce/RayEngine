#include "CylinderGeometry.h"
#include <iostream>
#include <cmath>

namespace Engine {

CylinderGeometry::CylinderGeometry(float radius, float height, unsigned int sectors, bool openEnded)
    : Geometry({}, {}) {

    float halfHeight = height * 0.5f;

    // Generate vertices for the sides
    for (unsigned int i = 0; i <= sectors; ++i) {
        float angle = 2.0f * M_PI * static_cast<float>(i) / static_cast<float>(sectors);
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        // Bottom vertex
        vertices.emplace_back(glm::vec3(x, -halfHeight, z), glm::vec3(x, 0.0f, z), glm::vec2(static_cast<float>(i) / static_cast<float>(sectors), 0.0f));

        // Top vertex
        vertices.emplace_back(glm::vec3(x, halfHeight, z), glm::vec3(x, 0.0f, z), glm::vec2(static_cast<float>(i) / static_cast<float>(sectors), 1.0f));
    }

    // Generate indices for the sides
    for (unsigned int i = 0; i < sectors; ++i) {
        unsigned int next = i + 1;

        // First triangle
        indices.push_back(2 * i);
        indices.push_back(2 * i + 1);
        indices.push_back(2 * next);

        // Second triangle
        indices.push_back(2 * next);
        indices.push_back(2 * i + 1);
        indices.push_back(2 * next + 1);
    }

    if (!openEnded) {
        // Generate vertices and indices for the bottom cap
        unsigned int centerIndex = vertices.size();
        vertices.emplace_back(glm::vec3(0.0f, -halfHeight, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0.5f, 0.5f));
        for (unsigned int i = 0; i <= sectors; ++i) {
            float angle = 2.0f * M_PI * static_cast<float>(i) / static_cast<float>(sectors);
            float x = radius * cos(angle);
            float z = radius * sin(angle);
            vertices.emplace_back(glm::vec3(x, -halfHeight, z), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0.5f + 0.5f * cos(angle), 0.5f + 0.5f * sin(angle)));
        }

        for (unsigned int i = 1; i <= sectors; ++i) {
            indices.push_back(centerIndex);
            indices.push_back(centerIndex + i);
            indices.push_back(centerIndex + i + 1);
        }

        // Generate vertices and indices for the top cap
        centerIndex = vertices.size();
        vertices.emplace_back(glm::vec3(0.0f, halfHeight, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.5f, 0.5f));
        for (unsigned int i = 0; i <= sectors; ++i) {
            float angle = 2.0f * M_PI * static_cast<float>(i) / static_cast<float>(sectors);
            float x = radius * cos(angle);
            float z = radius * sin(angle);
            vertices.emplace_back(glm::vec3(x, halfHeight, z), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.5f + 0.5f * cos(angle), 0.5f + 0.5f * sin(angle)));
        }

        for (unsigned int i = 1; i <= sectors; ++i) {
            indices.push_back(centerIndex);
            indices.push_back(centerIndex + i + 1);
            indices.push_back(centerIndex + i);
        }
    }

    SetupBuffers();
}

} // namespace Engine

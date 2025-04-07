#include "ConeGeometry.h"
#include <iostream>
#include <cmath>

namespace Engine {

ConeGeometry::ConeGeometry(float radius, float height, unsigned int sectors)
    : Geometry({}, {}) {

    // Apex vertex
    vertices.emplace_back(glm::vec3(0.0f, height, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.5f, 1.0f));

    // Base vertices
    for (unsigned int i = 0; i <= sectors; ++i) {
        float angle = 2.0f * M_PI * static_cast<float>(i) / static_cast<float>(sectors);
        float x = radius * cos(angle);
        float z = radius * sin(angle);
        vertices.emplace_back(glm::vec3(x, 0.0f, z), glm::vec3(x, 0.0f, z), glm::vec2(0.5f + 0.5f * cos(angle), 0.5f + 0.5f * sin(angle)));
    }

    // Center of the base
    unsigned int baseCenterIndex = vertices.size();
    vertices.emplace_back(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0.5f, 0.5f));

    // Indices for the side surface
    for (unsigned int i = 1; i <= sectors; ++i) {
        indices.push_back(0);
        indices.push_back(i);
        indices.push_back(i + 1);
    }

    // Indices for the base
    for (unsigned int i = 1; i <= sectors; ++i) {
        indices.push_back(baseCenterIndex);
        indices.push_back(i + 1);
        indices.push_back(i);
    }

    SetupBuffers();
}

} // namespace Engine

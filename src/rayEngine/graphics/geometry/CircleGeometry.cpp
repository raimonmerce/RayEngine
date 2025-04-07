#include "CircleGeometry.h"
#include <iostream>
#include <cmath>

namespace Engine {

CircleGeometry::CircleGeometry(float radius, unsigned int segments)
    : Geometry({}, {}) {

    // Center vertex
    vertices.emplace_back(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.5f, 0.5f));

    // Perimeter vertices
    for (unsigned int i = 0; i <= segments; ++i) {
        float angle = 2.0f * M_PI * static_cast<float>(i) / static_cast<float>(segments);
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        vertices.emplace_back(glm::vec3(x, y, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.5f + 0.5f * cos(angle), 0.5f + 0.5f * sin(angle)));
    }

    // Indices for triangle fan
    for (unsigned int i = 1; i <= segments; ++i) {
        indices.push_back(0);
        indices.push_back(i);
        indices.push_back(i + 1);
    }

    SetupBuffers();
}

} // namespace Engine

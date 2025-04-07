#include "SphereGeometry.h"
#include <iostream>
#include <cmath>

namespace Engine {

SphereGeometry::SphereGeometry(float radius, unsigned int rings, unsigned int sectors)
    : Geometry({}, {}) {

    // Generate vertices
    for (unsigned int ring = 0; ring <= rings; ++ring) {
        for (unsigned int sector = 0; sector <= sectors; ++sector) {
            float u = static_cast<float>(sector) / static_cast<float>(sectors);
            float v = static_cast<float>(ring) / static_cast<float>(rings);

            float theta = u * 2.0f * M_PI;
            float phi = v * M_PI;

            float x = radius * sin(phi) * cos(theta);
            float y = radius * cos(phi);
            float z = radius * sin(phi) * sin(theta);

            glm::vec3 normal = glm::normalize(glm::vec3(x, y, z));
            vertices.emplace_back(glm::vec3(x, y, z), normal, glm::vec2(u, v));
        }
    }

    // Generate indices
    for (unsigned int ring = 0; ring < rings; ++ring) {
        for (unsigned int sector = 0; sector < sectors; ++sector) {
            unsigned int first = (ring * (sectors + 1)) + sector;
            unsigned int second = first + sectors + 1;

            indices.push_back(first);
            indices.push_back(second);
            indices.push_back(first + 1);

            indices.push_back(second);
            indices.push_back(second + 1);
            indices.push_back(first + 1);
        }
    }

    SetupBuffers();
}

} // namespace Engine

#include "PlaneGeometry.h"
#include "../src/rayEngine/libs/glm/glm.hpp"
#include <iostream>

namespace Engine {

  PlaneGeometry::PlaneGeometry(float width, float height)
      : Geometry({}, {}) {

    std::cout << "Plane Geometry" << std::endl;

    float w = width * 0.5f;
    float h = height * 0.5f;

    vertices = {
      Vertex(glm::vec3(-w, -h, 0.0f), glm::vec3(0, 0, 1), glm::vec2(0.0f, 0.0f)),
      Vertex(glm::vec3( w, -h, 0.0f), glm::vec3(0, 0, 1), glm::vec2(1.0f, 0.0f)),
      Vertex(glm::vec3( w,  h, 0.0f), glm::vec3(0, 0, 1), glm::vec2(1.0f, 1.0f)),
      Vertex(glm::vec3(-w,  h, 0.0f), glm::vec3(0, 0, 1), glm::vec2(0.0f, 1.0f))
    };

    indices = {
      0, 1, 2,
      2, 3, 0
    };

    SetupBuffers();
  }
}

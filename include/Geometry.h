#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>
#include "Vertex.h"  // Define your Vertex struct (position, normal, texCoord, etc.)

namespace Engine {
  class Geometry {
  public:
    Geometry(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
    void Bind() const;
    void Unbind() const;
    int GetIndexCount() const;

  protected:
    void SetupBuffers();
    unsigned int VAO, VBO, EBO;
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
  };
}
#endif
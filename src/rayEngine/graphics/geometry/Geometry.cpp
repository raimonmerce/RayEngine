#include "Geometry.h"
#include <GL/glew.h>
#include <iostream>

namespace Engine {

  Geometry::Geometry(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
      : vertices(vertices), indices(indices) {
        SetupBuffers();
      }

  void Geometry::SetupBuffers() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
  
    glBindVertexArray(VAO);
  
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
  
    // Attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);
  
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
    glEnableVertexAttribArray(1);
  
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoord));
    glEnableVertexAttribArray(2);
  
    glBindVertexArray(0);
  }

  void Geometry::Bind() const {
    glBindVertexArray(VAO);  // Bind the VAO for rendering
  }

  void Geometry::Unbind() const {
    glBindVertexArray(0);  // Unbind the VAO after rendering
  }
}

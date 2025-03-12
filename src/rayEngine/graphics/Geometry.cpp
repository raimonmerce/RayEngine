#include "Geometry.h"
#include <GL/glew.h>
#include <iostream>

namespace Engine {

  Geometry::Geometry(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
      : vertices(vertices), indices(indices) {}

  void Geometry::SetupBuffers() {
    // Generate the VAO, VBO, and EBO
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // Bind the VAO (we'll be configuring the vertex attributes through it)
    glBindVertexArray(VAO);
    // Bind and set the data for the VBO (vertices)
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
    // Set the vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);  // Position
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));  // Normal
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoord));  // TexCoord
    glEnableVertexAttribArray(2);
    // Bind and set the data for the EBO (indices)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
    // Unbind the VAO (to avoid accidental changes to it)
    glBindVertexArray(0);
  }

  void Geometry::Bind() const {
    glBindVertexArray(VAO);  // Bind the VAO for rendering
  }

  void Geometry::Unbind() const {
    glBindVertexArray(0);  // Unbind the VAO after rendering
  }
}

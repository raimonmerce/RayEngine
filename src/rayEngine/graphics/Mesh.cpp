#include "Mesh.h"
#include <GL/glew.h>
#include <iostream>

namespace Engine {

Mesh::Mesh(Geometry* geometry, Material* material)
    : geometry(geometry), material(material) {}

Mesh::~Mesh() {
    // Cleanup: delete geometry and material if owned by this Mesh.
    delete geometry;
    delete material;
}

void Mesh::Draw() const {
    if(material && material->GetShaderProgram() != 0) {
        glUseProgram(material->GetShaderProgram());
    } else {
        std::cerr << "No valid shader program found for the material!" << std::endl;
    }

    GLint colorLocation = glGetUniformLocation(material->GetShaderProgram(), "u_Color");
    if (colorLocation != -1) {
        const glm::vec3& color = material->GetColor(); 
        glUniform3f(colorLocation, color.r, color.g, color.b); // Red color
    } else {
        std::cerr << "ERROR::SHADER::UNIFORM::u_Color NOT FOUND" << std::endl;
    }
    
    if(geometry) {
        geometry->Bind();
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
        geometry->Unbind();
    } else {
        std::cerr << "Geometry is not valid!" << std::endl;
    }
    
    glUseProgram(0);
}

Geometry* Mesh::GetGeometry() const {
    return geometry;
}

Material* Mesh::GetMaterial() const {
    return material;
}

} // namespace Engine

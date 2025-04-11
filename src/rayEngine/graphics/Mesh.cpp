#include "Mesh.h"
#include <GL/glew.h>
#include <iostream>
#include "../src/rayEngine/libs/glm/gtc/type_ptr.hpp" 

namespace Engine {

Mesh::Mesh(Geometry* geometry, Material* material,
    const glm::vec3& position,
    const glm::vec3& rotation,
    const glm::vec3& scale)
 : Object3D(), geometry(geometry), material(material)
{
 // Set transformation properties
 this->position = position;
 this->rotation = rotation;
 this->scale    = scale;
}

Mesh::~Mesh() {
    // Cleanup: delete geometry and material if owned by this Mesh.
    delete geometry;
    delete material;
}

void Mesh::Draw() {
    // std::cout << "Mesh draw" << std::endl;
    if(material && material->GetShaderProgram() != 0) {
        glUseProgram(material->GetShaderProgram());
    } else {
        std::cerr << "No valid shader program found for the material!" << std::endl;
        return;
    }

    material->ApplyUniforms();

    glm::mat4 model = GetWorldMatrix();
    GLint modelLoc = glGetUniformLocation(material->GetShaderProgram(), "u_ModelMatrix");
    if (modelLoc != -1) {
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    } else {
        std::cerr << "ERROR::SHADER::UNIFORM::u_ModelMatrix NOT FOUND" << std::endl;
    }

    GLint colorLocation = glGetUniformLocation(material->GetShaderProgram(), "u_Color");
    if (colorLocation != -1) {
        const glm::vec3& color = material->GetColor();
        glUniform3f(colorLocation, color.r, color.g, color.b);
    } else {
        std::cerr << "ERROR::SHADER::UNIFORM::u_Color NOT FOUND" << std::endl;
    }

    if(geometry) {
        geometry->Bind();
        glDrawElements(GL_TRIANGLES, geometry->GetIndexCount(), GL_UNSIGNED_INT, 0);
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

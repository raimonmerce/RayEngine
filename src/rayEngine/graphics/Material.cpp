#include "Material.h"

namespace Engine {

Material::Material() : shaderProgram(0), color(1.0f, 1.0f, 1.0f) {}

Material::Material(GLuint shaderProgram, const glm::vec3& color) 
    : shaderProgram(shaderProgram), color(color) {}

Material::~Material() {}

GLuint Material::GetShaderProgram() const {
    return shaderProgram;
}

void Material::SetShaderProgram(GLuint shaderProgram) {
    this->shaderProgram = shaderProgram;
}

const glm::vec3& Material::GetColor() const {
    return color;
}

void Material::SetColor(const glm::vec3& color) {
    this->color = color;
}

} // namespace Engine
#ifndef MATERIAL_H
#define MATERIAL_H

#include <GL/glew.h>
#include <variant>
#include <string>
#include <unordered_map>
#include "../src/rayEngine/libs/glm/glm.hpp"

using UniformValue = std::variant<
    int,
    float,
    glm::vec2,
    glm::vec3,
    glm::vec4,
    glm::mat4
>;

namespace Engine {

class Material {
public:
    Material();
    Material(GLuint shaderProgram, const glm::vec3& color);
    ~Material();

    GLuint GetShaderProgram() const;
    void SetShaderProgram(GLuint shaderProgram);

    const glm::vec3& GetColor() const;
    void SetColor(const glm::vec3& color);

    void SetUniformValue(const std::string& name, const UniformValue& value);
    const UniformValue* GetUniformValue(const std::string& name) const;

    void ApplyUniforms() const;

private:
    GLuint shaderProgram;
    glm::vec3 color;
    std::unordered_map<std::string, UniformValue> uniforms;
};

} // namespace Engine

#endif

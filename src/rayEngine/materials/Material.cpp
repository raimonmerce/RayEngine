#include "Material.h"
#include <iostream>
#include "../src/rayEngine/libs/glm/gtc/type_ptr.hpp"

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

    void Material::SetUniformValue(const std::string& name, const UniformValue& value) {
        uniforms[name] = value;
    }

    const UniformValue* Material::GetUniformValue(const std::string& name) const {
        auto it = uniforms.find(name);
        if (it != uniforms.end())
            return &(it->second);
        return nullptr;
    }

    void Material::ApplyUniforms() const {
        // Iterate over the uniform map and set each value based on its type.
        for (const auto& [name, value] : uniforms) {
            GLint location = glGetUniformLocation(shaderProgram, name.c_str());
            if (location == -1) {
                std::cerr << "Warning: uniform \"" << name << "\" not found in shader." << std::endl;
                continue;
            }
            
            // Use std::visit to handle each type variant
            std::visit([location](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, int>) {
                    glUniform1i(location, arg);
                } else if constexpr (std::is_same_v<T, float>) {
                    glUniform1f(location, arg);
                } else if constexpr (std::is_same_v<T, glm::vec2>) {
                    glUniform2fv(location, 1, &arg[0]);
                } else if constexpr (std::is_same_v<T, glm::vec3>) {
                    glUniform3fv(location, 1, &arg[0]);
                } else if constexpr (std::is_same_v<T, glm::vec4>) {
                    glUniform4fv(location, 1, &arg[0]);
                } else if constexpr (std::is_same_v<T, glm::mat4>) {
                    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(arg));
                }
            }, value);
        }
    }

} // namespace Engine
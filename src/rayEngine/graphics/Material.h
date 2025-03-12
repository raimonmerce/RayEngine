#ifndef MATERIAL_H
#define MATERIAL_H

#include <GL/glew.h>
#include "../libs/glm/glm.hpp"

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

private:
    GLuint shaderProgram;
    glm::vec3 color;
};

} // namespace Engine

#endif

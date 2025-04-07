#ifndef SIMPLE_MATERIAL_H
#define SIMPLE_MATERIAL_H

#include "Material.h"
#include "../src/rayEngine/libs/glm/glm.hpp"

namespace Engine {

class SimpleMaterial : public Material {
public:
    SimpleMaterial(const glm::vec3& color);

private:
    GLuint GetShaderProgramID();
};

} // namespace Engine

#endif

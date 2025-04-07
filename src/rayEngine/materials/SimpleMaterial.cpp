#include "SimpleMaterial.h"
#include "ShaderManager.h"

namespace Engine {


    GLuint SimpleMaterial::GetShaderProgramID() {
        static GLuint programID = ShaderManager::LoadShaderProgram("simple_vertex.glsl", "simple_fragment.glsl");
        return programID;
    }
    
    SimpleMaterial::SimpleMaterial(const glm::vec3& color)
        : Material(GetShaderProgramID(), color) {}
    }

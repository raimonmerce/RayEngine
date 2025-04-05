#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H

#include <string>
#include <GL/glew.h>

namespace Engine {

class ShaderManager {
public:
    static GLuint LoadShaderProgram(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
};

} // namespace Engine

#endif

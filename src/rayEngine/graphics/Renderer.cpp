#include "Renderer.h"
#include "Material.h"
#include "Mesh.h"
#include "../scene/SceneManager.h"
#include "../src/rayEngine/libs/glm/gtc/type_ptr.hpp" 
#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>

namespace Engine {
    void Renderer::Render() {
        glClear(GL_COLOR_BUFFER_BIT);
        const Scene* currentScene = SceneManager::GetCurrentScene();
        Camera* camera = currentScene->GetCamera();
        glm::mat4 view = camera->GetViewMatrix();
        glm::mat4 proj = camera->GetProjectionMatrix();
        glm::mat4 viewProj = proj * view;

        const auto& objects = currentScene->getObjects();
        for (auto obj : objects) {
            if (Engine::Mesh* mesh = dynamic_cast<Engine::Mesh*>(obj)) {
                Material* material = mesh->GetMaterial();

                GLuint shaderProgram = material->GetShaderProgram();

                glUseProgram(shaderProgram);

                GLint viewProjLoc = glGetUniformLocation(shaderProgram, "u_ViewProjection");
                if (viewProjLoc != -1) {
                    glUniformMatrix4fv(viewProjLoc, 1, GL_FALSE, glm::value_ptr(viewProj));
                } else {
                    std::cerr << "Warning: uniform \"u_ViewProjection\" not found in shader." << std::endl;
                }
                material->ApplyUniforms();
                mesh->Draw();
            }
            else {
                obj->Draw();
            }
        }
        glutSwapBuffers();
    }
}
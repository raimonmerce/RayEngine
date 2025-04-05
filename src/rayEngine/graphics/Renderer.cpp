#include "Renderer.h"
#include "../scene/SceneManager.h"
#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>

namespace Engine {
void Renderer::Render() {
    glClear(GL_COLOR_BUFFER_BIT);
    std::cout << "Rendering frame" << std::endl;
    const Scene* currentScene = SceneManager::GetCurrentScene();
    const auto& objects = currentScene->getMeshes();
    for (auto obj : objects) {
        obj->Draw();
    }

    // const auto& objects = SceneManager::GetSceneObjects();
    // for (auto obj : objects) {
    //     obj->Draw();
    // }

    glutSwapBuffers();
}
}  // namespace Engine
#include "Renderer.h"
#include "../scene/SceneManager.h"
#include <GL/glew.h>
#include <GL/glut.h>

namespace Engine {
void Renderer::Render() {
    glClear(GL_COLOR_BUFFER_BIT);

    const auto& objects = SceneManager::GetSceneObjects();
    for (auto obj : objects) {
        obj->Draw();
    }

    glutSwapBuffers();
}
}  // namespace Engine
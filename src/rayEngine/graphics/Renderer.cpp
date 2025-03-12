#include "Renderer.h"
#include "../scene/SceneManager.h"
#include <GL/glew.h>
#include <GL/glut.h>

namespace Engine {
void Renderer::Render() {
    glClear(GL_COLOR_BUFFER_BIT);

    const auto& objects = SceneManager::GetSceneObjects();
    for (auto obj : objects) {
        obj->Bind();
        // Draw the object using indices (assuming triangles)
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
        obj->Unbind();
    }

    glutSwapBuffers();
}
}  // namespace Engine
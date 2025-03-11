#include "Renderer.h"

#include <GL/glut.h>

namespace Engine {
void Renderer::Render() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex2f(-0.5, -0.5);
    glColor3f(0, 1, 0);
    glVertex2f(0.5, -0.5);
    glColor3f(0, 0, 1);
    glVertex2f(0, 0.5);
    glEnd();

    glutSwapBuffers();
}
}  // namespace Engine
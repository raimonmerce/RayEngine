#include "RayEngine.h"
#include "Game.h"
#include "Scene.h"
#include "Mesh.h"
#include "Material.h"
#include "Geometry.h"
#include "Vertex.h"
#include "ShaderManager.h"
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    glVertex3f(-0.6, -0.75, 0.5);
    glColor3f(0, 1, 0);
    glVertex3f(0.6, -0.75, 0);
    glColor3f(0, 0, 1);
    glVertex3f(0, 0.75, 0);
    glEnd();
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);

    Engine::RayEngine engine;
    Game game;

    engine.Init();
    game.Init();

    engine.SetScene(game.CreateInitialScene());
    engine.Run();

    return 0;
}
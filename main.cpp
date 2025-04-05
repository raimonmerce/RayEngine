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

    Engine::Scene* scene1 = new Engine::Scene();

    GLuint shaderProgramID = Engine::ShaderManager::LoadShaderProgram("simple_vertex.glsl", "simple_fragment.glsl");
    
    //First triangle
    Engine::Material* material1 = new Engine::Material(shaderProgramID, glm::vec3(0.0f, 0.0f, 1.0f));
    std::vector<Vertex> vertices1 = {
        Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(0, 0)),
        Vertex(glm::vec3( 0.5f,  0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(1, 0)),
        Vertex(glm::vec3(-0.5f,  0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(0.5, 1))
    };
    std::vector<unsigned int> indices1 = { 0, 1, 2 };
    Engine::Geometry* geometry1 = new Engine::Geometry(vertices1, indices1);
    geometry1->SetupBuffers();
    Engine::Mesh* mesh1 = new Engine::Mesh(geometry1, material1);
    scene1->add(mesh1);

    //Second triangle
    Engine::Material* material2 = new Engine::Material(shaderProgramID, glm::vec3(0.0f, 1.0f, 1.0f));
    std::vector<Vertex> vertices2 = {
        Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(0, 0)),
        Vertex(glm::vec3( 0.5f,  0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(1, 0)),
        Vertex(glm::vec3( 0.5f, -0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(0.5, 1))
    };
    std::vector<unsigned int> indices2 = { 0, 1, 2 };
    Engine::Geometry* geometry2 = new Engine::Geometry(vertices2, indices2);
    geometry2->SetupBuffers();
    Engine::Mesh* mesh2 = new Engine::Mesh(geometry2, material2);
    scene1->add(mesh2);

    engine.SetScene(scene1);
    engine.Run();

    return 0;
}
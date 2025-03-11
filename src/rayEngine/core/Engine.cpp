#include "Engine.h"
#include "../graphics/Renderer.h"
#include "../scene/SceneManager.h"
#include "../input/InputManager.h"
#include <GL/glut.h>
#include <iostream>

Engine::Engine() {}

Engine::~Engine() {}

void Engine::Init() {
    std::cout << "Initializing Engine..." << std::endl;

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Game Engine");
    glutKeyboardFunc(InputManager::KeyboardHandler);

    // Set up OpenGL settings
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glutDisplayFunc(Render);
    glutIdleFunc(Update);
}

void Engine::Run() {
    std::cout << "Starting Game Loop..." << std::endl;
    glutMainLoop();
}

void Engine::Shutdown() {
    std::cout << "Shutting down engine..." << std::endl;
}

void Engine::Render() {
    Renderer::Render();
}

void Engine::Update() {
    SceneManager::Update();
}

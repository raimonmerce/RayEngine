#include "RayEngine.h"
#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>

#include "../graphics/Renderer.h"
#include "../input/InputManager.h"
#include "../scene/SceneManager.h"

namespace Engine {
    RayEngine::RayEngine() {}

    RayEngine::~RayEngine() {}

    void RayEngine::Init() {
        std::cout << "Initializing RayEngine..." << std::endl;

        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(800, 600);
        glutInitWindowPosition(100, 100);
        glutCreateWindow("Game RayEngine");

        glewExperimental = GL_TRUE;
        if (glewInit() != GLEW_OK) {
            std::cerr << "Failed to initialize GLEW" << std::endl;
            exit(1);
        }
        glutKeyboardFunc(InputManager::KeyboardHandler);

        // Set up OpenGL settings
        glClearColor(1.0, 0.0, 0.0, 1.0);
        SceneManager::LoadScene();
        glutDisplayFunc(Render);
        glutIdleFunc(Update);
    }

    void RayEngine::Run() {
        std::cout << "Starting Game Loop..." << std::endl;
        glutMainLoop();
    }

    void RayEngine::Shutdown() { std::cout << "Shutting down engine..." << std::endl; }

    void RayEngine::Render() { Renderer::Render(); }

    void RayEngine::Update() { SceneManager::Update(); }
}  // namespace Engine
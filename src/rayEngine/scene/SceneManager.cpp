#include "SceneManager.h"
#include "../graphics/Vertex.h"
#include "../libs/glm/glm.hpp"
#include <iostream>

namespace Engine {
    std::vector<Geometry*> SceneManager::sceneObjects;

    void SceneManager::LoadScene() { 
        std::vector<Vertex> vertices = {
            Vertex(glm::vec3(-0.5f, -0.5f, 0.0f),
                   glm::vec3(0.0f,  0.0f, 1.0f),
                   glm::vec2(0.0f, 0.0f)),
            Vertex(glm::vec3(0.5f, -0.5f, 0.0f),
                   glm::vec3(0.0f,  0.0f, 1.0f),
                   glm::vec2(1.0f, 0.0f)),
            Vertex(glm::vec3(0.0f,  0.5f, 0.0f),
                   glm::vec3(0.0f,  0.0f, 1.0f),
                   glm::vec2(0.5f, 1.0f))
        };
        // Indices for the triangle
        std::vector<unsigned int> indices = { 0, 1, 2 };
        Geometry* triangle = new Geometry(vertices, indices);
        triangle->SetupBuffers();
        // Store in scene objects
        sceneObjects.push_back(triangle);
    }

    const std::vector<Geometry*>& SceneManager::GetSceneObjects() {
        return sceneObjects;
    }

    void SceneManager::Update() { 
        std::cout << "Updating Scene..." << std::endl; 
    }
}  // namespace Engine
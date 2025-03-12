#include "SceneManager.h"
#include "../graphics/Vertex.h"
#include "../libs/glm/glm.hpp"
#include "../shaders/ShaderManager.h"
#include <iostream>

namespace Engine {
    std::vector<Mesh*> SceneManager::sceneObjects;

    void SceneManager::LoadScene() { 
        GLuint shaderProgramID = ShaderManager::LoadShaderProgram("simple_vertex.glsl", "simple_fragment.glsl");

        //Primer
        Material* material = new Material(shaderProgramID, glm::vec3(0.0f, 0.0f, 1.0f));
        std::vector<Vertex> vertices = {
            Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(0, 0)),
            Vertex(glm::vec3( 0.5f, 0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(1, 0)),
            Vertex(glm::vec3( -0.5f,  0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(0.5, 1))
        };
        std::vector<unsigned int> indices = { 0, 1, 2 };
        Geometry* geometry = new Geometry(vertices, indices);
        geometry->SetupBuffers();
        Mesh* mesh = new Mesh(geometry, material);

        sceneObjects.push_back(mesh);

        //Segon
        Material* material2 = new Material(shaderProgramID, glm::vec3(0.0f, 1.0f, 0.0f));
        std::vector<Vertex> vertices2 = {
            Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(0, 0)),
            Vertex(glm::vec3( 0.5f, -0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(1, 0)),
            Vertex(glm::vec3( 0.5f,  0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(0.5, 1))
        };
        std::vector<unsigned int> indices2 = { 0, 1, 2 };
        Geometry* geometry2 = new Geometry(vertices2, indices2);
        geometry2->SetupBuffers();
        Mesh* mesh2 = new Mesh(geometry2, material2);

        sceneObjects.push_back(mesh2);
    }

    const std::vector<Mesh*>& SceneManager::GetSceneObjects() {
        return sceneObjects;
    }

    void SceneManager::Update() { 
        //std::cout << "Updating Scene..." << std::endl; 
    }
}  // namespace Engine
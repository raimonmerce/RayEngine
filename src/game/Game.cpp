#include "Game.h"
#include "Mesh.h"
#include "SimpleMaterial.h"
#include "Material.h"
#include "Geometry.h"
#include "PlaneGeometry.h"
#include "Vertex.h"
#include "ShaderManager.h"
#include <iostream>

void Game::Init() {
    std::cout << "Game Initialized!" << std::endl;
}

void Game::Update() {
    std::cout << "Game Updating..." << std::endl;
}

Engine::Scene* Game::CreateInitialScene() {
    std::cout << "Adding Mesh 1" << std::endl;
    auto* scene = new Engine::Scene();
    GLuint shaderProgramID = Engine::ShaderManager::LoadShaderProgram("simple_vertex.glsl", "simple_fragment.glsl");


    auto* material1b = new Engine::SimpleMaterial(glm::vec3(0.0f, 0.0f, 1.0f));
    auto* material1 = new Engine::Material(shaderProgramID, glm::vec3(0.0f, 0.0f, 1.0f));
    
    std::vector<Vertex> vertices1 = {
        Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(0, 0)),
        Vertex(glm::vec3( 0.5f,  0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(1, 0)),
        Vertex(glm::vec3(-0.5f,  0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(0.5, 1))
    };
    auto* geometry1 = new Engine::Geometry(vertices1, {0, 1, 2});
    auto* mesh1 = new Engine::Mesh(geometry1, material1,
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.5f, 1.0f, 1.0f)); 
    
    scene->add(mesh1);
    std::cout << "Adding Mesh 1" << std::endl;
    // Second Mesh

    //auto* material2b = new Engine::SimpleMaterial(glm::vec3(0.0f, 1.0f, 0.0f));
    auto* material2 = new Engine::Material(shaderProgramID, glm::vec3(0.0f, 1.0f, 0.0f));

    auto* geometry2 = new Engine::PlaneGeometry(1,1);
    auto* mesh2 = new Engine::Mesh(geometry2, material2,
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.5f, 0.5f, 0.5f));
    scene->add(mesh2);

    return scene;
}

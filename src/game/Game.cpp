#include "Game.h"
#include "Mesh.h"
#include "Material.h"
#include "Geometry.h"
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
    auto* scene = new Engine::Scene();

    GLuint shaderProgramID = Engine::ShaderManager::LoadShaderProgram("simple_vertex.glsl", "simple_fragment.glsl");

    // First Mesh
    auto* material1 = new Engine::Material(shaderProgramID, glm::vec3(0.0f, 0.0f, 1.0f));
    std::vector<Vertex> vertices1 = {
        Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(0, 0)),
        Vertex(glm::vec3( 0.5f,  0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(1, 0)),
        Vertex(glm::vec3(-0.5f,  0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(0.5, 1))
    };
    auto* geometry1 = new Engine::Geometry(vertices1, {0, 1, 2});
    geometry1->SetupBuffers();
    auto* mesh1 = new Engine::Mesh(geometry1, material1);
    scene->add(mesh1);

    // Second Mesh
    auto* material2 = new Engine::Material(shaderProgramID, glm::vec3(0.0f, 1.0f, 1.0f));
    std::vector<Vertex> vertices2 = {
        Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(0, 0)),
        Vertex(glm::vec3( 0.5f,  0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(1, 0)),
        Vertex(glm::vec3( 0.5f, -0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(0.5, 1))
    };
    auto* geometry2 = new Engine::Geometry(vertices2, {0, 1, 2});
    geometry2->SetupBuffers();
    auto* mesh2 = new Engine::Mesh(geometry2, material2);
    scene->add(mesh2);

    return scene;
}

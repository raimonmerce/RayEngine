#include "Game.h"
#include "Mesh.h"
#include "SimpleMaterial.h"
#include "Material.h"
#include "Geometry.h"
#include "PlaneGeometry.h"
#include "CubeGeometry.h"
#include "CircleGeometry.h"
#include "SphereGeometry.h"
#include "CylinderGeometry.h"
#include "ConeGeometry.h"
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

    // Geometry
    auto* material1 = new Engine::SimpleMaterial(glm::vec3(0.0f, 1.0f, 0.0f));    
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
    
    // Plane
    auto* material2 = new Engine::SimpleMaterial(glm::vec3(0.0f, 0.0f, 1.0f));
    auto* geometry2 = new Engine::PlaneGeometry(1,1);
    auto* mesh2 = new Engine::Mesh(geometry2, material2,
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.5f, 0.5f, 0.5f));
    scene->add(mesh2);

    // Cube
    auto* material3 = new Engine::SimpleMaterial(glm::vec3(1.0f, 1.0f, 0.0f));
    auto* geometry3 = new Engine::CubeGeometry(1,1,1);
    auto* mesh3 = new Engine::Mesh(geometry3, material3,
        glm::vec3(0.5f, 0.5f, 0.0f),
        glm::vec3(45.0f, 45.0f, 45.0f),
        glm::vec3(0.5f, 0.5f, 0.5f));
    scene->add(mesh3);

    // Circle
    auto* material4 = new Engine::SimpleMaterial(glm::vec3(1.0f, 0.0f, 1.0f));
    auto* geometry4 = new Engine::CircleGeometry(0.5f, 12);
    auto* mesh4 = new Engine::Mesh(geometry4, material4,
        glm::vec3(-0.5f, 0.5f, 0.0f),
        glm::vec3(45.0f, 45.0f, 45.0f),
        glm::vec3(0.5f, 0.5f, 0.5f));
    scene->add(mesh4);

    // Sphere 
    auto* material5 = new Engine::SimpleMaterial(glm::vec3(0.0f, 1.0f, 1.0f));
    auto* geometry5 = new Engine::SphereGeometry(0.5f, 12, 12);
    auto* mesh5 = new Engine::Mesh(geometry5, material5,
        glm::vec3(-0.5f, -0.5f, 0.0f),
        glm::vec3(45.0f, 45.0f, 45.0f),
        glm::vec3(0.5f, 0.5f, 0.5f));
    scene->add(mesh5);

    // Cylinder 
    auto* material6 = new Engine::SimpleMaterial(glm::vec3(0.5f, 0.0f, 0.0f));
    auto* geometry6 = new Engine::CylinderGeometry(0.5f, 1, 8, false);
    auto* mesh6 = new Engine::Mesh(geometry6, material6,
        glm::vec3(0.5f, -0.5f, 0.0f),
        glm::vec3(45.0f, 45.0f, 45.0f),
        glm::vec3(0.5f, 0.5f, 0.5f));
    scene->add(mesh6);

    // Cone 
    auto* material7 = new Engine::SimpleMaterial(glm::vec3(0.0f, 0.5f, 0.0f));
    auto* geometry7 = new Engine::ConeGeometry(0.5f, 1, 12);
    auto* mesh7 = new Engine::Mesh(geometry7, material7,
        glm::vec3(0.0f, -0.5f, 0.0f),
        glm::vec3(45.0f, 45.0f, 45.0f),
        glm::vec3(0.5f, 0.5f, 0.5f));
    scene->add(mesh7);

    return scene;
}

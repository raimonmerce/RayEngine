#include "SceneManager.h"
#include "../../../include/Vertex.h"
#include "../libs/glm/glm.hpp"
#include "../../../include/ShaderManager.h"
#include <iostream>
#include <algorithm>

namespace Engine {

// Define static members.
std::vector<Scene*> SceneManager::scenes;
int SceneManager::currentSceneIndex = 0;

Scene* SceneManager::GetCurrentScene() {
    if (scenes.empty()) {
        return nullptr;
    }
    return scenes[currentSceneIndex];
}

void SceneManager::SetCurrentScene(Scene* scene) {
    auto it = std::find(scenes.begin(), scenes.end(), scene);
    if (it != scenes.end()) {
        currentSceneIndex = std::distance(scenes.begin(), it);
    } else {
        scenes.push_back(scene);
        currentSceneIndex = scenes.size() - 1;
    }
}

void SceneManager::Update() {
    std::cout << "Updating frame" << std::endl;
}

void SceneManager::Shutdown() {
    for (Scene* scene : scenes) {
        delete scene;
    }
    scenes.clear();
}

}  // namespace Engine

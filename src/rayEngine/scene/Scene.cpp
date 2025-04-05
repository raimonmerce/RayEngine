#include "Scene.h"
#include <algorithm>

namespace Engine {

    Scene::~Scene() {
        for (Mesh* mesh : meshes) {
            delete mesh;
        }
        meshes.clear();
    }

    void Scene::add(Mesh* mesh) {
        meshes.push_back(mesh);
    }

    void Scene::remove(Mesh* mesh) {
        auto it = std::remove(meshes.begin(), meshes.end(), mesh);
        if (it != meshes.end()) {
            meshes.erase(it, meshes.end());
        }
    }

    const std::vector<Mesh*>& Scene::getMeshes() const {
        return meshes;
    }

}

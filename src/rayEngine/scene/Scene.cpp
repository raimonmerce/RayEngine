#include "Scene.h"
#include <algorithm>

namespace Engine {

    Scene::~Scene() {
        for (Object3D* mesh : objects) {
            delete mesh;
        }
        objects.clear();
    }

    void Scene::add(Object3D* mesh) {
        objects.push_back(mesh);
    }

    void Scene::remove(Object3D* mesh) {
        auto it = std::remove(objects.begin(), objects.end(), mesh);
        if (it != objects.end()) {
            objects.erase(it, objects.end());
        }
    }

    const std::vector<Object3D*>& Scene::getObjects() const {
        return objects;
    }

}

#include "Scene.h"
#include <algorithm>

namespace Engine {

    Scene::~Scene() {
        for (Object3D* mesh : objects) {
            delete mesh;
        }
        objects.clear();
        if (m_Camera) {
            delete m_Camera;
            m_Camera = nullptr;
        }
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

    void Scene::SetCamera(Camera* camera) {
        if (m_Camera) delete m_Camera;
        m_Camera = camera;
    }

    Camera* Scene::GetCamera() const {
        return m_Camera;
    }
}

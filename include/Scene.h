#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Object3D.h"
#include "Camera.h"

namespace Engine {
    class Scene {
    public:
        Scene() = default;
        ~Scene();

        void add(Object3D* mesh);
        void remove(Object3D* mesh);
        const std::vector<Object3D*>& getObjects() const;

        void SetCamera(Camera* camera);
        Camera* GetCamera() const;
    private:
        std::vector<Object3D*> objects;
        Camera* m_Camera = nullptr;
    };
}

#endif

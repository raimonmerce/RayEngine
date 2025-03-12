#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <vector>
#include "../graphics/Geometry.h"
#include "../graphics/Material.h"
#include "../graphics/Mesh.h"

namespace Engine {
class SceneManager {
    public:
        static void LoadScene();
        static void Update();
        static const std::vector<Mesh*>& GetSceneObjects();

    private:
        static std::vector<Mesh*> sceneObjects;
};
}  // namespace Engine

#endif

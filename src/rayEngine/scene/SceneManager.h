#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <vector>
#include "../graphics/Geometry.h"

namespace Engine {
class SceneManager {
    public:
        static void LoadScene();
        static void Update();
        static const std::vector<Geometry*>& GetSceneObjects();

    private:
        static std::vector<Geometry*> sceneObjects;
};
}  // namespace Engine

#endif

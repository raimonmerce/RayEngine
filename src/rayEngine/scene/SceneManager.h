#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <vector>
#include "Scene.h"

namespace Engine {

class SceneManager {
public:
    // Returns the current active scene.
    static Scene* GetCurrentScene();

    // Switch to a different scene by index.
    static void SetCurrentScene(Scene* scene);

    // Call per-frame update for the current scene.
    static void Update();

    // Optional: clean up all scenes
    static void Shutdown();

private:
    static std::vector<Scene*> scenes;
    static int currentSceneIndex;
};

}  // namespace Engine

#endif  // SCENEMANAGER_H

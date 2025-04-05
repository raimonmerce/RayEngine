#ifndef RAYENGINE_H
#define RAYENGINE_H

#include "Scene.h"

namespace Engine {
    class RayEngine {
    public:
        RayEngine();
        ~RayEngine();

        void Init();
        void Run();
        void Shutdown();
        void SetScene(Scene* scene);

    private:
        static void Render();
        static void Update();
    };
}
#endif
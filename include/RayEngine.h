#ifndef RAYENGINE_H
#define RAYENGINE_H

namespace Engine {
class RayEngine {
   public:
    RayEngine();
    ~RayEngine();

    void Init();      // Initializes the RayEngine
    void Run();       // Main game loop
    void Shutdown();  // Cleanup

   private:
    static void Render();  // Rendering function
    static void Update();  // Game update function
};
}  // namespace Engine
#endif
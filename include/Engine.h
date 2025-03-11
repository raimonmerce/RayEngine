#ifndef ENGINE_H
#define ENGINE_H

class Engine {
public:
    Engine();
    ~Engine();

    void Init();    // Initializes the engine
    void Run();     // Main game loop
    void Shutdown();// Cleanup

private:
    static void Render(); // Rendering function
    static void Update(); // Game update function
};

#endif
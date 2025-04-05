#ifndef GAME_H
#define GAME_H

#include "Scene.h"

class Game {
   public:
    void Init();
    void Update();
    Engine::Scene* CreateInitialScene();
};

#endif

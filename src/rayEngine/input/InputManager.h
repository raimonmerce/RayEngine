#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

namespace Engine {
class InputManager {
   public:
    static void KeyboardHandler(unsigned char key, int x, int y);
};
}  // namespace Engine
#endif

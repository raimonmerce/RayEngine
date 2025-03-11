#include "InputManager.h"

#include <iostream>

namespace Engine {
void InputManager::KeyboardHandler(unsigned char key, int x, int y) {
    if (key == 27) {  // ESC key
        exit(0);
    }
    std::cout << "Key Pressed: " << key << std::endl;
}
}  // namespace Engine
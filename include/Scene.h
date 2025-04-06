#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Object3D.h"

namespace Engine {

class Scene {
public:
    Scene() = default;
    ~Scene();

    void add(Object3D* mesh);

    void remove(Object3D* mesh);

    const std::vector<Object3D*>& getObjects() const;

private:
    std::vector<Object3D*> objects;
};

}  // namespace Engine

#endif  // SCENE_H

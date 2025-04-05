#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Mesh.h"

namespace Engine {

class Scene {
public:
    Scene() = default;
    ~Scene();

    void add(Mesh* mesh);

    void remove(Mesh* mesh);

    const std::vector<Mesh*>& getMeshes() const;

private:
    std::vector<Mesh*> meshes;
};

}  // namespace Engine

#endif  // SCENE_H

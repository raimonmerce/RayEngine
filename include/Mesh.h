#ifndef MESH_H
#define MESH_H

#include "Geometry.h"
#include "Material.h"
#include "Object3D.h"

namespace Engine {

class Mesh : public Object3D{
public:

Mesh(Geometry* geometry, Material* material,
    const glm::vec3& position = glm::vec3(0.0f),
    const glm::vec3& rotation = glm::vec3(0.0f),
    const glm::vec3& scale    = glm::vec3(1.0f));
    ~Mesh();

    // Draws the mesh by binding the material and geometry.
    void Draw() override;

    // Accessors.
    Geometry* GetGeometry() const;
    Material* GetMaterial() const;

private:
    Geometry* geometry;
    Material* material;
};

} // namespace Engine

#endif

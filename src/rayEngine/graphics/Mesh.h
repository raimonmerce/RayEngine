#ifndef MESH_H
#define MESH_H

#include "Geometry.h"
#include "Material.h"

namespace Engine {

class Mesh {
public:
    // Constructs a Mesh from a given Geometry and Material.
    Mesh(Geometry* geometry, Material* material);
    ~Mesh();

    // Draws the mesh by binding the material and geometry.
    void Draw() const;

    // Accessors.
    Geometry* GetGeometry() const;
    Material* GetMaterial() const;

private:
    Geometry* geometry;
    Material* material;
};

} // namespace Engine

#endif

#ifndef SPHERE_GEOMETRY_H
#define SPHERE_GEOMETRY_H

#include "Geometry.h"
#include "../src/rayEngine/libs/glm/glm.hpp"
#include <vector>

namespace Engine {

class SphereGeometry : public Geometry {
public:
    SphereGeometry(float radius, unsigned int rings, unsigned int sectors);
};

} // namespace Engine

#endif // SPHERE_GEOMETRY_H

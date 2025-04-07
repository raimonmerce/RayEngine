#ifndef CONE_GEOMETRY_H
#define CONE_GEOMETRY_H

#include "Geometry.h"
#include "../src/rayEngine/libs/glm/glm.hpp"
#include <vector>

namespace Engine {

class ConeGeometry : public Geometry {
public:
    ConeGeometry(float radius, float height, unsigned int sectors);
};

} // namespace Engine

#endif // CONE_GEOMETRY_H

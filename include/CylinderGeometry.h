#ifndef CYLINDER_GEOMETRY_H
#define CYLINDER_GEOMETRY_H

#include "Geometry.h"
#include "../src/rayEngine/libs/glm/glm.hpp"
#include <vector>

namespace Engine {

class CylinderGeometry : public Geometry {
public:
    CylinderGeometry(float radius, float height, unsigned int sectors, bool openEnded = false);
};

} // namespace Engine

#endif // CYLINDER_GEOMETRY_H

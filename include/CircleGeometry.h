#ifndef CIRCLE_GEOMETRY_H
#define CIRCLE_GEOMETRY_H

#include "Geometry.h"
#include "../src/rayEngine/libs/glm/glm.hpp"
#include <vector>

namespace Engine {

class CircleGeometry : public Geometry {
public:
    CircleGeometry(float radius, unsigned int segments);
};

} // namespace Engine

#endif // CIRCLE_GEOMETRY_H

#ifndef CUBEGEOMETRY_H
#define CUBEGEOMETRY_H

#include "Geometry.h"

namespace Engine {

  class CubeGeometry : public Geometry {
  public:
    CubeGeometry(float width = 1.0f, float height = 1.0f, float depth = 1.0f);
  };

}
#endif
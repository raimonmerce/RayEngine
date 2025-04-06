#ifndef PLANEGEOMETRY_H
#define PLANEGEOMETRY_H

#include "Geometry.h"

namespace Engine {

  class PlaneGeometry : public Geometry {
  public:
    PlaneGeometry(float width = 1.0f, float height = 1.0f);
  };

}
#endif
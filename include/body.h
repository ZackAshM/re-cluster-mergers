#ifndef BODY_H
#define BODY_H

#include "vector3d.h"

// a simple body as we know it
struct Body
{
  double mass;
  Vector3D position;
  Vector3D velocity;

  // constructors and destructor
  Body();
  Body(double mass, Vector3D position, Vector3D velocity);
  ~Body();
};

#endif

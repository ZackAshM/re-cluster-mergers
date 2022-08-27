#ifndef FRK4_H
#define FRK4_H

#include "vector3d.h"

extern Vector3D FRK4(Vector3D dydt, Vector3D y, double t0, double dt);

#endif

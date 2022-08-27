#ifndef GRAVITY_H
#define GRAVITY_H

#include "vector3d.h"
#include "body.h"

extern Vector3D Fg(const Body &body1, const Body &body2);

#endif

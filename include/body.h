#ifndef BODY_H
#define BODY_H

#include "vector.h"

// a simple body as we know it
struct Body
{
  double mass;
  Vector position;
  Vector velocity; 
};

#endif

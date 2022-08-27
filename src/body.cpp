#include "body.h"
#include "vector3d.h"

// constructors, default at 0 mass, 0,0,0 position, 0,0,0 velocity
Body::Body() : mass(0), position(Vector3D()), velocity(Vector3D()) {}
Body::Body(double mass, Vector3D position, Vector3D velocity) : mass(mass), position(position), velocity(velocity) {}

Body::~Body() {}

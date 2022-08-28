#include "body.h"
#include "vector3d.h"

#include <iostream>

using namespace std;

// constructors, default at 0 mass, 0,0,0 position, 0,0,0 velocity
Body::Body() : mass(0), position(Vector3D()), velocity(Vector3D()) {}
Body::Body(const double mass, const Vector3D position, const Vector3D velocity) : mass(mass), position(position), velocity(velocity) {}

Body::~Body() {}

ostream& operator<<(ostream& os, const Body &body) {
  return os << "Mass: " << body.mass << ", Position: " << body.position << ", Velocity: " << body.velocity;
}

void Body::update(double mass, Vector3D &position, Vector3D &velocity) {
  this->mass = mass;
  this->position.update( position.x(), position.y(), position.z() );
  this->velocity.update( velocity.x(), velocity.y(), velocity.z() );
}

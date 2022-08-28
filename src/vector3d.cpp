#include <cmath>
#include <iostream>

using namespace std;

#include "vector3d.h"

// 3d vector constructor, sets x,y,z components; 0,0,0 default
Vector3D::Vector3D() : _x(0), _y(0), _z(0) {}
Vector3D::Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z) {}

// 3d vector destructor
Vector3D::~Vector3D() {}

// component getters
double Vector3D::x() {
  return this->_x;
}
double Vector3D::y() {
  return this->_y;
}
double Vector3D::z() {
  return this->_z;
}

// return the vector magnitude
double Vector3D::mag() {
  return sqrt(this->_x*this->_x + this->_y*this->_y + this->_z*this->_z);
}

// return the corresponding unit vector
Vector3D Vector3D::unitVector() {
  double mag = sqrt(this->_x*this->_x + this->_y*this->_y + this->_z*this->_z);
  double xnorm = this->_x / mag;
  double ynorm = this->_y / mag;
  double znorm = this->_z / mag;
  return Vector3D(xnorm, ynorm, znorm);
}

/* operations */

// addition
Vector3D Vector3D::operator+(const Vector3D &v) const {
  return Vector3D( this->_x + v._x, this->_y + v._y, this->_z + v._z );
}

// subtraction
Vector3D Vector3D::operator-(const Vector3D &v) const {
  return Vector3D( this->_x - v._x, this->_y - v._y, this->_z - v._z );
}

// scalar mult on right
Vector3D Vector3D::operator*(double a) const {
  return Vector3D( a*this->_x, a*this->_y, a*this->_z );
}

// scalar mult on left
Vector3D operator*(double a, const Vector3D &v) {
  return Vector3D( a*v._x, a*v._y, a*v._z );
}

// scalar division on right
Vector3D Vector3D::operator/(double a) const {
  return Vector3D( this->_x/a, this->_y/a, this->_z/a );
}

// dot product
double Vector3D::dot(const Vector3D &v) const {
  return this->_x*v._x + this->_y*v._y + this->_z*v._z;
}

// cross product
Vector3D Vector3D::cross(const Vector3D &v) const {
  double xcomp = this->_y*v._z - this->_z*v._y;
  double ycomp = this->_z*v._x - this->_x*v._z;
  double zcomp = this->_x*v._y - this->_y*v._x;
  return Vector3D( xcomp, ycomp, zcomp );
}

// print appropriately
ostream& operator<<(ostream& os, const Vector3D &v) {
  return os << "(" << v._x << ", " << v._y << ", " << v._z << ")";
}

// update coords
void Vector3D::update(double x, double y, double z) {
  this->_x = x;
  this->_y = y;
  this->_z = z;
}

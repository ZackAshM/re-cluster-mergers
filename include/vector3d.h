#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iosfwd>
using namespace std;

// a simple 3d vector
class Vector3D
{
 private:
  const double _x, _y, _z;

 public:
  Vector3D();
  Vector3D(double x, double y, double z);
  ~Vector3D();

  double x();
  double y();
  double z();

  double mag();
  Vector3D unitVector();

  Vector3D operator+(const Vector3D &v) const;
  Vector3D operator-(const Vector3D &v) const;
  Vector3D operator*(double a) const;
  friend Vector3D operator*(double a, const Vector3D &v);
  Vector3D operator/(double a) const;
  
  double dot(const Vector3D &v) const;
  Vector3D cross(const Vector3D &v) const;

  friend ostream& operator<<(ostream& os, const Vector3D &v);
  
};

#endif

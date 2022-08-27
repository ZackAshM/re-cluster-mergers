#include "gravity.h"
#include "body.h"
#include "vector3d.h"
#include "constants.h"

using namespace astrophysical_constants;
// using namespace std;

#include <cmath>
// #include <iostream>

extern Vector3D Fg(const Body &body1, const Body &body2)
{

  // get masses
  double m1 {body1.mass};
  double m2 {body2.mass};

  /*
  cout << "m1: " << m1 << endl;
  cout << "m2: " << m2 << endl;
  */

  // get position difference from body1 to body2
  Vector3D r {body1.position - body2.position};
  double r_mag {r.mag()};
  Vector3D r_dir {r.unitVector()};

  /*
  cout << "r: " << r << endl;
  cout << "r_mag: " << r_mag << endl;
  cout << "r_dir: " << r_dir << endl;
  */

  // calculate and return the gravitational force w/ distance buffer
  return -G*m1*m2*r_dir / pow(r_mag + R_BUFFER, 2);
  
}

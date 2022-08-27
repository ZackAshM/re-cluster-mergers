#include "FRK4.h"
#include "vector3d.h"

extern Vector3D FRK4(Vector3D &dydt(Vector3D, double), Vector3D y0, double t0, double dt)
{

  // slope approximations
  Vector3D k1{dydt(y0, t0)};
  Vector3D k2{dydt(y0 + k1*(dt/2), t0 + dt/2)};
  Vector3D k3{dydt(y0 + k2*(dt/2), t0 + dt/2)};
  Vector3D k4{dydt(y0 + k3*dt, t0 + dt)};

  // weighted slope
  Vector3D slope{(k1 + 2*k2 + 2*k3 + k4)/6};

  // approximate solution at t0+dt
  return y0 + slope*dt;
  
}

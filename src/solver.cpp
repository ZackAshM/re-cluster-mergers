#include "solver.h"
#include "vector3d.h"
#include "body.h"
#include "gravity.h"

/*
  Return for this body, a new body representing the
  the body's position and velocity at a new timestep (+dt).
  thatbody represents the influencing body via gravity.
  The solver uses Runge-Kutta 4th Order Algorithm.
 */
extern Body solver(Body &thisbody, Body &thatbody, double dt)
{

  // the initial conditions for this body
  double mass{ thisbody.mass };
  Vector3D r0{ thisbody.position };
  Vector3D v0{ thisbody.velocity };
  
  // the derivatives: dv/dt = F/m, dx/dt = v
  Vector3D a0{ Fg(thisbody, thatbody) / mass };
  // Vector3D v0{ thisbody.velocity };

  // 1st order slopes
  Vector3D k1v{ a0 };
  Vector3D k1r{ v0 };

  // this body updated for 1st order
  Vector3D r1{ r0 + k1r*(dt/2) };
  Vector3D v1{ v0 + k1v*(dt/2) };
  Body thisbody1{ Body(mass, r1, v1) };

  // now repeat with newly approximated body
  Vector3D a1{ Fg(thisbody1, thatbody) / mass };
  Vector3D k2v{ a1 };
  Vector3D k2r{ v1 };

  // get 2nd order body
  Vector3D r2{ r0 + k2r*(dt/2) };
  Vector3D v2{ v0 + k2v*(dt/2) };
  Body thisbody2{ Body(mass, r2, v2) };

  // repeat
  Vector3D a2{ Fg(thisbody2, thatbody) / mass };
  Vector3D k3v{ a2 };
  Vector3D k3r{ v2 };

  // get 3rd order
  Vector3D r3{ r0 + k3r*dt };
  Vector3D v3{ v0 + k3v*dt };
  Body thisbody3{ Body(mass, r3, v3) };

  // repeat
  Vector3D a3{ Fg(thisbody3, thatbody) / mass };
  Vector3D k4v{ a3 };
  Vector3D k4r{ v3 };

  // get final 4th order corrections
  Vector3D r4{ r0 + dt*(k1r + 2*k2r + 2*k3r + k4r)/6 };
  Vector3D v4{ v0 + dt*(k1v + 2*k2v + 2*k3v + k4v)/6 };

  // all corrections finished, return new body
  return Body(mass, r4, v4);
  
}

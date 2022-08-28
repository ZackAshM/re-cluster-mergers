/*
  Simple orbit simulation using Fg solver.
 */

#include "body.h"
#include "vector3d.h"
#include "solver.h"

using namespace std;
#include <iostream>
#include <fstream>

#define N_POINTS 1000
#define DURATION_YRS 5

int main()
{

  // initial conditions: a body centered, and a revolving body
  Body sun(2e30, Vector3D(), Vector3D());
  Body earth(6e24, Vector3D(0.5*150e6,0,0), Vector3D(0,9.46e8,0));
  const double t0{0};
  const double tf{t0+DURATION_YRS};
  const double dt{(tf - t0) / N_POINTS};

  double t{t0};

  // record initial
  ofstream orbit_data;
  orbit_data.open ("output/orbit_data.csv");
  orbit_data << "# time [yr], x[m], y[m]\n";

  // find new time and positions
  Body body_n{earth};   // iterated body variable

  // repeat for next time steps
  for (double t=t0; t<=tf; t=t+dt)
    {
      // write data to file
      orbit_data << t << ", " << body_n.position.x() << ", " << body_n.position.y() << "\n";

      // get body at new time
      Body updated_body = solver(body_n, sun, dt);
      body_n.update(updated_body.mass, updated_body.position, updated_body.velocity);
      
    }
    
  orbit_data.close();
  return 0;
}

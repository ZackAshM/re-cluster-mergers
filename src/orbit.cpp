/*
  Simple orbit simulation using Fg solver.
 */

#include "body.h"
#include "vector3d.h"
#include "solver.h"

using namespace std;
#include <iostream>
#include <fstream>

int main()
{

  // initial conditions: a body centered, and a revolving body
  Body sun(2e30, Vector3D(), Vector3D());
  Body earth(6e24, Vector3D(150e6,0,0), Vector3D(0,9.46e8,0));
  const double t0{0};
  const double tf{100};
  const double dt{(tf - t0) / 10};

  double t{t0};

  // record initial
  ofstream orbit_data;
  orbit_data.open ("output/orbit_data.csv");
  orbit_data << "# time [yr], x[m], y[m]\n";

  // find new time and positions
  Body body_n{earth};   // iterated body variable

  cout << "Initial: \n";
  cout << "Pos: " << body_n.position << endl;
  cout << "Vel: " << body_n.velocity << endl;
  cout << "ptr: " << &body_n << endl;

  // repeat for next time steps
  for (double t=t0; t<=tf; t=t+dt)
    {
      // write data to file
      orbit_data << t << ", " << body_n.position.x() << ", " << body_n.position.y() << "\n";

      // get body at new time
      cout << "getting new body..." << endl;
      Body l = solver(body_n, sun, dt);
      
      Body body_n{Body(l.mass, l.position, l.velocity)};// Body(solver(body_n, sun, dt)) };
      cout << "body ptr: " << &body_n << endl << endl;
      
    }
    
  orbit_data.close();
  return 0;
}

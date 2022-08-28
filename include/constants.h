#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace astrophysical_constants
{
  
  // for gravitational force calculation
  inline constexpr double G{6.6380e-5};        // gravitational constant [m^3 / kg / yr^2]
  inline constexpr double R_BUFFER{0.01};      // distance modifier to prevent divide by 0 [m]

}

#endif

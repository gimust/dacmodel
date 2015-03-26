// MASH Simulation
// http://www.holmea.demon.co.uk/Frac2/Mash.htm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <float.h>
#include <assert.h>
#include <sstream>

#include "mash3.hpp"

// Parameters
const int F=1;

std::string mash3::getState()
{
  std::stringstream ss;
  ss << q[0] << " " << q[1] << " " << q[2] << " " << c[0][0] << " " << c[1][0] << " " << c[2][0] << " " << mash;     

  std::string s = ss.str();
  return s;
}

//default constructor, 3 identical 2^N 24 bit accumulators
mash3::mash3(void)
{
  modulo1 = (1<<24);
  modulo2 = (1<<24);
  modulo3 = (1<<24);
  init();
}

//constructor with user defined modulo accumulators
mash3::mash3(uint32_t mod1, uint32_t mod2, uint32_t mod3)
{
  modulo1 = mod1;
  modulo2 = mod2;
  modulo3 = mod3;
  init();
}

void  mash3::init()
{
  // Initial values
  q[0]=1;
  q[1]=0;
  q[2]=0;
  
  for(int i=0; i<3; i++) {

    for(int j=0; j<3; j++)
      c[i][j] = 0;
  }
  
  fprintf(stderr, "mash3 initialised with modulo %d, %d, %d\n", modulo1, modulo2, modulo3);
}

int mash3::Clock(int n)
{
  int d[4]; // Adder output / register data input

  // Carry flip-flops
  c[2][2] = c[2][1]; c[2][1] = c[2][0];
  c[1][1] = c[1][0];

  // Adders
  d[0] = (q[0]+   n) % modulo1;
  d[1] = (q[1]+d[0]) % modulo2;
  d[2] = (q[2]+d[1]) % modulo3;

  // Carries
  c[0][0] = (q[0]+   n) / modulo1;
  c[1][0] = (q[1]+d[0]) / modulo2;
  c[2][0] = (q[2]+d[1]) / modulo3;

  // Register
  for (int i=0; i<3; i++) q[i] = d[i];

  // Pascals triangle for output value
  mash =  c[0][0]
      +   c[1][0] -   c[1][1]
      +   c[2][0] - 2*c[2][1] +   c[2][2];

  return mash;
}

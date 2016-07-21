#include <stdio.h> 

int main(int argc, char **argv) {


  
  typedef double real; // creating a type called real f
  
  typedef struct { 
    real x, y;       
  } VecR; 
  
  typedef struct {
    VecR r, rv, ra;  // position, veloity, acceleration
  } Mol;

  void ComputeForces () {


  }


  return 0;
}

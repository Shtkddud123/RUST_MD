#include <stdio.h>
#include <stdlib.h>

typedef int (*newfunction) (int a, int b); 

int add (int a, int b) {

  int c; 
  c = a + b;  
  return c;   
}

int main () {

  int new; 
  newfunction blah;

  blah = &add; 

  //  new = add(3,4);
  new = blah(3,4);
  printf("%i \n", new);

  return 0;
}

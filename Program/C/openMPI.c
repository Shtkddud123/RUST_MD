// OpenMP introductory example: sampling bucket sort 

// compile: gcc -fopenmp -o MPI openMPI.c

// set the number of threads via the environment variable 
// OMP_NUMTHREADS e.g. in the C shell 

// setenv OMP_NUM_THREADS 8

#include <omp.h> 
#include <stdlib.h>

// needed for call to qsort() 

int cmpints(int *u, int *v) {
  if (*u < *v) return -1; 
  if (*u > *v) return 1; 
  return 0;
}

// adds xi to the part array, increments npart, the length of part
void grab(int xi, int *part, int *npart) {
  part[*npart] = xi;
  *npart += 1; 
}

// finds the min and max y, length ny 
// placing them in miny and maxy 

void findminmax(int *y, int ny, int *miny, int *maxy) {
  int i, yi;
  *miny = *maxy = y[0];
  for (i = 1; i < ny; i++) {
    yi = y[i];
    if (yi < *miny) {
      *miny = yi;   
    } else if (yi > *maxy) {
      *maxy = yi;
    }
  }
}

// sort the array x of length n 
void bsort(int *x, int n) {
  // these are local to this function, but shared among the threads 
  float *bdries, int *counts; 
  #pragma omp parallel 
  // entering the block activates the threads, each executing it 
  { int me = omp_get_thread_num();
    // have to do the next call within the block, while the threads 
    // are active 
    int nth = omp_get_num_thread();
    int i, xi, minx, maxx, start; 
    int *mypart;
    float increm;
    int SAMPLESIZE;

    

  }

}

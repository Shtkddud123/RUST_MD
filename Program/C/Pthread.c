// PrimesThreads.c 

/*
Threads-based program to find the number of primes between 2 and n;
uses the sieve of eratothenes, deleting all multiples of 2, all multples 
of 3, all multiples of 5 etc..  
 */

// for illustration purposes only; NOT claimed to be efficient 

// Unix compilation: gcc -g -o primethreads Primethreads.c -lpthread -lm 

// usage: primethreads n num_threads 

#include <stdio.h>
#include <math.h> 
#include <pthread.h>

#define MAX_N 1000000
#define MAX_THREADS 25 

// shared variables 
int nthreads, // number of threads (not counting main()) 
  n, // range of check for primeness
  prime[MAX_N+1], // in the end, prime[i] = 1 else 0 
  nextbase; // next sieve multiplier to be used 

// lock for the shared variables nextbase 
pthread_mutex_t nextbaselock = PTHREAD_MUTEX_INITIALIZER;
// ID structs for the threads 
pthread_t id[MAX_THREADS]; 

// crosses out all odd multiples of k 
void crossout (int k) { 
  int i; 
  for (i = 3; i*k <= n; i+= 2) {
    prime[i*k] = 0;
  }
} 

// each thread runs this routine 
void *worker (int tn) // tn is the thread number (0,1...) 
{ int lim, base, 
    work = 0; // amount of work done by this thread 
  // no need to ehck multipliers bigger than sqrt(n)
  lim = sqrt(n);
  do { 
    // get next sieve multiplier, avoiding duplication across threads
    // get the lock 
    pthread_mutex_lock(&nextbaselock);
    base = nextbase; 
    nextbase += 2; 
    // unlock 
    pthread_mutex_unlock(&nextbaselock);
    if (base <= lim) {
      // don't bother crossing out if base known composite 
      if (prime[base]){ 
	crossout(base);
	work++; // log work one by this thread 
      }
    }
    else return work;
  } while (1);
}

int main (int argc, char **argv) {

  int nprimes, // number of primes found 
    i,work;
  n = atoi(argv[1]);
  nthreads = atoi(argv[2]);
  // mark all even numbers nonprime, and the rest "prime until 
  // shown otherwise" 
  for (i = 3; i <= n; i++) {
    if (i%2 == 0) prime[i] = 0;
    else prime[i] = 1; 
  } 
  nextbase = 3; 
  // get threads started 

  for (i = 0; i < nthreads; i++) {
    // this call says create a thread, record it's ID in the array 
    // id, and get the thread started executing the function worker(), 
    // passing the argument i to that function 
    pthread_create(&id[i],NULL,worker,i);
  }

  // wait for all done 
  for (i = 0; i < nthreads; i++) {
    // this call says wait until thread number id[i] finishes 
    // execution, and to assign the return value of that thread to our 
    // local variable work here 
    pthread_join(id[i],&work);
    printf("%id values of base done \n", work);
  }
    // report results 
    nprimes = 1; 
    for (i = 3; i <= n; i++) {
      if (prime[i]) {
	nprimes++;
      }
      printf("the number of primes found was %d\n", nprimes);
    }

  return 0;
}

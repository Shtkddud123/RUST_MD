#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h> 

// The sum computed by the background thread


long long i = 0; // global variable 
long long sum = 0; // initalize sum 
 
// thread function to generate a sum of 0 to N 
void* sum_runner(void* arg) {

  long long *limit_ptr = (long long *) arg; // typecasting a void * pointer 
  long long limit = *limit_ptr;  // dereferencing the limit pointer 
 
  for (i = 0; i <= limit; i++) {
    sum += i; 
  }

  // sum is a global variable so other threads can access 

  pthread_exit(0);
}

// Now, what to do with the answer? 


int main(int argc, char **argv) {

  /*
    Skeleton for the thread file 
   */

  // Program that accepts arguments - if there is a wrong number
  // then this will return the error message
  if (argc < 2) {
    printf("Usage: %s<num>\n", argv[0]);
    exit(-1);
  }
  // change the string of the argument to a long long 
  long long limit = atoll(argv[1]);

  // Thread ID 
  pthread_t tid; // thread ID 

  // Create attributes 
  pthread_attr_t attr; // attributes  
  pthread_attr_init(&attr); // create attributes 
  pthread_create(&tid, &attr, sum_runner, &limit); // create a thread (CPU) with the id, the attribute, and the function x
  
  /*
While the thread is running, I can do other stuff here
   */

  
 // wait until the thread is done 
  pthread_join(tid, NULL);
  printf("Sum is %lld\n", sum);
  return 0;
} 

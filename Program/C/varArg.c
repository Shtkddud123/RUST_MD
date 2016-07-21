#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "dbg.h"

#define MAX_DATA 100 

int read_string(char **out_string, int max_buffer) { // checks string array letters, and defines the maximum size of the string 
  *out_string = calloc(1, max_buffer); // allocate caracter memory data of size max_buffer
  check_mem(*out_string); // check for errors 
  
  char *result = fgets(*out_string, max_buffer,stdin);
  check(result != NULL, "Input error.");

  return 0;

 error:
  if(*out_string) free (*out_string);
  *out_string = NULL;
  return -1; 
}

int read_int(int *out_int) {

  char *input = NULL; // initially initialize a null pointer 
  int rc = read_string(&input, MAX_DATA); // read the data from the input, with a maximum data size of MAX_DATA
  check(rc == 0, "Failed to read number");
  
  *out_int = atoi(input); // change string to intger
  free(input);
  return 0;

 error:
  if(input) free(input);
  return -1;
}

int read_scan(const char *fmt, ...) {
  int i = 0;
  int rc = 0;
  int *out_int = NULL; // integer pointer
  char *out_int = NULL; // character integer pointer 
  char **out_string = NULL; // string pointer 
  int max_buffer = 0; 
  
  va_list argp;
  va_start(argp, fmt);

  for () {
    
  }
  
}



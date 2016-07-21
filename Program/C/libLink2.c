#include <stdio.h>
#include "dbg.h" 
#include <dlfcn.h>

typedef int (*lib_function) (const char *data);

int main (int argc, char *argv[]) {

  int rc = 0;
  check (argc == 4, "USAGE liblink2");
  
  char *lib_file = argv[1];
  char *func_to_run = argv[2];
  char *data = argv[3];


  void *lib = dlopen(lib_file, RTLD_NOW);
  
  /*
    The dlopen function is used to load up the library 
    indicated by lib_file. This function returns a handle 
    that we can use later and works a lot like opening a file
   */

  check(lib != NULL, "Failed to open the library %s, %s", lib_file, dlerror());

  /*
    the dlerror function is used to check what kind of error it is. 
   */

  lib_function func = dlsym(lib, func_to_run);
  
  /*
    The dlsym function is used to get a function of the lib 
    by it's string name in func_to_run. This is the powerful part, 
    since you are dynamically getting a pointer to a function 
    based on a string I got from the command line argv 
   */
  check(func != NULL, "Did not find %s function in the library %s: %s", func_to_run, lib_file, dlerror());

  rc = func(data);
  check(rc == 0, "Failed to close %s", lib_file);
  
  return 0;

 error:
  return 1; 

}

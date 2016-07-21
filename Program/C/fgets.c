#include <stdio.h>

int main() {
  
  FILE *fp;
  char str[60];
  
  // Opening file for reading 
  fp = fopen("file.txt", "r");
  if (fp == NULL) { // IF the pointer is pointinng nowhere 
 
    perror("Error opening file");
    return(-1); // program did not return value - stop     
  }

  if (fgets(str, 60, fp) != NULL) {

    // writing content to stdout 
    puts(str);
  }
  fclose(fp);

  return 0;
}

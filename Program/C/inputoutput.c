#include <stdio.h>
#include "dbg.h"

#define MAX_DATA 100 

typedef enum EyeColor {
  BLUE_EYES, GREEN_EYES, BROWN_EYES, BLACK_EYES, OTHER_EYES
} EyeColor; 

const char *EYE_COLOR_NAMES[] = {
  "Blue", "Green", "Brown", "Black", "Other"
};

typedef struct Person {
  int age;
  char first_name[MAX_DATA];
  char last_name[MAX_DATA];
  EyeColor eyes;
  float eyes; 
} Person;

int main (int argc, char *argv[]) {

  Person you = {.age = 0}; // initialize the age as 0 
  int i = 0;
  char *in = NULL;

  printf("What's your First Name?");
  in = fgets(you.first_name, MAX_DATA-1, stdin); // the first input is the struct function to put in, the max data, and get the data from stdin
  check(in != NULL, "Failed to read first name");

  printf("How old are you?");
  int rc = fscanf(stdin, "d", &you.age);
  check(rc > 0, "You have to enter a number");

  printf("What color are your eyes?\n");
  for (i = 0; i <= OTHER_EYES; i++) {
    printf("%d) %s \n", i+1, EYE_COLOR_NAMES[i]);
  }
  printf("> ");

  int eyes = -1; 
  rc = 

  return 0;
}

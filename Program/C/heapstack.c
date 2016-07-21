#include <stdio.h>
#include <assert.h>
#include <stdlib.h> 
#include <errno.h>
#include <string.h> 

#define MAX_DATA 512
#define MAX_ROWS 100


/*
Initial structure to enter data for addresses 
 */
struct Address {
  int id;
  int set;
  char name[MAX_DATA];
  char email[MAX_DATA]; 
};

/* 
Array to store databases 
 */
struct Database {
  struct Address rows[MAX_ROWS];
};

/*
Connecting to a file, and having a pointer to a database 
 */

struct Connection {
  FILE *file; 
  struct Database *db; 
};

/* Error message */

void die (const char *message) {
  if (errno) {
    perror(message);
  } else {
    printf("ERROR %s\n", message);
  }
  exit(1);
}

/* 
Access the array, and print out each entry 
 */

void Address_print(struct Address *addr) {
  printf("%d %s %s \n", addr->id, addr->name, addr->email);
}



void Database_load(struct Connection *conn) {
int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
if(rc != 1) die ("Failed to load database."); 
}


int main () {




  return 0; 
}

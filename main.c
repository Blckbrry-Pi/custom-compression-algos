#include "stdio.h"
#include <stdlib.h>
#include <string.h>

int input(char *s,int length);

int main(void) {
  long length;
  char *buffer;
  size_t bufsize = 32;

  //get 
  buffer = (char *)malloc(bufsize * sizeof(char));
  getline(&buffer,&bufsize,stdin);
  buffer[strlen(buffer)-1] = 0;

  FILE *tempFile;
  tempFile = fopen(buffer, "r");


  if (tempFile) {
    fseek (tempFile, 0, SEEK_END);
    length = ftell (tempFile);
    fseek (tempFile, 0, SEEK_SET);
    buffer = malloc (length);
    if (buffer) {
      fread (buffer, 1, length, tempFile);
    }
    fclose (tempFile);
  }

  printf("The contents of the file are:\n%s", buffer);
  return 0;
}
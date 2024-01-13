#include <stdio.h>

int main(int argc, char *argv[]) 
{
  FILE *file;
  file = fopen(argv[1], "r");
  int counter = 0;

  if(argv[1]==NULL) {
    return 1;
  }
  if(file==NULL) {
    return 2;
  }

  for (char c = getc(file); c != EOF; c = getc(file)) {
    if(c >= 32 && c <= 126) {
      counter++;
    }
  }

  printf("Antal tecken %d", counter);
  fclose(file);

  return 0;
}
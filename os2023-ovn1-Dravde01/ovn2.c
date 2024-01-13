#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
  char full_name[1000] = "";
  int words = argc - 1;

  for (int i = 1; i < argc; i++) {
    strcat(full_name, argv[i]);
    if(argc > i+1) {
      strcat(full_name, " ");
    }
  }

  if(argv[1]==NULL) {
    return 1;
  }
  else if(words > 100) {
    return 2;
  }
  else {
    printf("Hej %s!\n", full_name);
    return 0;
  }
}
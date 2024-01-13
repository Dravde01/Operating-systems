#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
  if(argv[1]==NULL) {
    printf("Vänligen ge ditt namn som input då du kör mig :)\n");
    return 1;
  }
  else {
    printf("Hej %s!\n", argv[1]);
    return 0;
  }
}
#include <stdio.h>

int main(int argc, char *argv[]) 
{
  FILE *i_file;
  i_file = fopen(argv[1], "r");
  FILE *o_file;
  o_file = fopen("output", "w");
  int counters[26] = {0};

  if(argv[1]==NULL) {
    return 1;
  }
  if(i_file==NULL) {
    return 2;
  }

  for (char c = getc(i_file); c != EOF; c = getc(i_file)) {
    if(c >= 65 && c <= 90) {
      c += 32;
    }
    if(c >= 97 && c <= 122) {
      counters[c - 'a']++;
    }
  }

  for (int i = 0; i < 26; i++) {
    if(!counters[i] == 0) {
      printf("%c %d\n", i + 'a', counters[i]);
      fprintf(o_file, "%c %d\n", i + 'a', counters[i]);
    }
  }

  fclose(i_file);
  fclose(o_file);

  return 0;
}
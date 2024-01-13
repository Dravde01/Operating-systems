#include <stdio.h>
#include <stdlib.h>

struct CharFreq {
  char character;
  int frequency;
};

int compare(const void *a, const void *b) {
  return (((struct CharFreq*)b)->frequency - ((struct CharFreq*)a)->frequency);
}

int main(int argc, char *argv[]) 
{
  FILE *i_file;
  i_file = fopen(argv[1], "r");
  FILE *o_file;
  o_file = fopen("sorted_output", "w");
  int counters[26] = {0};
  struct CharFreq pair[26];

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
    pair[i].character = i + 'a';
    pair[i].frequency = counters[i];
  }

  qsort(pair, 26, sizeof(struct CharFreq), compare);

  for (int i = 0; i < 26; i++) {
    if(!pair[i].frequency == 0) {
      printf("%c %d\n", pair[i].character, pair[i].frequency);
      fprintf(o_file, "%c %d\n", pair[i].character, pair[i].frequency);
    }
  }

  fclose(i_file);
  fclose(o_file);

  return 0;
}
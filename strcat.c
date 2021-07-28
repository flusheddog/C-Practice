#include <stdio.h>
#include <stdlib.h>

void cat (char *a, char *b) {
  while (*a !='\0') {
    a++;
  }
  while ((*a = *b) != '\0') {
    a++;
    b++;
  }
}

int main() {
  char str1[10000];
  char str2[10000];
  scanf("%s %s", str1, str2);
  cat(str1,str2);
  printf("%s\n", str1);
  return 0;
}

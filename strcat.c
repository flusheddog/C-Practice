#include <stdio.h>
#include <stdlib.h>

void cat (char *a, char *b) {
  int i,j;
  i = j = 0;
  while (*(a+i)!='\0') {
    i++;
  }
  while ((*(a+i) = *(b+j)) != '\0') {
    i++;
    j++;
}

int main() {
  char str1[10000];
  char str2[10000];
  scanf("%s %s", str1, str2);
  cat(str1,str2);
  printf("%s\n", str1);
  return 0;
}

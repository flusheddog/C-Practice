#include <stdio.h>
#include <stdlib.h>

void squeeze (char a[], char b) {
  int i,j;
    for(i = j = 0; a[i]!= '\0'; i++) {
      if(a[i] != b) {
	    a[j++] = a[i];
      }
    }
    a[j] ='\0';
}

void squeeze2(char str1[], char str2[]) {
  for(int i = 0; str2[i] != '\0'; i++) {
    squeeze(str1, str2[i]);
  }
}
int main() {
  char str1[10000];
  char str2[10000];
  scanf("%s %s", str1, str2);
  squeeze2(str1,str2);
  printf("%s\n", str1);
    return 0;
}

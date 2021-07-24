#include <stdio.h>
#include <stdlib.h>


void squeeze (char a[], char b[]) {
  int i,j,k;
  for(k = 0; b[k] != '\0'; k++) {
    for(i = j = 0; a[i]!= '\0'; i++) {
      if(a[i] != b[k]) {
	    a[j++] = a[i];
      }
        a[j] ='\0';
    }
  }
}

int main() { 

  char str1[] = "hello";
  char str2[] = "hel";
  squeeze(str1, str2);
  printf("%s\n", str1);
    return 0;
}

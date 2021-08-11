#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef void (*EXCHTYPE)(char **, char **);
typedef int LINE;
LINE lines = 100;
LINE maxl = 1000;

int getlines(char s[], int lim) {
    int c, i;
    i = 0;
    while(--lim > 0 && (c=getchar()) != EOF && c!= '\n') {
        s[i++] = c;
    }
    if(c=='\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}
int readlines(char *lineptr[], LINE maxlines) {
    int len;
    LINE nlines; 
    char *p,line[maxl];
 
    nlines=0;
    while ((len = getlines(line,maxl))>0) {
        if (nlines >= maxlines) {
            return -1;
        }
        
        p = malloc(len+1);
        if (p == NULL) {
            return -1;
        }
        strcpy(p,line);
        lineptr[nlines++] = p;
    }
    return nlines;
}
void writelines(char *lineptr[],int nlines) {
    int i;
    for(i=0;i<nlines;i++)
        printf("%s\n",lineptr[i]);
}

int fold(const void *a,const void *b) {
    return tolower(*(char*)a) - tolower(*(char*)b);
}

int main(int argc,char *argv[]) {
    char *lineptr[lines];
    int nlines;
    if((nlines = readlines(lineptr,lines)) >=0) {
        qsort(lineptr,nlines,sizeof(*lineptr),fold);
        writelines(lineptr,nlines);
    } else{
        printf("input too big to sort\n");
    }
  return 0;
}

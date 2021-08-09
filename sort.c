#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef int LINE;
LINE lines = 100;
LINE maxl = 1000;
$ha

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
int readlines(char *lineptr[], int maxlines) {
    int len, nlines; 
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

void swap(char *px[],char *py[]) {
    char *temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

void sort(char* v[], int n, int (*comp)(), void (*exch)(char **, char **)) {
    int gap, i, j;
    for(gap=n/2;gap>0;gap/=2) {
        for(i=gap;i<n;i++) {
            for(j=i-gap;j>=0;j-=gap) {
                if((*comp) (v[j],v[j+gap])<=0) {
                    break;
                }
		(*exch)(&v[j],&v[j+gap]);
            }
        }
    }
}
int fold(char *a, char *b) {
    return tolower(*a) - tolower(*b);
}

int main(int argc,char *argv[]) {
    char *lineptr[lines];
    int nlines;
    int (*compf) (char*, char*) = &fold;
    void (*swapf) (char **,char **)  = &swap;
    if(argc>1&& argv[1][0] == '-' && argv[1][1] == 'f'){
        compf = &fold;
    }
    if((nlines = readlines(lineptr,lines)) >=0) {
        sort(lineptr, nlines, compf, swapf);
        writelines(lineptr,nlines);
    } else{
        printf("input too big to sort\n");
    }
  return 0;
}

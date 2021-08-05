#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLEN 1000
#define ALLOCSIZE 1000
#define LINES 200

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {

    if(allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n ;
        return allocp - n;
    }
    else
        return 0;
}
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
    char *p,line[MAXLEN];
 
    nlines=0;
    while ((len = getlines(line,MAXLEN))>0) {
        if (nlines >= maxlines) {
            return -1;
        }
        
        p = malloc(len+1);
        if (p == NULL) {
            return -1;
        }
        // line[len-1] = '\0';
	printf("line %d %p\n", nlines, p);

        strcpy(p,line);
        lineptr[nlines++] = p;
    }
    printf("read end %d\n", nlines);
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

void sort(char* v[], int n, int (*comp)(), void (*exch)()) {
    int gap, i, j;
    char *temp;
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
    char *lineptr[LINES];
    int nlines;
    int (*compf) (char*, char*) = &fold;
    void (*swapf) (char **,char **)  = &swap;
    if(argc>1&& argv[1][0] == '-' && argv[1][1] == 'f'){
        compf = &fold;
    }
    if((nlines = readlines(lineptr,LINES)) >=0) {
        sort(lineptr, nlines, compf, swapf);
        writelines(lineptr,nlines);
    } else{
        printf("input too big to sort\n");
    }
  return 0;
}

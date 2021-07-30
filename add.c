#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isChar(char *c) {
    if(*c == '+'|| *c == '-' || *c == '/' || *c == '*') {
        return true;
    }
    return false;
}

int main(int argc, char *argv[]) {
    int num[argc];
    int count = 0;
    for(int i = 1; i < argc;i++) {
        if(!isChar(argv[i])) {
            num[count] = atoi(argv[i]);
            count++;
        }
        if (isChar(argv[i])) {
            if(count < 2) {
                printf("Invalid Equation.");
                break;
            }
            if(*argv[i] == '+') {
                num[count-2] = num[count-2] + num[count-1];
                count--;
            }
            if(*argv[i] == '-') {
                num[count-2] = num[count-2] - num[count-1];
                count--;
            }
            if(*argv[i] == '*') {
                num[count-2] = num[count-2] * num[count-1];
                count--;
            }
            if(*(argv[i]) == '/') {
                num[count-2] = num[count-2] / num[count-1];
                count--;
            }
        }
    }
    printf("%d\n",num[0]);
    return 0;
}

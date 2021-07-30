#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isChar(char c) {
    if(c == '+'|| c == '-' || c == '/' || c == '*') {
        return true;
    }
    return false;
}
int main() {
    

    int num[10000];
    char ch;
    int count = 0;
    scanf("%c",&ch);
    while(true){
        if(ch == '\n') {
            break;
        }
        if(!isChar(ch) && ch != ' ') {
            num[count] = ch - '0';
            count++;
        }
        if (isChar(ch)) {
            if(count < 2) {
                printf("Invalid Equation.");
                break;
            }
            if(ch == '+') {
                num[count-2] = num[count-2] + num[count-1];
                count--;
            }
            if(ch == '-') {
                num[count-2] = num[count-2] - num[count-1];
                count--;
            }
            if(ch == '*') {
                num[count-2] = num[count-2] * num[count-1];
                count--;
            }
            if(ch == '/') {
                num[count-2] = num[count-2] / num[count-1];
                count--;
            }
        }
        scanf("%c",&ch);
    }
    printf("%d",num[0]);
    return 0;
}

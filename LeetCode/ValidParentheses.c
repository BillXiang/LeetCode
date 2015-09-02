#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    if(s==NULL){
        return true;
    }
    int len = strlen(s)+1;
    char* stack = (char*)malloc(len*sizeof(char));
    char* pStack = stack+1;
    while(*s){
        switch(*s){
        case '(':
        case '{':
        case '[':
            *pStack = *s;
            pStack++;
            break;
        case ')':
            pStack--;
            if(pStack==stack || *pStack!='('){
                return false;
            }
            break;
        case '}':
            pStack--;
            if(pStack==stack || *pStack!='{'){
                return false;
            }
            break;
        case ']':
            pStack--;
            if(pStack==stack || *pStack!='['){
                return false;
            }
            break;
        }
        s++;
    }
    bool result = stack+1==pStack;
    free(stack);
    return result;
}

void isValidMain(void){
    char s[] = "{(){[(){}]}[()]}";
    printf("%d\n", isValid(s));
}

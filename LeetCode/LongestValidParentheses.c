#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestValidParentheses(char* s) {
    if(s==NULL){
        return 0;
    }
    int maxLen = 0;
    int curLen = 0;

    int sLen = strlen(s);

    char* stack = (char*)malloc((sLen+1)*sizeof(char));
    char* pStack = stack;
    pStack[sLen] = '\0';
    char* stackPre = stack;;

    while(*s){
        switch(*s){
        case '(':
        case '{':
        case '[':
            *pStack = *s;
            pStack++;
            break;
        case ')':
            if(pStack!=stack && *(pStack-1)=='('){
                *(pStack-1) = '*';
                if(pStack-1!=stack){
                    stackPre = pStack-2;
                    while(stackPre!=stack && *stackPre=='*'){
                        stackPre--;
                    }
                }
            }else if(*(pStack-1)=='*'){
                if(*stackPre=='('){
                    *stackPre = '*';
                    while(stackPre!=stack && *stackPre=='*'){
                        stackPre--;
                    }
                }else{
                    *pStack = ')';
                    pStack++;
                }
            }else{
                *pStack = ')';
                pStack++;
            }
            break;
        case '}':
            if(pStack!=stack && *(pStack-1)=='{'){
                *(pStack-1) = '*';
                if(pStack-1!=stack){
                    stackPre = pStack-2;
                    while(stackPre!=stack && *stackPre=='*'){
                        stackPre--;
                    }
                }
            }else if(*(pStack-1)=='*'){
                if(*stackPre=='{'){
                    *stackPre = '*';
                    while(stackPre!=stack && *stackPre=='*'){
                        stackPre--;
                    }
                }else{
                    *pStack = '}';
                    pStack++;
                }
            }else{
                *pStack = '}';
                pStack++;
            }
            break;
        case ']':
            if(pStack!=stack && *(pStack-1)=='['){
                *(pStack-1) = '*';
                if(pStack-1!=stack){
                    stackPre = pStack-2;
                    while(stackPre!=stack && *stackPre=='*'){
                        stackPre--;
                    }
                }
            }else if(*(pStack-1)=='*'){
                if(*stackPre=='['){
                    *stackPre = '*';
                    while(stackPre!=stack && *stackPre=='*'){
                        stackPre--;
                    }
                }else{
                    *pStack = ']';
                    pStack++;
                }
            }else{
                *pStack = ']';
                pStack++;
            }
            break;
        }
        s++;
    }

    maxLen = 0;
    curLen = 0;
    pStack = stack;
    while(*pStack){
        if(*pStack=='*'){
            curLen += 2;
        }else{
            if(curLen>maxLen){
                maxLen = curLen;
            }
            curLen = 0;
        }
        pStack++;
    }
    if(curLen>maxLen){
        maxLen = curLen;
    }

    free(stack);
    return maxLen;
}

int longestValidParentheses2(char* s) {
    if(s==NULL){
        return 0;
    }
    int maxLen = 0;
    int curLen = 0;

    int sLen = strlen(s);
//    char* ps = s;
//    while(*ps){
//        sLen++;
//        ps++;
//    }

    char* stack = (char*)malloc((sLen+1)*sizeof(char));
    if(stack==NULL){
        return -1;
    }
    char* pStack = stack;
    //pStack[sLen] = '\0';
    char* stackEnd = stack+sLen;
    char* stackPre = stack;;

    while(*s){
        switch(*s){
        case '(':
            *pStack = *s;
            pStack++;
            break;
        case ')':
            if(pStack!=stack && *(pStack-1)=='('){
                *(pStack-1) = '*';
                if(pStack-1!=stack){
                    stackPre = pStack-2;
                    while(stackPre!=stack && *stackPre=='*'){
                        stackPre--;
                    }
                }
            }else if(*(pStack-1)=='*'){
                if(*stackPre=='('){
                    *stackPre = '*';
                    while(stackPre!=stack && *stackPre=='*'){
                        stackPre--;
                    }
                }else if(pStack!=stackEnd){
                    *pStack = ')';
                    pStack++;
                }
            }else if(pStack!=stackEnd){
                *pStack = ')';
                pStack++;
            }
            break;
        }
        s++;
    }
    pStack = stack;
    int i=0;
    //while(*pStack){
    for(i=0; i<sLen; i++){
        if(pStack[i]=='*'){
            curLen += 2;
        }else{
            if(curLen>maxLen){
                maxLen = curLen;
            }
            curLen = 0;
        }
        //pStack++;
    }
    if(curLen>maxLen){
        maxLen = curLen;
    }

    free(stack);
    return maxLen;
}

void longestValidParenthesesMain(void){
    char s[] = //"()(()";
    //"}[{[[]]}])(){}[]{}";
    //"((()))(((()";
    //"(()()";
    //"()(())";
    //"(())(()(()())()()(()())())))())()((())())(((()))))())()())()()())()()))(())((((()()(()))())(()))))((())()())()))))((())((((()))(())))()((()())))())((((()((()()()()((((()((()))))()))";
    //"(())(()(()())()()(()())())))())()((())())(((()))))())()())()()())()()))(())((((()()(()))())(()))))((())()())()))))((())((((()))(())))()((()())))())((((()((()()()()((((()((()))))()))";
    "(()()(()(()))()((()))((()(()())()(()))())))()(()()))())))))))()()()()))(((()())((()()(((())))()(()()(())((()))))))(()(()))(((()())()))(()))((((()(()()()())()()(()))(()()(())()((()()())))(())()())()(";
    printf("%d\n", longestValidParentheses2(s));
}

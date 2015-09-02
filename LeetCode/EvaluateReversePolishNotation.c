/**逆波兰表达式
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

**/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int evalRPN(char** tokens, int tokensSize) {
    int* stack = (int*)malloc(tokensSize*sizeof(int));
    int* stackTop = stack;
    int result = 0;

    int i = 0;
    for(i=0; i<tokensSize; i++){
        if(tokens[i][0]=='+' && tokens[i][1]=='\0'){
            if(stackTop-1!=stack){
                stackTop--;
                *(stackTop-1) = (*(stackTop-1)) + (*(stackTop));
            }
        }else if(tokens[i][0]=='-' && tokens[i][1]=='\0'){
            if(stackTop-1!=stack){
                stackTop--;
                *(stackTop-1) = (*(stackTop-1)) - (*(stackTop));
            }
        }else if(tokens[i][0]=='*'){
            if(stackTop-1!=stack){
                stackTop--;
                *(stackTop-1) = (*(stackTop-1)) * (*(stackTop));
            }
        }else if(tokens[i][0]=='/'){
            if(stackTop-1!=stack && *(stackTop-1)!=0){
                stackTop--;
                *(stackTop-1) = (*(stackTop-1)) / (*(stackTop));
            }
        }else{
            *stackTop = atoi(tokens[i]);
            stackTop++;
        }
    }
    result = *stack;
    free(stack);
    return result;
}

void evalRPNMain(void){
    char *tokens[] = //{"1", "2", "+", "5", "*"};
    {"-3", "9","*"};

    int len = sizeof(tokens)/sizeof(char*);
    printf("%d\n", evalRPN(tokens, len));
}

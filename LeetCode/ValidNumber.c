#include <stdbool.h>
#include <stdlib.h>

bool isNumber(char* s) {
    double i = 3.;
    if(s==NULL){
        return false;
    }
    char state = 0;
    while(*s){
        switch(state){
            case 0:
                if(*s==' '){
                    s++;
                }else{
                    state = 1;
                }
                break;
            case 1:
                if(*s=='.'){
                    state = 2;
                    s++;
                }else if(*s=='+' || *s=='-'){
                    state = 5;
                    s++;
                }else if(*s>='0' && *s<='9'){
                    state = 6;
                    s++;
                }else{
                    return false;
                }
                break;
            case 2:
                if(*s>='0' && *s<='9'){
                    state = 3;
                    s++;
                }else{
                    return false;
                }
                break;
            case 3:
                if(*s>='0' && *s<='9'){
                    s++;
                }else if(*s=='e'){
                    state = 7;
                    s++;
                }else if(*s==' '){
                    state = 4;
                    s++;
                }else{
                    return false;
                }
                break;
            case 4:
                if(*s==' '){
                    s++;
                }else{
                    return false;
                }
                break;
            case 5:
                if(*s=='.'){
                    state = 2;
                    s++;
                }else if(*s>='0' && *s<='9'){
                    state = 6;
                    s++;
                }else{
                    return false;
                }
                break;
            case 6:
                if(*s>='0' && *s<='9'){
                    s++;
                }else if(*s=='.'){
                    state = 10;
                    s++;
                }else if(*s=='e'){
                    state = 7;
                    s++;
                }else if(*s==' '){
                    state = 4;
                    s++;
                }else{
                    return false;
                }
                break;
            case 7:
                if(*s=='+' || *s=='-'){
                    state = 8;
                    s++;
                }else if(*s>='0' && *s<='9'){
                    state = 9;
                    s++;
                }else{
                    return false;
                }
                break;
            case 8:
                if(*s>='0' && *s<='9'){
                    state = 9;
                    s++;
                }else{
                    return false;
                }
                break;
            case 9:
                if(*s>='0' && *s<='9'){
                    s++;
                }else if(*s==' '){
                    state = 4;
                    s++;
                }else{
                    return false;
                }
                break;
            case 10:
                if(*s>='0' && *s<='9'){
                    state = 3;
                    s++;
                }else if(*s==' '){
                    state = 4;
                    s++;
                }else if(*s=='e'){
                    state = 7;
                    s++;
                }else{
                    return false;
                }
                break;
        }
    }
    if(state==3 || state==4 || state==6 || state==9 || state==10){
        return true;
    }
    return false;
}

void isNumberMain(void){
//    printf("%d\n", isNumber("1"));
//    printf("%d\n", isNumber(".1"));
//    printf("%d\n", isNumber("-1"));
//    printf("%d\n", isNumber("+1"));
//    printf("%d\n", isNumber("   1"));
//    printf("%d\n", isNumber("0001"));
//    printf("%d\n", isNumber("   0001"));
//    printf("%d\n", isNumber("1e6"));
//    printf("%d\n", isNumber("1e-6"));
//    printf("%d\n", isNumber("000"));
//    printf("%d\n\n", isNumber("0e4"));

//    printf("%d\n", isNumber("1   "));
//    printf("%d\n", isNumber(".100"));
//    printf("%d\n", isNumber("-100  "));
//    printf("%d\n", isNumber("+1"));
//    printf("%d\n", isNumber("   1"));
//    printf("%d\n", isNumber("0001"));
//    printf("%d\n", isNumber("   0001"));
//    printf("%d\n", isNumber("1e6"));
//    printf("%d\n", isNumber("1e-6"));
//    printf("%d\n", isNumber("000"));
//    printf("%d\n", isNumber("0e4"));
    printf("%d\n", isNumber("3.   "));
    printf("%d\n", isNumber("3.e3   "));
    printf("%d\n", isNumber("3.2e3   "));
//    printf("%d\n\n", isNumber("0e-4"));
//
//    printf("%d\n", isNumber("a"));
//    printf("%d\n", isNumber("0.0.0"));
//    printf("%d\n", isNumber("e3"));
//    printf("%d\n", isNumber("e3.0"));
//    printf("%d\n", isNumber("e.3"));
//    printf("%d\n", isNumber("1e 6"));
    printf("%d\n", isNumber("1 e6"));
    printf("%d\n", isNumber("1.e6"));
    printf("%d\n", isNumber("3me"));
}

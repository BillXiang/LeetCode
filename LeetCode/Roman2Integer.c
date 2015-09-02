#include <stdlib.h>
int romanToInt(char* s) {
    if(s==NULL)
        return 0;
    int result = 0;
    while(*s){
        switch(*s){
        case 'I':
            if(*(s+1)=='V'){
                result += 4;
                s += 2;
            }else if(*(s+1)=='X'){
                result += 9;
                s += 2;
            }else{
                result += 1;
                s++;
            }
            break;
        case 'X':
            if(*(s+1)=='L'){
                result += 40;
                s += 2;
            }else if(*(s+1)=='C'){
                result += 90;
                s += 2;
            }else{
                result += 10;
                s++;
            }
            break;
        case 'C':
            if(*(s+1)=='D'){
                result += 400;
                s += 2;
            }else if(*(s+1)=='M'){
                result += 900;
                s += 2;
            }else{
                result += 100;
                s++;
            }
            break;
        case 'V':
            result += 5;
            s++;
            break;
        case 'L':
            result += 50;
            s++;
            break;
         case 'D':
            result += 500;
            s++;
            break;
        case 'M':
            result += 1000;
            s++;
            break;
        default:
            break;
        }
    }
    return result;
}

void romanToIntMain(void){
    printf("%d\n", romanToInt("MMMCMXCIX"));//3999
    printf("%d\n", romanToInt("MM"));//2000
    printf("%d\n", romanToInt("MDCCCLXXXVIII"));//1888
}

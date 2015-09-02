#include <limits.h>
#include <stdlib.h>
int myAtoi(char* str) {
    if(str==NULL)
        return 0;
    int negtive = 0;
    int result = 0;
    int tmp = 0;
    int start = 0;
    char *p = str;
    while(*p){
        if( start==0 ){
            if(*p==' ' || *p=='0'){
                p++;
                continue;
            }
            else{
                start = 1;
                if(*p=='-'){
                    negtive = 1;
                    p++;
                    if(*p=='\0'){
                        return 0;
                    }
                }else if(*p=='+'){
                    p++;
                    if(*p=='\0'){
                        return 0;
                    }
                }
            }
        }
        if(*p>='0' && *p<='9'){
            if(!negtive){//0/正数
                if(INT_MAX/10>=result){
                    result *= 10;
                    tmp = *p-'0';
                    if(INT_MAX-tmp>=result){
                        result += tmp;
                        p++;
                    }else{
                        return INT_MAX;
                    }
                }
                else{
                    //return 0;
                    return INT_MAX;
                }
            }else{//负数
                if(INT_MIN/10<=result){
                    result *= 10;
                    tmp = *p-'0';
                    if(INT_MIN+tmp<=result){
                        result -= tmp;
                        p++;
                    }else{
                        return INT_MIN;
                    }
                }
                else{
                    //return 0;
                    return INT_MIN;
                }
            }
        }
        else{
            //return 0;
            break;
        }
    }
    return result;
}

void myAtoiMain(void){
    printf("%d %d\n", INT_MAX, INT_MIN);
    printf("%d\n", myAtoi("-"));
    printf("%d\n", myAtoi("4294967297"));
    printf("%d\n", myAtoi("4294967396"));
    printf("%d\n", myAtoi("12345"));
    printf("%d\n", myAtoi("-12345"));
    printf("%d\n", myAtoi("0"));
    printf("%d\n", myAtoi("1"));
    printf("%d\n", myAtoi("-10"));
    printf("%d\n", myAtoi("+10"));
    printf("%d\n", myAtoi("    000010"));
    printf("%d\n", myAtoi("    +000011"));
    printf("%d\n", myAtoi("    -000011"));
    printf("%d\n", myAtoi("    -00001q1"));
    printf("%d\n", myAtoi("-2147483648"));
    printf("%d\n", myAtoi("-2147483649"));
    printf("%d\n", myAtoi("2147483647"));
    printf("%d\n", myAtoi("2147483648"));
}

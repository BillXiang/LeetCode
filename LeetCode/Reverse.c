#include <limits.h>
int reverse(int x) {
    if(x>-10 && x<10){
        return x;
    }
    int result = 0;
    int negtive = 0;
    int tmp = 0;
    if(x<0){
        x = -x;
        negtive = 1;
    }
    while(x>0){
        if(INT_MAX/10>=result){
            result *= 10;
            tmp = x%10;
            if(INT_MAX-tmp>=result){
                result += tmp;
                x /= 10;
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }
    if(negtive){
        result = -result;
    }
    return result;
}

void reverseMain(void){
    printf("%d\n", reverse(0));
    printf("%d\n", reverse(1));
    printf("%d\n", reverse(-1));
    printf("%d\n", reverse(123));
    printf("%d\n", reverse(-123));
    printf("%d\n", reverse(100));
    printf("%d\n", reverse(-100));
    printf("%d\n", reverse(1534236469));
}

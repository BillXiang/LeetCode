/**
Implement int sqrt(int x).

Compute and return the square root of x.
**/
#include <stdio.h>

int mySqrt(int x) {
    if(x<0){
        return -1;
    }
    if(x==1){
        return 1;
    }
    int left = 0;
    int right = x;
    int mid = (left+right)>>1;
    int tmp = 0;
    while(mid!=left){
        tmp = x/mid;//用除法，不能用mid*mid和x比较，乘法可能溢出
        if(tmp<mid){
            right = mid;
        }else if(tmp>mid){
            left = mid;
        }else{
            return mid;
        }
        mid = (left+right)>>1;
    }
    return mid;
}

void mySqrtMain(void){
    printf("%d\n", mySqrt(0));
    printf("%d\n", mySqrt(1));
    printf("%d\n", mySqrt(2));
    printf("%d\n", mySqrt(3));
    printf("%d\n", mySqrt(4));
    printf("%d\n", mySqrt(5));
    printf("%d\n", mySqrt(6));
    printf("%d\n", mySqrt(7));
    printf("%d\n", mySqrt(8));
    printf("%d\n", mySqrt(9));
    printf("%d\n", mySqrt(10));
    printf("%d\n", mySqrt(2147395599));

    printf("\n%d\n", mySqrt(-1));
}

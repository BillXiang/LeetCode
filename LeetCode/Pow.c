#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double powRecursion(double x, int n){
    if(n==1){
        return x;
    }else if(n==2){
        return x*x;
    }
    double half = powRecursion(x, n/2);
    half = half*half;
    if(n&1){//奇数
        half *= x;
    }
    return half;
}

double myPow(double x, int n) {
    int nNegtive = 0;
    double result = 0.0;
    if(n<0){
        n = -n;
        nNegtive = 1;
    }else if(n==0){
        return 1;
    }

    if(fabs(1.0-x)<=1e-15){
        return 1.0;
    }else if(fabs(-1.0-x)<=1e-15){
        if(n&1){
            return -1;
        }else{
            return 1;
        }
    }

    result = powRecursion(x, n);
    if(nNegtive){
        result = 1.0/result;
    }
    return result;
}

void myPowMain(void){
    printf("%f\n", myPow(15.0, -1));
    printf("%f\n", myPow(15.0, 0));
    printf("%f\n", myPow(15.0, 1));
    printf("%f\n", myPow(15.0, 2));
    printf("%f\n", myPow(15.0, 3));
    printf("%f\n", myPow(15.0, 4));
    printf("%f\n", myPow(15.0, 5));
    printf("%f\n", myPow(15.0, 6));
    printf("%f\n", myPow(15.0, 7));

    printf("%f\n", myPow(0.00001, -1));
    printf("%f\n", myPow(0.00001, 0));
    printf("%f\n", myPow(0.00001, 1));
    printf("%f\n", myPow(0.00001, 2147483647));

    printf("%f\n", myPow(-15.0, -1));
    printf("%f\n", myPow(-15.0, 0));
    printf("%f\n", myPow(-15.0, 1));
    printf("%f\n", myPow(-15.0, 2));
    printf("%f\n", myPow(-15.0, 3));
    printf("%f\n", myPow(-15.0, 4));
    printf("%f\n", myPow(-15.0, 5));
    printf("%f\n", myPow(-15.0, 6));
    printf("%f\n\n", myPow(-15.0, 7));

    printf("%f\n", myPow(-0.00001, -1));
    printf("%f\n", myPow(-0.00001, 0));
    printf("%f\n", myPow(-0.00001, 1));
    printf("%f\n\n", myPow(-0.00001, 2147483647));

    printf("%f\n\n", myPow(1.00000, -2147483648));

    printf("%f\n\n", myPow(0.44894, -5));

    printf("%f\n", myPow(-1.00000, -2147483648));
    printf("%f\n", myPow(-1.00000, 2147483648));
    printf("%f\n", myPow(-1.00000, -2147483647));
    printf("%f\n", myPow(-1.00000, 2147483647));
}

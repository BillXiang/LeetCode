/**
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
**/

#include <stdio.h>
#include <stdlib.h>

int largestRectangleArea(int* height, int heightSize) {
    if(height==NULL || heightSize==0){
        return 0;
    }
    if(heightSize==1){
        return *height;
    }
    int i = 0;
    int largest = 0;
    int newLargest = 0;
    int smallestHeight = 0;
    int width = 0;

    int* stack = (int*)malloc((heightSize+1)*sizeof(int));
    int* pStack = stack;

    pStack++;
    *pStack = 0;
    for(i=1; i<heightSize; i++){
        if(height[i]<height[i-1]){
            while(pStack!=stack && height[i]<=height[*pStack]){
                if(pStack-1==stack){
                    width = i;
                }else{
                    width = i-*pStack;
                }
                newLargest = width*height[*pStack];
                largest = largest>newLargest?largest:newLargest;
                pStack--;
            }
            pStack++;
            height[*pStack] = height[i];
            //*pStack = i;
        }else{
            pStack++;
            *pStack = i;
        }
    }
    if(0<height[i-1]){
        while(pStack!=stack && 0<=height[*pStack]){
            if(pStack-1==stack){
                width = i;
            }else{
                width = i-*pStack;
            }
            newLargest = width*height[*pStack];
            largest = largest>newLargest?largest:newLargest;
            pStack--;
        }
    }
    free(stack);
    return largest;
}

void largestRectangleAreaMain(void){
    int height[] = //{2,1,5,6,2,3};
    //{1, 2, 3, 4, 5, 1, 1, 1, 1, 1};
    //{2,1,2};
    {4,2,0,3,2,5};
    int len = sizeof(height)/sizeof(height[0]);
    printf("%d\n", largestRectangleArea(height, len));
}

#include <stdlib.h>
//从两端往中间找，每次较低的一端先移动
int trap(int* height, int heightSize) {
    if(height==NULL || heightSize<3){
        return 0;
    }
    int traped = 0;
    int used = 0;
    int i=0, ip=0, j=heightSize-1, jp=j;

    while(i<j){
        while( height[i+1]>height[i] && i<j ){//去除左边递增的
            i++;
        }
        while( height[j-1]>height[j] && i<j ){//去除右边递减的
            j--;
        }

        while( height[i]<=height[j] && i<j ){
            used = 0;
            ip = i+1;
            //从左向右找到第一个>=当前边的边，这两条边之间可以存水，水高度为当前边高度
            //至少可以找到一个height[j]
            while( height[ip]<height[i] ){
                used += height[ip];//中间边，占用了存水空间
                ip++;
            }
            traped += (ip-i-1)*height[i]-used;
            i = ip;
        }

        while( height[j]<=height[i] && i<j ){
            used = 0;
            jp = j-1;
            //从右向左找到第一个>=当前边的边，这两条边之间可以存水，水高度为当前边高度
            //至少可以找到一个height[i]
            while( height[jp]<height[j] ){
                used += height[jp];//中间边，占用了存水空间
                jp--;
            }
            traped += (j-jp-1)*height[j]-used;
            j = jp;
        }
    }
    return traped;
}
#define GET_ARRAY_LEN(array, len) {len = sizeof(array)/sizeof(array[0]);}
void trapMain(void){
    int array[] = //{0,1,0,2,1,0,1,3,2,1,2,1};
    {0,1,0,2,1,0,1,3,2,1,2,1,0,1,0,2,1,0,1,3,2,1,2,1};
    int len = 0;
    GET_ARRAY_LEN(array, len);
    printf("%d\n", trap(array, len));
}

#include <stdlib.h>
/**
a     g     m     s     y
b   f h   l n   r t   x z
c e   i k   o q   u w
d     j     p     v
--->
agmsybfhlnrtxzceikoquwdjpv
**/
//竖线部分
#define VERTICAL_CUR_LEN(curLen, curRow, column) {curLen = curRow + 2*column*(numRows-1);}
//斜线部分
#define OBLIQUE_CUR_LEN(curLen, curRow, column) {curLen = 2*(column+1)*(numRows-1)-curRow;}
char* convert(char* s, int numRows) {
    if(s==NULL || numRows<=0)
        return NULL;
    int sLen = strlen(s);
    if(sLen<=2 || numRows==1 || numRows>=sLen)
        return s;
    char *converted = (char *)malloc(sLen+1);
    converted[sLen] = '\0';
    char *convertedP = converted;
    int curRow = 0/*当前行*/, column = 0/*当前列*/, curLen = 0;

    //curRow==0
    VERTICAL_CUR_LEN(curLen, curRow, column);
    while(curLen<sLen)
    {//第0行
        *convertedP = s[curLen];
        convertedP++;
        column++;
        VERTICAL_CUR_LEN(curLen, curRow, column);
    }

    curRow++;
    while(curRow<numRows-1)
    {//第1~(numRows-2)行
        column = 0;
        VERTICAL_CUR_LEN(curLen, curRow, column);
        while(curLen<sLen)
        {
            *convertedP = s[curLen];
            convertedP++;
            OBLIQUE_CUR_LEN(curLen, curRow, column);
            if(curLen<sLen)
            {
                *convertedP = s[curLen];
                convertedP++;
                column++;
                VERTICAL_CUR_LEN(curLen, curRow, column);
            }
        }
        curRow++;
    }
    //curRow==numRows-1
    column = 0;
    VERTICAL_CUR_LEN(curLen, curRow, column);
    while(curLen<sLen)
    {//最后一行
        *convertedP = s[curLen];
        convertedP++;
        column++;
        VERTICAL_CUR_LEN(curLen, curRow, column);
    }
    return converted;
}
//测试
void zigZagConversionMain(void)
{
    printf("%s\n", convert(
                           "abcdefghijklmnopqrstuvwxyz", 25
                           ));
}

#include <string.h>
int integer[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
char *roman[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
int SIZE = 13;
int MAX_LEN = 20;//最长15
//char result[20] = "";
int maxLen = 0;
char* intToRoman(int num) {
    if(num<=0 && num>3999)
        return NULL;
    int i=0;
    char *result = (char *)malloc(MAX_LEN);
    memset(result, 0, MAX_LEN);
    //int len = 0;
    for(i=SIZE-1; i>=0; i--){
        while(num>=integer[i]){
            strcat(result, roman[i]);
            //len += strlen(roman[i]);
            num -= integer[i];
        }
    }
    //if(len>maxLen)
    //    maxLen = len;
    return result;
}

void intToRomanMain(void){
    int i=0;
    char *result = NULL;
    for(i=0; i<4000; i++){
        result = intToRoman(i);
        printf("%s\n", result);
        free(result);
        //result[0] = '\0';
    }
    //printf("%d\n", maxLen);
}

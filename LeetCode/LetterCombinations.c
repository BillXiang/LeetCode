#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *digit2lettersMapping[]={" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int mappingLens[] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};//不包括'\0'
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    if(digits==NULL){
        *returnSize = 0;
        return NULL;
    }
    int digitsLen = 0;
    *returnSize = 1;
    int i=0;
    while(*(digits+i)!='\0'){
        *returnSize = (*returnSize) * mappingLens[*(digits+i)-'0'];
        digitsLen++;
        i++;
    }
    if(digitsLen==0){
        *returnSize = 0;
        return NULL;
    }
    digitsLen++;//长度加上一个'\0'
    char** result = (char**)malloc(*returnSize*sizeof(char*));
    for(i=0; i<*returnSize; i++){
        result[i] = malloc(digitsLen*sizeof(char));
        result[i][digitsLen-1] = '\0';
    }
    int j = 0;
    int repeat = *returnSize;
    int len = 0;
    int digitLettersIndex = 0;

    for(i=0; i<digitsLen-1; i++){
        repeat = repeat/mappingLens[digits[i]-'0'];
        len = repeat;
        for(j=0; j<*returnSize;){
            digitLettersIndex = 0;
            while(digitLettersIndex<mappingLens[digits[i]-'0']){
                while(len>0 && j<*returnSize){
                    *(*(result+j)+i) = digit2lettersMapping[digits[i]-'0'][digitLettersIndex];
                    len--;
                    j++;
                }
                len = repeat;
                digitLettersIndex++;
            }
        }
    }
    return result;
}

void letterCombinationsMain(void){
    char digits[] = "";
    int returnSize = 0;
    char **result = letterCombinations(digits, &returnSize);
    int i = 0;
    for(i=0; i<returnSize; i++){
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);
}

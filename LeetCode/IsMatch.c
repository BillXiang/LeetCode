#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//递归
bool isMatchRecursion(char* s, char* p){
    if(*s=='\0'){
        if(*p=='\0'){
            return 1;
        }else if(*(p+1)=='*'){
            return isMatchRecursion(s, p+2);
        }else{
            return 0;
        }
    }else{
        if(*s==*p || *p=='.'){
            if(*(p+1)=='*'){
                return isMatchRecursion(s, p+2)||isMatchRecursion(s+1, p)||isMatchRecursion(s+1, p+2);
            }else{
                return isMatchRecursion(s+1, p+1);
            }
        }else if(*(p+1)=='*'){
            return isMatchRecursion(s, p+2);
        }else{
            return 0;
        }
    }
}

//动规
bool isMatchDP(char* s, int sLen, int sIndex, char* p, int pLen, int pIndex, int *isMatchTable){
    if(isMatchTable[sIndex*pLen+pIndex]!=-1)
                return isMatchTable[sIndex*pLen+pIndex];

    if(*(s+sIndex)=='\0'){
        if(*(p+pIndex)=='\0'){
            isMatchTable[sIndex*pLen+pIndex] = 1;
            return 1;
        }else if(*(p+pIndex+1)=='*'){
            isMatchTable[sIndex*pLen+pIndex] = isMatchDP(s, sLen, sIndex, p, pLen, pIndex+2, isMatchTable);
            return isMatchTable[sIndex*pLen+pIndex];
        }else{
            isMatchTable[sIndex*pLen+pIndex] = 0;
            return 0;
        }
    }else if(*(p+pIndex)=='\0'){
        isMatchTable[sIndex*pLen+pIndex] = 0;
        return 0;
    }else{
        if(*(s+sIndex)==*(p+pIndex) || *(p+pIndex)=='.'){
            if(*(p+pIndex+1)=='*'){
                isMatchTable[sIndex*pLen+pIndex] = isMatchDP(s, sLen, sIndex, p, pLen, pIndex+2, isMatchTable)
                                                ||isMatchDP(s, sLen, sIndex+1, p, pLen, pIndex, isMatchTable)
                                                ||isMatchDP(s, sLen, sIndex+1, p, pLen, pIndex+2, isMatchTable);
                return isMatchTable[sIndex*pLen+pIndex];
            }else{
                isMatchTable[sIndex*pLen+pIndex] = isMatchDP(s, sLen, sIndex+1, p, pLen, pIndex+1, isMatchTable);
                return isMatchTable[sIndex*pLen+pIndex];
            }
        }else if(*(p+pIndex+1)=='*'){
            isMatchTable[sIndex*pLen+pIndex] = isMatchDP(s, sLen, sIndex, p, pLen, pIndex+2, isMatchTable);
            return isMatchTable[sIndex*pLen+pIndex];
        }else{
            isMatchTable[sIndex*pLen+pIndex] = 0;
            return 0;
        }
    }
}

bool isMatch(char* s, char* p) {
    int *isMatchTable;
    if(s==NULL)
        return p==NULL;
    if(p==NULL)
        return 0;
    int sLen = strlen(s)+1;
    int pLen = strlen(p)+1;
    isMatchTable = (int *)malloc(sLen*pLen*sizeof(int));
    int i=0, j=0;
    for(i=0; i<sLen; i++){
        for(j=0; j<pLen; j++){
            isMatchTable[i*pLen+j] = -1;
        }
    }
    int result = isMatchDP(s, sLen, 0, p, pLen, 0, isMatchTable);
    free(isMatchTable);
    return result;
    //return isMatchRecursion(s, p);
}


void isMatchMain(void){
    printf("%d\n", isMatch("aa","a"));
    printf("%d\n", isMatch("aa","aa"));
    printf("%d\n", isMatch("aaa","aa"));
    printf("%d\n", isMatch("aa", "a*"));
    printf("%d\n", isMatch("aa", ".*"));
    printf("%d\n", isMatch("ab", ".*"));
    printf("%d\n", isMatch("aab", "c*a*b"));
    printf("%d\n", isMatch("ab", ".*c"));
    printf("%d\n", isMatch("aaa", "ab*a*"));
    printf("%d\n", isMatch("aaa", "ab*a*c*a"));
    printf("%d\n", isMatch("aasdfasdfasdfasdfas", "aasdf.*asdf.*asdf.*asdf.*s"));
    printf("%d\n", isMatch("baccbbcbcacacbbc", "c*.*b*c*ba*b*b*.a*"));
}

#include <stdlib.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0;
    int len = 0;
    char *result = NULL;
    if(strs==NULL || strsSize==0){
        return "";
    }
    while(1){
        for(i=0; i<strsSize; i++){
            if(strs[i][len]=='\0' || strs[i][len]!=strs[0][len]){
                result = (char*)malloc(len+1);
                for(i=0; i<len; i++){
                    result[i] = strs[0][i];
                }
                result[len] = '\0';
                return result;
            }
        }
        len++;
    }
}

#define GET_ARRAY_LEN(array, len) {len = sizeof(array)/sizeof(array[0]);}

void longestCommonPrefixMain(void){
    char *strs[] = {"aqwerr",
    "aqwert",
    "aqwerty",
    "aqwertyu"
    };
    int strsSize = 0;
    GET_ARRAY_LEN(strs, strsSize);
    printf("%s\n",longestCommonPrefix(strs, strsSize));
    printf("%s\n",longestCommonPrefix(NULL, strsSize));
    printf("%s\n",longestCommonPrefix(strs, 0));
}

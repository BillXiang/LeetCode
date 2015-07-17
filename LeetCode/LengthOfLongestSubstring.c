#include <stdlib.h>
int hash[256][2];

int lengthOfLongestSubstring(char* s) {
    if(!s)
        return 0;
    int len = 0, newLen = 0;
    int it = 1;

    int hashIndex = 0;
    int stringIndex = 0;

    memset(hash, 0, sizeof(int)*256*2);
    while(*(s+stringIndex))
    {
        hashIndex = *(s+stringIndex);
        if(hash[hashIndex][1]==it)//本次迭代遇到重复字母，进行下次迭代
        {
            len = len>newLen?len:newLen;//更新最长长度
            newLen = 0;
            stringIndex = hash[hashIndex][2]+1;//下一次迭代起始位置为重复字母的下一个
            it++;//迭代次数增一
        }
        else
        {
            newLen++;
            hash[hashIndex][1] = it;
            hash[hashIndex][2] = stringIndex;
            stringIndex++;
        }
    }
    return len>newLen?len:newLen;//更新最长长度
}
//测试
void lengthOfLongestSubstringMain(void)
{
    char s[] = "bba";//"abcdabbcdegbb";
    printf("%d\n", lengthOfLongestSubstring(NULL));
}

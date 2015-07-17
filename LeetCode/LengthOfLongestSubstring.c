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
        if(hash[hashIndex][1]==it)//���ε��������ظ���ĸ�������´ε���
        {
            len = len>newLen?len:newLen;//���������
            newLen = 0;
            stringIndex = hash[hashIndex][2]+1;//��һ�ε�����ʼλ��Ϊ�ظ���ĸ����һ��
            it++;//����������һ
        }
        else
        {
            newLen++;
            hash[hashIndex][1] = it;
            hash[hashIndex][2] = stringIndex;
            stringIndex++;
        }
    }
    return len>newLen?len:newLen;//���������
}
//����
void lengthOfLongestSubstringMain(void)
{
    char s[] = "bba";//"abcdabbcdegbb";
    printf("%d\n", lengthOfLongestSubstring(NULL));
}

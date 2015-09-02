#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s)
{
    char *start, *end, *sp=s, *oldS, *head=s;
    int curLen=0, len=0, newPa=0;
    if(s==NULL || s[0]=='\0' || s[1]=='\0')
        return s;

    s++;
    while(*s)
    {
        if(*s==*sp && sp>=head)//遇到相同的字母，偶数的回文
        {
            if(sp+1==s)//新的回文
            {
                curLen = 2;
                newPa = 1;//新的回文

                s++;
                while(*s && (*s==*sp))//重复的字符
                {
                    curLen++;
                    s++;
                }
                oldS = sp+1;

                sp--;
            }
            else if(newPa)//正在处理回文
            {
                curLen += 2;
                sp--;
                s++;
            }
        }
        else if( *(s+1) && (sp+1==s) && (*(s+1)==*sp) )//奇数的回文
        {
            oldS = s;

            curLen = 3;

            newPa = 1;
            s += 2 ;
            sp--;
        }
        else if(newPa)//正在处理回文，遇到不同字母，结束
        {
            if(curLen>len)
            {
                start = sp+1;
                end = s-1;
                len = curLen;
            }
            s = oldS+1;

            newPa = 0;//回文结束
            sp = s-1;
        }
        else
        {
            sp++;
            s++;
        }
    }
    if(newPa)//回文到字符串末尾
    {
        if(curLen>len)
        {
            start = sp+1;
            end = s-1;
        }
    }

    *(end+1) = '\0';
    return start;
}

//求最长公共子串
char* longestCommonSubString(char* s1, int len1, char* s2, int len2){
    int i;
    int j;
    int maxI = 0;
    int maxJ = 0;
    int maxLength = 0;

    int* matchTable[2];
    for(i=0; i<2; i++){
        matchTable[i] = (int*)malloc((len2+1)*sizeof(int));
        if(matchTable[i]==NULL){
            printf("OOM1\n");
            exit(0);
        }
    }
    for(i=0; i<len2+1; i++){
        matchTable[0][i] = 0;
        matchTable[1][i] = 0;
    }

    int iIndex = 0;
    for(i=len1-1; i>=0; i--){
        for(j=len2-1; j>=0; j--){
            if(s1[i]==s2[j]){
                matchTable[iIndex][j] = matchTable[iIndex==0][j+1]+1;
                if(maxLength<matchTable[iIndex][j]){
                    maxLength = matchTable[iIndex][j];
                    maxI = i;
                    maxJ = j;
                }
            }
            else{
                matchTable[iIndex][j] = 0;
            }
        }
        iIndex = (iIndex==0);//换行
    }
    for(i=0; i<2; i++){
        free(matchTable[i]);
    }
    s2[maxLength] = '\0';
    for(i=0; i<maxLength; i++){
        s2[i] = s1[maxI];
        maxI++;
    }
    return s2;
}

//通过求与其自身反转的最长公共子串求得
char* longestPalindrome2(char* s){
    //先获得反转后的字符串
    int len = strlen(s);
    char* reversed = (char *)malloc((len+1)*sizeof(char));
    if(reversed==NULL){
        printf("OOM3\n");
        exit(0);
    }
    reversed[len] = '\0';
    int i = 0;
    for(i=0; i<len; i++){
        reversed[i] = s[len-1-i];
    }
    char* result = longestCommonSubString(s, len, reversed, len);
    return result;
}

//测试
void longestPalindromeMain(void)
{
    char s[] =
    //"aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaa";
    //"aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaa"
    //"aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaa"
    //"aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaa"
    //"aaabaaaa";
    //"ababababa";//奇数回文结束时要回滚
    //"bananas";//奇数回文结束时要回滚
    //"abaddca";
    //"cccccc";//重复字符
    "gfsdabcddcbagteabcdaadcbaetsg";
    //"abbaaaaaaaabba";
    //"civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
//    char* result = longestPalindrome(s);
//    printf("%s\n", longestPalindrome(s));
//    free(result);
    char* result = longestPalindrome2(s);
    printf("%s\n", result);
    free(result);
}

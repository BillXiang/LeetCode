#include <stdio.h>
/**
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
"((()))", "(()())", "(())()", "()(())", "()()()"
**/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 /**
 每增加一对括号，在上一次左边或者右边或者套上
 f(1) = 1;
 f(n) = (1/2)*3^(n-1)+(1/2) = floor( (1/2)*3^(n-1) )+1;
 **/

#include <math.h>
#include <stdlib.h>
#include <string.h>

char** generateParenthesis(int n, int* returnSize) {
    if(n<1){
        return NULL;
    }
    *returnSize = (((int)pow(3, n-1))>>1) + 1;
    char** result = (char**)malloc( (*returnSize)*sizeof(char*));

    int i = 0;
    int len = ((n<<1)+1);

    for(i=0; i<*returnSize; i++){
        result[i] = (char*)malloc( len*sizeof(char) );
        result[i][len-1] = '\0';
    }

    //初始只有一对括号在结果集中
    result[0][0]='(';
    result[0][1]=')';
    result[0][2]='\0';
    if(n==1){
        return result;
    }

    int count = 1;//初始括号对数，初始为1
    int curResultSize = 1;//当前字符串个数，初始为1
    int newResultSize = 2;

    int curLen = 2;//

    int lastIndex = 0;//添加新字符串时的位置
    while(count<n){
        count++;//当前括号对数

        //新括号对数为count时结果集大小
        newResultSize = (((int)pow(3, count-1))>>1) + 1;
        lastIndex = newResultSize-1;

        curLen = count<<1;//当前字符串长度，等于括号对数乘以2
        while(curResultSize>1){
            //将其弹出，左边添加，右边添加，套起来
            //左边添加，将curResultSize-1复制到lastIndex，左边预留两个字符用于添加()
            strcpy(&result[lastIndex][2], &result[curResultSize-1][0]);
            result[lastIndex][curLen] = '\0';
            result[lastIndex][0] = '(';
            result[lastIndex][1] = ')';

            lastIndex--;
            //右边添加，将curResultSize-1复制到lastIndex
            strcpy(&result[lastIndex][0], &result[curResultSize-1][0]);
            result[lastIndex][curLen] = '\0';
            result[lastIndex][curLen-1] = ')';
            result[lastIndex][curLen-2] = '(';

            lastIndex--;
            //括起来，将curResultSize-1复制到lastIndex，左边预留一个字符用于添加(
            strcpy(&result[lastIndex][1], &result[curResultSize-1][0]);
            result[lastIndex][curLen] = '\0';
            result[lastIndex][curLen-1] = ')';
            result[lastIndex][0] = '(';

            lastIndex--;

            curResultSize--;
        }
        //curResultSize等于1时，只在右边添加，和套起来
        //将curResultSize-1复制到1，为1的左边预留一位字符，后面将1阔来需要在左面接一个(
        strcpy(&result[1][1], &result[curResultSize-1][0]);
        //将原字符串括起来
        result[1][curLen] = '\0';
        result[1][curLen-1] = ')';
        result[1][0] = '(';

        //在原字符串右边增加一对括号
        result[0][curLen] = '\0';
        result[0][curLen-1] = ')';
        result[0][curLen-2] = '(';

        //当括号对数为count时结果集大小
        curResultSize = newResultSize;
    }

    return result;
}

void generateParenthesisMain(voia){
    int returnSize = 0;
    char** result = generateParenthesis(4, &returnSize);
    while(returnSize>0){
        printf("%s\n", result[returnSize-1]);
        free(result[returnSize-1]);
        returnSize--;
    }
    free(result);
}
/**
java code : 采用递归树的思想，当左括号数大于右括号数时可以加左或者右括号，
否则只能加左括号，当左括号数达到n时，剩下全部加右括号。
public class Solution {
    public ArrayList<String> generateParenthesis(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ArrayList<String> res = new ArrayList<String>();
        generate(res, "", 0, 0, n);
        return res;
    }
    public void generate(ArrayList<String> res, String tmp, int lhs, int rhs, int n)
    {
        if(lhs == n)
        {
            for(int i = 0; i < n - rhs; i++)
            {
                tmp += ")";
            }
            res.add(tmp);
            return ;
        }
        generate(res, tmp + "(", lhs + 1, rhs, n);
        if(lhs > rhs)
            generate(res, tmp + ")", lhs, rhs + 1, n);
    }
}
**/

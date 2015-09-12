/**
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
**/
#include <string>
#include <algorithm>
using namespace std;
class Solution {
private:
    int*** isScrambleTable;
    bool isScramble(string s1, int start1, string s2, int start2, int length) {
        if(isScrambleTable[start1][start2][length]!=-1){
            return isScrambleTable[start1][start2][length];
        }

        int length1 = s1.length();
        int length2 = s2.length();
        if(length1!=length2){//长度不同，肯定不符合
            return false;
        }
        string ss1=s1, ss2=s2;
        sort(ss1.begin(), ss1.end());
        sort(ss2.begin(), ss2.end());
        if(ss1.compare(ss2)){//存在字符不相同，肯定不符合
            isScrambleTable[start1][start2][length] = 0;
            return false;
        }else if(length1==1){//只有一个字符，而且相同，符合
            isScrambleTable[start1][start2][length] = 1;
            return true;
        }
        //字符都相同，进一步判断
        for(int i=0; i<length1-1; i++){
            string ls1 = s1.substr(0, i+1);
            string rs1 = s1.substr(i+1, length1-i-1);
            string ls2 = s2.substr(0, i+1);
            string rs2 = s2.substr(i+1, length1-i-1);
            if( isScramble(ls1, start1, ls2, start2, i+1)&&isScramble(rs1, start1+i+1, rs2, start2+i+1, length1-i-1) ){
                isScrambleTable[start1][start2][length] = 1;
                return true;
            }else{
                string ls2 = s2.substr(length1-i-1, i+1);
                string rs2 = s2.substr(0, length1-i-1);
                if( isScramble(ls1, start1, ls2, start2+length1-i-1, i+1)&&isScramble(rs1, start1+i+1, rs2, start2, length1-i-1) ){
                    isScrambleTable[start1][start2][length] = 1;
                    return true;
                }else{


                }
            }
        }
        isScrambleTable[start1][start2][length] = 0;
        return false;
    }
public:
    bool isScramble(string s1, string s2) {
        int length1 = s1.length();
        int length2 = s2.length();
        if(length1!=length2){
            return false;
        }else if(length1==0){
            return true;
        }
        if(s1.compare(s2)==0){
            return true;
        }
        string ss1=s1, ss2=s2;
        sort(ss1.begin(), ss1.end());
        sort(ss2.begin(), ss2.end());
        if(ss1.compare(ss2)){
            return false;
        }
        isScrambleTable = new int**[length1]();

        for(int i=0; i<length1; i++){
            isScrambleTable[i] = new int*[length1]();
            for(int j=0; j<length1; j++){
                isScrambleTable[i][j] = new int[length1+1]();
                for(int k=0; k<length1+1; k++){
                    isScrambleTable[i][j][k] = -1;
                }
            }
        }

        bool result = isScramble(s1, 0, s2, 0, length1);

        for(int i=0; i<length1; i++){
            for(int j=0; j<length1; j++){
                delete[] isScrambleTable[i][j];
            }
            delete[] isScrambleTable[i];
        }
        delete[] isScrambleTable;

        return result;
    }
};

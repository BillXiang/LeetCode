/**
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
**/
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

class Solution {
private:
    int** result;

    int minDistance(string word1, int start1, string word2, int start2) {
        if(word1[start1]=='\0'){
            return word2.length()-start2;
        }else if(word2[start2]=='\0'){
            return word1.length()-start1;
        }
        if(result[start1+1][start2+1]==-1){
            result[start1+1][start2+1] = minDistance(word1, start1+1, word2, start2+1);
        }
        int a = result[start1+1][start2+1];
        if(word1[start1]==word2[start2]){
            return a;
        }else{
            if(result[start1+1][start2]==-1){
                result[start1+1][start2] = minDistance(word1, start1+1, word2, start2);
            }
            int b = result[start1+1][start2];

            if(result[start1][start2+1]==-1){
                result[start1][start2+1] = minDistance(word1, start1, word2, start2+1);
            }
            int c = result[start1][start2+1];
            return ( a>b?(b>c?c:b):(a>c?c:a) )+1;
        }
    }
public:
    int minDistance(string word1, string word2) {
        int length1 = word1.length()+1;
        int length2 = word2.length()+1;
        result = new int*[length1];
        for(int i=0; i<length1; i++){
            result[i] = new int[length2];
            for(int j=0; j<length2; j++){
                result[i][j] = -1;
            }
        }
        int distance = minDistance(word1, 0, word2, 0);
        for(int i=0; i<length1; i++){
            delete result[i];
        }
        delete result;
        return distance;
    }
};

void minDistanceMain(void){
    cout<<Solution().minDistance("", "")<<endl;
    cout<<Solution().minDistance("1", "")<<endl;
    cout<<Solution().minDistance("", "1")<<endl;
    cout<<Solution().minDistance("1", "1")<<endl;
    cout<<Solution().minDistance("1", "0")<<endl;
    cout<<Solution().minDistance("11", "00")<<endl;
    cout<<Solution().minDistance("11", "1")<<endl;
}

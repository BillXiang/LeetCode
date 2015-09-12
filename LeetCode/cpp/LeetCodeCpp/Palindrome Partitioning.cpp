/**
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
**/
#include <vector>
#include <string>
#include <iostream>
#include <list>
using namespace std;

class Solution {
private:
    vector<list<string>>* subResultTable;//还是用vector<vector<string>>更好
    bool* solved;
    int** isPalindromeTable;
//    int stringLength;
//    bool isPalindrome(string s, int start){
//        int length = s.length();
//        if(isPalindromeTable[start][length]!=-1){
//            return isPalindromeTable[start][length];
//        }else if(start>0 && start+length<stringLength && isPalindromeTable[start-1][length+2]==1){
//            isPalindromeTable[start][length] = true;
//            return true;
//        }
//        int i=0, j=s.length()-1;
//        while(i<j){
//            if(s[i]!=s[j]){
//                isPalindromeTable[start][length] = false;
//                return false;
//            }
//            i++;
//            j--;
//        }
//        isPalindromeTable[start][length] = true;
//        return true;
//    }
    bool isPalindrome(string s, int start, int length){
        if( length==1 ||
           ( s[start]==s[start+length-1]
           && (length==2 || isPalindromeTable[start+1][length-2]) ) ){
            isPalindromeTable[start][length] = true;
            return true;
        }else{
            isPalindromeTable[start][length] = false;
            return false;
        }
//        int i=0, j=s.length()-1;
//        while(i<j){
//            if(s[i]!=s[j]){
//                isPalindromeTable[start][length] = false;
//                return false;
//            }
//            i++;
//            j--;
//        }
//        isPalindromeTable[start][length] = true;
//        return true;
    }
    vector<list<string>> myPartition(string s, int start) {
        if(solved[start]){
            return subResultTable[start];
        }
        vector<list<string>> result;
//        if(isPalindrome(s, start)){
        if(isPalindromeTable[start][s.length()]){
            list<string> tmp = {s};//自身就是回文，构成一个划分
            result.push_back(tmp);
        }
        unsigned int length = s.length();
        for(unsigned int i=0; i<length-1; i++){
            string subStr = s.substr(0, i+1);
//            if(isPalindrome(subStr, start)){
            if(isPalindromeTable[start][subStr.length()]){
                vector<list<string>> subResult = myPartition(s.substr(i+1, length-i-1), start+i+1);
                //list<list<string>>::iterator iteEnd = subResult.end();
                for(unsigned int j=0; j<subResult.size(); j++){
                //for(list<list<string>>::iterator ite=subResult.begin(); ite!=iteEnd; ite++)
                    subResult[j].push_front(subStr);
                    result.push_back(subResult[j]);
                }
            }
        }
        subResultTable[start] = result;
        return result;
    }
public:
    vector<vector<string>> partition(string s) {
        int stringLength = s.length();
        vector<vector<string>> result;
        if(stringLength==0){
            return result;
        }
        subResultTable = new vector<list<string>>[stringLength]();
        solved = new bool[stringLength]();
        isPalindromeTable = new int*[stringLength]();
        for(int i=0; i<stringLength; i++){
            isPalindromeTable[i] = new int[stringLength+1]();
            isPalindromeTable[i][1] = 1;//单个字符肯定是回文
            for(int j=2; j<stringLength+1; j++){
                isPalindromeTable[i][j] = -1;
            }
        }
        for(int i=2; i<=stringLength; i++){
            for(int j=0; j+i<=stringLength; j++){
                //以j开头的，长度为i的子串
                isPalindrome(s, j, i);
            }
        }
        vector<list<string>> listResult = myPartition(s, 0);
        result.resize(listResult.size());
        for(int i=0; i<listResult.size(); i++){
            list<string>::iterator ite2End = listResult[i].end();
            vector<string> tmp(listResult[i].size());
            int j=0;
            for(list<string>::iterator ite2=listResult[i].begin(); ite2!=ite2End; ite2++, j++){
                tmp[j] = *ite2;
            }
            result[i] = tmp;
        }
        delete[] subResultTable;
        delete[] solved;
        for(int i=0; i<stringLength; i++){
            delete[] isPalindromeTable[i];
        }
        delete[] isPalindromeTable;
        return result;
    }
};

void partitionMain(void){
    vector<vector<string>> result = Solution().partition("abaacasdgsdgsfasteyteydddfggfdffdabaacasdgsdgsfasteyteydddfggfdffd");
    for(vector<vector<string>>::iterator ite1=result.begin(); ite1!=result.end(); ite1++){
        for(vector<string>::iterator ite2=(*ite1).begin(); ite2!=(*ite1).end(); ite2++){
            //cout<<*ite2<<" ";
        }
        //cout<<endl;
    }
}

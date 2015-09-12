/**
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
**/
#include <unordered_set>
#include <stdbool.h>
#include <string>
using namespace std;
class Solution {
private:
    int* canWordBreak;
    bool wordBreak(string s, unsigned int start, unordered_set<string>& wordDict){
        if(start==s.length()){
            canWordBreak[start] = 1;
            return true;
        }
        for(unsigned int i=start; i<s.length(); i++){
            if( wordDict.find( s.substr(start, i-start+1) )!=wordDict.end() ){
                if(canWordBreak[i+1]==-1){
                    //canWordBreak[i+1] =
                    wordBreak(s, i+1, wordDict);
                }
                if(canWordBreak[i+1]==1){
                    canWordBreak[start] = 1;
                    return true;
                }
            }
        }
        canWordBreak[start] = 0;
        return false;
    }
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        canWordBreak = new int[s.length()+1];
        for(unsigned int i=0; i<s.length()+1; i++){
            canWordBreak[i] = -1;
        }
        bool result = wordBreak(s, 0, wordDict);
        delete canWordBreak;
        return result;
    }
};

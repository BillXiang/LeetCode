/**
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
**/
#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<string> *subResults;
    char *canBreak;
    void wordBreak(string s, unsigned int start, unordered_set<string>& wordDict){
        if(start==s.length()){
            canBreak[start] = 1;
        }else{
            for(unsigned int i=start; i<s.length(); i++){
                string subString = s.substr(start, i-start+1);
                if( wordDict.find(subString)!=wordDict.end() ){
                    if(canBreak[i+1]==-1){
                        wordBreak(s, i+1, wordDict);
                    }
                    if(canBreak[i+1]==1){
                        int subLength = subResults[i+1].size();
                        if(subLength==0){
                            subResults[start].push_back(subString);
                        }else{
                            for(int j=0; j<subLength; j++){
                                subResults[start].push_back(subString+" "+subResults[i+1][j]);
                            }
                        }
                        canBreak[start] = 1;
                    }
                }
            }
            canBreak[start] = (canBreak[start]==1);
        }
    }
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> emptyResult;
        if(wordDict.size()==0){
            return emptyResult;
        }
        unsigned int length = s.length()+1;
        subResults = new vector<string>[length]();
        canBreak = new char[length]();
        for(unsigned int i=0; i<length; i++){
            canBreak[i] = -1;
        }
        wordBreak(s, 0, wordDict);
        for(unsigned int i=0; i<length; i++){
            if(subResults[i].size()!=0){
                vector<string> result = subResults[i];
                delete[] subResults;
                delete canBreak;
                return result;
            }
        }
        delete[] subResults;
        delete canBreak;
        return emptyResult;
    }
};

void wordBreakII(void){
    unordered_set<string> wordDict = //{"cat", "cats", "and", "sand", "dog"};
    {"a"};
    vector<string> result = Solution().wordBreak(//"catsanddog",
                                                 "a",
                                                 wordDict);
    for(vector<string>::iterator ite=result.begin(); ite!=result.end(); ite++){
        cout<<*ite<<endl;
    }
}

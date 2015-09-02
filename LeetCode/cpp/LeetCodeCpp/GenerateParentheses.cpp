/**
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
**/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
private:
    void generateParenthesis(string parenthesis, int n, int leftN, int rightN, vector<string> &result){
        if(leftN==n){
            //左括号数已经达到最大值，只能添加右括号
            int i = n-rightN;
            string l = parenthesis;
            for(; i>0; i--){
                l += ')';
            }
            result.push_back(l);
        }else{
            string l = parenthesis+'(';
            generateParenthesis(l, n, leftN+1, rightN, result);
            if(rightN<leftN){
                string r = parenthesis+')';
                generateParenthesis(r, n, leftN, rightN+1, result);
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesis("", n, 0, 0, result);
        return result;
    }
};

void generateParenthesisMain(void){
    vector<string> result = Solution().generateParenthesis(4);
    for(vector<string>::iterator iter=result.begin(); iter!=result.end(); iter++){
        cout<<*iter<<endl;
    }
}

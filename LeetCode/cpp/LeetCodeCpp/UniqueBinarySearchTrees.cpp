/**
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
**/
#include <iostream>
using namespace std;

class Solution {
private:
    int* numTreesI;
    int getNumTrees(int n){
        if(n<=1){
            return 1;
        }
        if(numTreesI[n]!=-1){
            return numTreesI[n];
        }
        int result = 0;
        for(int i=0; i<n; i++){
            result += getNumTrees(i)*getNumTrees(n-i-1);
        }
        numTreesI[n] = result;
        return result;
    }
public:
    int numTrees(int n) {
        numTreesI = new int[n+1]();
        for(int i=0; i<n+1; i++){
            numTreesI[i] = -1;
        }
        int result = getNumTrees(n);
        delete numTreesI;
        return result;
    }
};

void numTreesMain(void){
    cout<<Solution().numTrees(12)<<endl;
}

/**
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
**/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector< vector<int> > subsetsWithDup(vector<int>& nums) {
        int sizeofNums = nums.size();
        vector< vector<int> > results;
        results.push_back(vector<int>());
        if(sizeofNums==0){
            return results;
        }
        std::sort(nums.begin(), nums.end());
        int lastAdd = 1;
        for(int i=0; i<sizeofNums; i++){
            int sizeofResult = results.size();
            int j = 0;
            if(i>0 && nums[i]==nums[i-1]){
                j = lastAdd;
            }
            for(; j<sizeofResult; j++){
                vector<int> newSubSet(results[j]);
                newSubSet.push_back(nums[i]);
                results.push_back(newSubSet);
            }
            lastAdd = sizeofResult;
        }
        return results;
    }
};

/**
Given a set of distinct integers, nums, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
**/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector< vector<int> > subsets(vector<int>& nums) {
        int sizeofNums = nums.size();
        vector< vector<int> > results;
        results.push_back(vector<int>());
        if(sizeofNums==0){
            return results;
        }
        std::sort(nums.begin(), nums.end());
        for(int i=0; i<sizeofNums; i++){
            int sizeofResult = results.size();
            for(int j=0; j<sizeofResult; j++){
                vector<int> newSubSet(results[j]);
                newSubSet.push_back(nums[i]);
                results.push_back(newSubSet);
            }
        }
        return results;
    }
};

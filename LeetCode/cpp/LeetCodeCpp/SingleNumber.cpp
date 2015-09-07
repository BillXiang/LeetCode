/**
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
**/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sizeOfNums = nums.size();
//        if(sizeOfNums<=2){
//            return -1;
//        }
        int result = 0;

        for(int i=0; i<sizeOfNums; i++){
            result ^= nums[i];
        }
        return result;
    }
    /**
    Given an array of integers, every element appears three times except for one. Find that single one.
    Note:
    Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
    **/
    int singleNumberII(vector<int>& nums) {
        int sizeOfNums = nums.size();
        int sizeOfInt = sizeof(int)*8;
        int numsOfOne[sizeof(int)*8] = {0};
        int result = 0;

        for(int i=0; i<sizeOfInt; i++){
            for(int j=0; j<sizeOfNums; j++){
                numsOfOne[i] += (nums[j]>>i)&1;
            }
            result |= (numsOfOne[i]%3)<<i;
        }
        return result;
    }
};

void singleNumberIIMain(void){
    int numsArray[] = {0,1,0,1,0,1,99};
    vector<int> numsVector(numsArray, numsArray+7);
    cout<<Solution().singleNumberII(numsVector)<<endl;
}

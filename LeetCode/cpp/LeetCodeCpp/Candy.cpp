/**
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?
**/
#include <vector>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int nOfChildren = ratings.size();
        int numsOfCandy[nOfChildren];
        int sum = 0;
        numsOfCandy[0] = 1;
        for(int i=1; i<nOfChildren; i++){
            if(ratings[i]>ratings[i-1]){
                numsOfCandy[i] = numsOfCandy[i-1]+1;
            }else{
                numsOfCandy[i] = 1;
            }
        }
        sum = numsOfCandy[nOfChildren-1];
        for(int i=nOfChildren-2; i>=0; i--){
            if(ratings[i]>ratings[i+1] && numsOfCandy[i]<=numsOfCandy[i+1]){
                numsOfCandy[i] = numsOfCandy[i+1]+1;
            }
            sum += numsOfCandy[i];
        }
        return sum;
    }
};

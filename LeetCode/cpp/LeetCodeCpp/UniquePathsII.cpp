/**
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

The total number of unique paths is 2.

Note: m and n will be at most 100.
**/
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(m==0 || n==0){
            return -1;
        }
        if(m==1){
            for(int i=0; i<n; i++){
                if(obstacleGrid[0][i]==1){
                    return 0;
                }
            }
            return 1;
        }
        if(n==1){
            for(int i=0; i<m; i++){
                if(obstacleGrid[i][0]==1){
                    return 0;
                }
            }
            return 1;
        }

        int isZero = obstacleGrid[m-1][n-1]==0;
        if(!isZero){
            return 0;//目标地址标记为1，不可达
        }
        for(int i=m-2; i>=0; i--){//最后一行
            isZero = isZero && (obstacleGrid[i][n-1]==0);
            obstacleGrid[i][n-1] = isZero;
        }
        isZero = 1;
        for(int i=n-2; i>=0; i--){//最后一列
            isZero = isZero && (obstacleGrid[m-1][i]==0);
            obstacleGrid[m-1][i] = isZero;
        }
        for(int i=m-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                obstacleGrid[i][j] = obstacleGrid[i][j]==0?(obstacleGrid[i+1][j]+obstacleGrid[i][j+1]):0;
            }
        }
        return obstacleGrid[0][0];
    }
};

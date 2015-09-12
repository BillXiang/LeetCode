/**
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
**/
#include <string.h>
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<=1 || n<=1){
            return 1;
        }
        int **table = new int*[m+1]();
        for(int i=0; i<m+1; i++){
            table[i] = new int[n];
            table[i][n-1] = 1;
        }
        memset(table[m], 0, n*sizeof(int));

        for(int i=m-1; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                table[i][j] = table[i+1][j] + table[i][j+1];
            }
        }

        int result = table[0][0];

        for(int i=0; i<m+1; i++){
            delete[] table[i];
        }
        delete[] table;

        return result;
    }
};

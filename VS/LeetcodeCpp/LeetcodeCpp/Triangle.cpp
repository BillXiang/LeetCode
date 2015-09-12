/**
Given a triangle, find the minimum path sum from top to bottom.
Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space,
where n is the total number of rows in the triangle.
**/
#include "stdafx.h"
#include <vector>
#include <limits.h>
#include <iostream>
using namespace std;

class Solution {
private:
	int myMin(int a, int b){
		return a>b ? b : a;
	}
	int myMin(int a, int b, int c){
		return a>b ? (b>c ? c : b) : (a<c ? a : c);
	}
public:
	int minimumTotal(vector< vector<int> >& triangle) {
		int rows = triangle.size();
		if (rows == 0){
			return 0;
		}
		int result = INT_MAX;
		int tmp[2][rows];
		int tmpRow = 0;
		tmp[0][0] = triangle[0][0];
		for (int i = 1; i<rows; i++){//遍历每一行
			tmpRow = !tmpRow;
			for (int j = 0; j<i + 1; j++){//遍历每一列
				if (j == 0){
					if (i == 1){
						tmp[tmpRow][j] = triangle[i][j] + tmp[!tmpRow][j];
					}
					else{
						tmp[tmpRow][j] = triangle[i][j] + myMin(tmp[!tmpRow][j], tmp[!tmpRow][j + 1]);
					}
				}
				else if (j == i - 1){
					tmp[tmpRow][j] = triangle[i][j] + myMin(tmp[!tmpRow][j - 1], tmp[!tmpRow][j]);
				}
				else if (j == i){
					tmp[tmpRow][j] = triangle[i][j] + tmp[!tmpRow][j - 1];
				}
				else{
					tmp[tmpRow][j] = triangle[i][j] + myMin(tmp[!tmpRow][j - 1], tmp[!tmpRow][j], tmp[!tmpRow][j + 1]);
				}
			}
		}
		for (int i = 0; i<rows; i++){
			if (tmp[tmpRow][i]<result){
				result = tmp[tmpRow][i];
			}
		}
		return result;
	}
};
void minimumTotalMain(void){
	int arr1[] = { 1 };
	vector<int> v1(arr1, arr1 + 1);
	int arr2[] = { 2, 3 };
	vector<int> v2(arr2, arr2 + 2);
	vector<int> arr[] = { v1, v2 };
	vector< vector<int> > v(arr, arr + 2);

	cout << Solution().minimumTotal(v) << endl;
}

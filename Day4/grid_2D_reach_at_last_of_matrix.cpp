#include <bits/stdc++.h> 
using namespace std;

// t.c = O(M * N) s.c = O(M*N) + O(M+N)[for auxillary space stack of the recursion]
// memoization -> Bottom-up [thats why uses left and up]
int f(int row, int col, vector<vector<int>>&dp){
	if(row == 0 && col == 0)	return 1;
	if(dp[row][col] != -1)	return dp[row][col];
	int left = 0;
	if(col-1>=0)	left += f(row, col-1, dp);
	int up = 0;
	if(row-1>=0)	up += f(row-1, col, dp);

	return dp[row][col] = left + up;
}

// tabulation -> top-down dp	[thats why uses right down]
// t.c = O(row * col), s.c = O(row * col) [save the recursive call stack space.]
// int f(int row, int col){
// 	vector<vector<int>>dp(row, vector<int>(col, -1));
// 	dp[0][0] = 1;

// 	for(int r=0; r<row; r++){
// 		for(int c=0; c<col; c++){
// 			if(r != 0 || c != 0){
// 				int right = 0;
// 				if(c-1>=0)	right += dp[r][c-1];
// 				int down = 0;
// 				if(r-1 >=0) down += dp[r-1][c];

// 				dp[r][c] = right + down;
// 			}
// 		}
// 	}
// 	return dp[row-1][col-1];
// }

int f(int m, int n){

	vector<int>prevRow(n,0);

	for(int row=0; row<m; row++){
		vector<int>prevCol(n,0);
		for(int col=0; col<n; col++){
			if(row==0 && col==0){
				prevCol[col] = 1;
				continue;
			}
			int left= 0;
			if(col-1>=0) left += prevCol[col-1];
			int up = 0;
			if(row-1>=0) up += prevRow[col];

			prevCol[col] = left + up;	// updating the prevCol value.
		}
		prevRow = prevCol;
	}

	return prevRow[n-1];
}

int uniquePaths(int m, int n) {
	vector<vector<int>>dp(m, vector<int>(n, -1));
	// return f(m-1, n-1, dp); // memoization
	// return f(m, n); // tabulation
	return f(m,n); // space optimal one.
}
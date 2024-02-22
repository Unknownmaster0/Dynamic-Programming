#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/minimum-path-sum_985349?leftPanelTabValue=PROBLEM


// normal recurrence -> t.c = O(2^(n*m)) s.c = O(n+m) 
// memoization -> t.c = O(n * m) s.c = O(n*m) [for dp] + O(n + m) [for auxillary recursion stack space]
int f(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
    if(row == 0 && col == 0)    return grid[row][col];
    if(dp[row][col] != -1)  return dp[row][col];

    int left = INT_MAX, up = INT_MAX;

    if(col-1 >=0) left = grid[row][col] + f(row, col-1, grid, dp);
    if(row-1 >=0) up = grid[row][col] + f(row-1, col, grid, dp);

    return dp[row][col] = min(left, up);
}

// tabulation -> t.c = O(N * M) s.c = O(N * M) [for dp only]
// int f(int n, int m, vector<vector<int>>& grid ){

//     vector<vector<int>> dp(n, vector<int>(m, -1));
    
//     for(int row=0; row<n; row++){
//         for(int col=0; col<m; col++){
//             if(row == 0 && col==0){
//                 dp[row][col] = grid[0][0]; // row = 0, col = 0 only.
//                 continue;
//             }
//             int left = INT_MAX, up = INT_MAX;
//             if(col-1 >=0) left = grid[row][col] + dp[row][col-1];
//             if(row-1 >=0) up = grid[row][col] + dp[row-1][col];

//             dp[row][col] = min(left, up);
//         }
//     }

//     return dp[n-1][m-1];
// }

// spaceOptimal -> t.c = O(N * M) s.c = O(M) [for dp only]
int f(int n, int m, vector<vector<int>>& grid ){

    vector<int> prevUpRow(m, 0);
    
    for(int row=0; row<n; row++){
        vector<int> prevCol(m, 0);
        for(int col=0; col<m; col++){
            if(row == 0 && col==0){
                prevCol[col] = grid[0][0]; // row = 0, col = 0 only.
                continue;
            }
            int left = INT_MAX, up = INT_MAX;
            if(col-1 >=0) left = grid[row][col] + prevCol[col-1];
            if(row-1 >=0) up = grid[row][col] + prevUpRow[col];

            prevCol[col] = min(left, up);
        }
        prevUpRow = prevCol;
    }

    return prevUpRow[m-1];
}

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    // return f(n-1, m-1, grid, dp); // for memoization and normal recurrence.
    return f(n, m, grid); // for tabulation
}

int main()
{

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/triangle_1229398?leftPanelTabValue=PROBLEM


// memoization -> t.c = O(n * n)  | s.c = O(n) [for recursion call stack] + O(n * n) [for dp]
int f(int row, int col, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp){
    if(row == n-1)  return triangle[row][col];

    if(dp[row][col] != -1)  return dp[row][col];

    int down = triangle[row][col] + f(row+1, col, n, triangle, dp);
    int diag = triangle[row][col] + f(row+1, col+1, n, triangle, dp);

    return dp[row][col] = min(down, diag);
}


// // tabulation approach -> t.c = O(n * n) | s.c = O(n * n) [for dp]
// int f(int n, vector<vector<int>>& triangle){
//     vector<vector<int>> dp(n, vector<int>(n, -1));

//     // base case of memoization
//     for(int i=0; i<n; i++) dp[n-1][i] = triangle[n-1][i];

//     for(int row = n-2; row >=0; row--){
//         for(int col = row; col >=0; col--){
//             int down = triangle[row][col] + dp[row+1][col];
//             int diag = triangle[row][col] + dp[row+1][col+1];

//             dp[row][col] = min(down, diag);
//         }
//     }
//     return dp[0][0];
// }


// space optimisation -> t.c = O(n * n)  |  s.c = O(n)
int f(int n, vector<vector<int>>& triangle){
    vector<int> nextRow(n,0);

    // base case of memoization
    for(int i=0; i<n; i++) nextRow[i] = triangle[n-1][i];

    for(int row = n-2; row >=0; row--){
        vector<int> temp(row + 1, 0);
        for(int col = row; col >=0; col--){
            int down = triangle[row][col] + nextRow[col];
            int diag = triangle[row][col] + nextRow[col+1];

            temp[col] = min(down, diag);
        }
        nextRow = temp;
    }
    return nextRow[0];
}



int minimumPathSum(vector<vector<int>>& triangle, int n){
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // return f(0,0,n, triangle, dp); // for memoization
    return f(n, triangle); // for tabulation and space optimisation
}

int main()
{

    return 0;
}
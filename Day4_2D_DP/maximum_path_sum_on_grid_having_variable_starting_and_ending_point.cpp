#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM


// memoization step -> t.c = O(n * m)  |  s.c = O(n) [for recursion stack space] + O(n * m) [for dp]
int f(int row, int col, vector<vector<int>> &matrix, int tr, int tc, vector<vector<int>> &dp){
    if(row == 0)    return matrix[0][col];
    if(dp[row][col] != -1)  return dp[row][col];
    int up = matrix[row][col] + f(row-1, col, matrix, tr, tc, dp);
    int leftdiag = INT_MIN; // as we have said to return the max value so, the leftdiag is INT_MIN
    if(col-1 >= 0) leftdiag = matrix[row][col] + f(row-1, col-1, matrix, tr, tc, dp);
    int rightdiag = INT_MIN; // similarly here also.
    if(col+1 < tc) rightdiag = matrix[row][col] + f(row-1, col+1, matrix, tr, tc, dp);

    return dp[row][col] = max(up, max(leftdiag, rightdiag));
}


// // tabulation code. -> t.c = O(n * m)  ||  s.c = O(n * m)
// int f(int n, int m, vector<vector<int>> &matrix){
//     vector<vector<int>> dp(n, vector<int>(m, -1));
//     for(int i=0; i<m; i++){
//         dp[0][i] = matrix[0][i];
//     }

//     for(int i=1; i<n; i++){
//         for(int j=0; j<m; j++){
//             int up = matrix[i][j] + dp[i-1][j];
//             int leftdiag = INT_MIN; // as we have said to return the max value so, the leftdiag is INT_MIN
//             if(j-1 >= 0) leftdiag = matrix[i][j] + dp[i-1][j-1];
//             int rightdiag = INT_MIN; // similarly here also.
//             if(j+1 < m) rightdiag = matrix[i][j] + dp[i-1][j+1];

//             dp[i][j] = max(up, max(leftdiag, rightdiag));
//         }
//     }

//     int maxi = INT_MIN;
//     for(int i=0; i<m; i++){
//         maxi = max(maxi, dp[n-1][i]);
//     }
//     return maxi;
// }

// space optimisation -> need to store only the previous row values.
// t.c = O(n * m)  ||  s.c = O(m)
int f(int n, int m, vector<vector<int>> &matrix){
    vector<int> prevRow(m, -1);
    for(int i=0; i<m; i++){
        prevRow[i] = matrix[0][i];
    }

    for(int i=1; i<n; i++){
        vector<int> currRow(m, 0);
        for(int j=0; j<m; j++){
            int up = matrix[i][j] + prevRow[j];
            int leftdiag = INT_MIN; // as we have said to return the max value so, the leftdiag is INT_MIN
            if(j-1 >= 0) leftdiag = matrix[i][j] + prevRow[j-1];
            int rightdiag = INT_MIN; // similarly here also.
            if(j+1 < m) rightdiag = matrix[i][j] + prevRow[j+1];

            currRow[j] = max(up, max(leftdiag, rightdiag));
        }
        prevRow = currRow;
    }

    int maxi = INT_MIN;
    for(int i=0; i<m; i++){
        maxi = max(maxi, prevRow[i]);
    }
    return maxi;
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    /* FOR MEMOIZATION
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = INT_MIN;
    for(int i=0; i<m; i++){

        maxi = max(maxi, f(n-1, i, matrix, n, m, dp));
    }

    return maxi; */

    // for tabulation and space optimisation
    return f(n, m, matrix);
}

int main()
{

    return 0;
}
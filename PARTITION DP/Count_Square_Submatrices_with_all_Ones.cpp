#include<iostream>
#include<vector>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/count-square-submatrices-with-all-ones_3751502?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

// code->
int countSquares(int n, int m, vector<vector<int>> &arr) {

    vector<vector<int>> dp(n, vector<int>(m, 0));

    // first fill the first row and col as it is in the dp table.
    for(int i=0; i<n; i++){
        dp[i][0] = arr[i][0];
    }
    for(int j=0; j<m; j++){
        dp[0][j] = arr[0][j];
    }

    for(int row = 1; row<n; row++){
        for(int col = 1; col<m; col++){

            if(arr[row][col] == 0)  continue;
// this is the only single line logic for this question.
            dp[row][col] = min(dp[row-1][col-1], min(dp[row-1][col], dp[row][col-1])) + 1;
        }
    }
    
    // now total number of squares is -> sum of all the values in the dp.
    int count = 0;
    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){

            count += dp[row][col];
        }
    }

    return count;
}

int main()
{
    
    return 0;
}
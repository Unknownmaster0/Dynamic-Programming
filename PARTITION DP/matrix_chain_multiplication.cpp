#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/matrix-chain-multiplication_975344?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

// code ->
/*
// memoization -> t.c = O(n^3) ||  s.c = O(N * N)[for dp]  * O(N)[for auxillary stack space.]
int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    if( i == j )    return 0;

    if(dp[i][j] != -1)  return dp[i][j];

    int mini = 1e9;
    for(int k=i; k<j; k++){
        int operations = arr[i-1] * arr[k] * arr[j]  + f(i, k, arr, dp) + f(k+1, j, arr, dp);
        mini = min(mini, operations);
    }
    return dp[i][j] = mini;
}
*/

// tabulation -> t.c = O(n*n*n) ||  s.c = O(N * N)[for dp]
int f(vector<int> &arr, int &n){

    vector<vector<int>> dp(n, vector<int>(n, 0));    

    for(int i=n-1; i>=1; i--){
        for(int j=i+1; j<n; j++){

            int mini = 1e9;
            for(int k=i; k<j; k++){
                int opr = ( arr[i-1] * arr[k] * arr[j] ) + dp[i][k] + dp[k+1][j];
                mini = min(mini, opr);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][n-1];
}

int matrixMultiplication(vector<int> &arr, int N)
{
 
// Memoization ->
    // vector<vector<int>> dp(N, vector<int>(N, -1));
    // return f(1, N-1, arr, dp);

// Tabulation -> 
    return f(arr, N);
}







int main()
{

    return 0;
}
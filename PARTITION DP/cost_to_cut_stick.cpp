#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/cost-to-cut-a-chocolate_3208460?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

int f(int i, int j, vector<int> &cut, vector<vector<int>> &dp){
    if(i > j)   return 0;

    if(dp[i][j] != -1)  return dp[i][j];

    int mini = INT_MAX;
    for(int k=i; k<=j; k++){
        int cost = cut[j+1]-cut[i-1] + f(i,k-1, cut,dp) + f(k+1,j, cut, dp);
        mini = min(cost, mini);
    }
    return dp[i][j] = mini;
}

int f(vector<int>& cut, int c){
    vector<vector<int>> dp(c+2, vector<int>(c+2, 0));

    for(int i=c; i>=1; i--){
        for(int j=1; j<=c; j++){
            // if(i > j)   continue;    // if you use this if statement then don't need to give below if statement
            if(i > j){  // base case of the recurrence.
                dp[i][j] = 0;
            }
            else{

                // if(i <= j){
                    int mini = INT_MAX;
                    for(int k=i; k<=j; k++){
                        int cost = cut[j+1]-cut[i-1] + dp[i][k-1] + dp[k+1][j];
                        mini = min(cost, mini);
                    }
                    dp[i][j] = mini;
                // }
            }
        }
    }

    return dp[1][c];
}

int cost(int n, int c, vector<int> &cuts){
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c+1, vector<int>(c+1, -1));

    // return f(1,c,cuts, dp);

    return f(cuts, c);
}

int main()
{
    
    return 0;
}
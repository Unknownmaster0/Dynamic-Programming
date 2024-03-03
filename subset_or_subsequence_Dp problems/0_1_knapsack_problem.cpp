#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
/*
// memoization -> t.c = O(n * w), s.c = O(n) [for A.S.S] + O(n * w) [for dp]
int f(int idx, int w, vector<int>&wt, vector<int>& val, vector<vector<int>>&dp){
    // base case 
    if(idx == 0){
        if(wt[0]<=w)  return val[idx];
        return 0;
    }

    if(dp[idx][w] != -1)    return dp[idx][w];
    int notTake = 0 + f(idx-1, w, wt, val, dp);
    int take = INT_MIN;
    if (wt[idx] <= w)take = val[idx]+ f(idx-1, w-wt[idx], wt, val, dp);

    return dp[idx][w] = max(notTake, take);
}*/

// // tabulation -> t.c = O(n * w), s.c = O(n * w) [for dp]
// int f(int n, int weight, vector<int>&wt, vector<int>& val){
//     vector<vector<int>> dp(n, vector<int>(weight+1, 0));
//     // base case 
//     // if(wt[0]<=w)  dp[0][0] = val[idx]; // for the idx == 0
//     for(int i=wt[0]; i<=weight; i++){
//         dp[0][i] = val[0];
//     }

//     for(int idx=1; idx<n; idx++){
//         for(int w=0; w<=weight; w++){
//             int notTake = 0 + dp[idx-1][w];
//             int take = INT_MIN;
//             if (wt[idx] <= w)take = val[idx] + dp[idx-1][w-wt[idx]];

//             dp[idx][w] = max(notTake, take);
//         }
//     }

//     return dp[n-1][weight];
// }

// // Space optimisation -> O(n * w), s.c = O(w) [for dp]
// int f(int n, int weight, vector<int>&wt, vector<int>& val){
//     vector<int>prevRow(weight+1, 0);
//     // base case 
//     // if(wt[0]<=w)  dp[0][0] = val[idx]; // for the idx == 0
//     for(int i=wt[0]; i<=weight; i++){
//         prevRow[i] = val[0];
//     }

//         vector<int>curr(weight+1, 0);
//     for(int idx=1; idx<n; idx++){
//         for(int w=0; w<=weight; w++){
//             int notTake = 0 + prevRow[w];
//             int take = INT_MIN;
//             if (wt[idx] <= w)take = val[idx] + prevRow[w-wt[idx]];

//             curr[w] = max(notTake, take);
//         }
//         prevRow = curr;
//     }

//     return prevRow[weight];
// }

// single array space optimisation -> 
int f(int n, int weight, vector<int>&wt, vector<int>& val){
    vector<int>prevRow(weight+1, 0);
    // base case 
    // if(wt[0]<=w)  dp[0][0] = val[idx]; // for the idx == 0
    for(int i=wt[0]; i<=weight; i++){
        prevRow[i] = val[0];
    }

    for(int idx=1; idx<n; idx++){
        for(int w=weight; w>=0; w--){
            int notTake = 0 + prevRow[w];
            int take = INT_MIN;
            if (wt[idx] <= w)take = val[idx] + prevRow[w-wt[idx]];

            prevRow[w] = max(notTake, take);
        }
    }

    return prevRow[weight];
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    /*
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	return f(n-1, maxWeight, weight, value, dp);
    */

    return f(n, maxWeight, weight, value);
}

int main()
{

    return 0;
}
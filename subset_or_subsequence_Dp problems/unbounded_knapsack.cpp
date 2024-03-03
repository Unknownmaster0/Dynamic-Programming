#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

// // memoization -> t.c = O(n * wt) || s.c = O(n * target) + O(target) [A.S.S]
// int f(int idx, int wt, vector<int>& pr, vector<int>& weight, vector<vector<int>> &dp){
//     // Base case ->
//     if(idx == 0){
//         if(wt % weight[0] == 0) return pr[0] * (wt / weight[0]);
//         return 0;
//     }

//     if(dp[idx][wt] != -1)   return dp[idx][wt];

//     int notTake = f(idx-1, wt, pr, weight, dp);
//     int take = INT_MIN;
//     if(weight[idx] <= wt) take = pr[idx] + f(idx, wt-weight[idx], pr, weight, dp);

//     return dp[idx][wt] = max(notTake, take);
// }

// // tabulation -> t.c = O(n * wt) || s.c = O(n * target)
// int f(int n, int w, vector<int>& pr, vector<int>& weight){
//     vector<vector<int>> dp(n, vector<int>(w+1, 0));
//     // Base case ->
//     // if(idx == 0){
//     //     if(wt % weight[0] == 0) return pr[0] * (wt / weight[0]);
//     //     return 0;
//     // }
//     for(int wt=0; wt<=w; wt++){
//         if(wt % weight[0] == 0) dp[0][wt] = pr[0] * (wt / weight[0]);
//         else dp[0][wt] = 0;
//     }

//     for(int idx=1; idx<n; idx++){
//         for(int wt=0; wt<=w; wt++){
//             int notTake = dp[idx-1][wt];
//             int take = INT_MIN;
//             if(weight[idx] <= wt) take = pr[idx] + dp[idx][wt-weight[idx]];

//             dp[idx][wt] = max(notTake, take);
//         }
//     }
//     return dp[n-1][w];
// }

// // space optimisation using two array -> t.c = O(n * wt) || s.c = O(weight)
// int f(int n, int w, vector<int>& pr, vector<int>& weight){
//     vector<int> prevRow(w+1, 0), currRow(w+1, 0);
//     // Base case ->
//     // if(idx == 0){
//     //     if(wt % weight[0] == 0) return pr[0] * (wt / weight[0]);
//     //     return 0;
//     // }
//     for(int wt=0; wt<=w; wt++){
//         if(wt % weight[0] == 0) prevRow[wt] = pr[0] * (wt / weight[0]);
//         else prevRow[wt] = 0;
//     }

//     for(int idx=1; idx<n; idx++){
//         for(int wt=0; wt<=w; wt++){
//             int notTake = prevRow[wt];
//             int take = INT_MIN;
//             if(weight[idx] <= wt) take = pr[idx] + currRow[wt-weight[idx]];

//             currRow[wt] = max(notTake, take);
//         }
//         prevRow = currRow;
//     }
//     return prevRow[w];
// }

// space optimisation using one array -> t.c = O(n * wt) || s.c = O(weight)
int f(int n, int w, vector<int> &pr, vector<int> &weight)
{
    vector<int> prevRow(w + 1, 0);
    // Base case ->
    // if(idx == 0){
    //     if(wt % weight[0] == 0) return pr[0] * (wt / weight[0]);
    //     return 0;
    // }
    for (int wt = 0; wt <= w; wt++)
    {
        if (wt % weight[0] == 0)
            prevRow[wt] = pr[0] * (wt / weight[0]);
        else
            prevRow[wt] = 0;
    }

    for (int idx = 1; idx < n; idx++)
    {
        for (int wt = 0; wt <= w; wt++)
        {
            int notTake = prevRow[wt];
            int take = INT_MIN;
            if (weight[idx] <= wt)
                take = pr[idx] + prevRow[wt - weight[idx]];

            prevRow[wt] = max(notTake, take);
        }
    }
    return prevRow[w];
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{

    // vector<vector<int>> dp(n, vector<int>(w+1, -1));
    // return f(n-1, w, profit, weight, dp);

    // tabulation
    return f(n, w, profit, weight);
}

int main()
{

    return 0;
}
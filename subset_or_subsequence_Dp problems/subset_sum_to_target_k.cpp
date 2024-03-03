#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=1%3Fsource%3Dyoutube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM


// // recurrence -> t.c = O(2^n) || s.c = O(n) [auxillary stack space.]
bool f(int idx, int k, vector<int>& arr){
    // base cases->
    if(k ==0)   return true;
    if(idx == 0)    return arr[0] == k;

    // now possiblity of the curr idx.
    bool not_take = f(idx-1, k, arr);
    bool take = false;
    if(arr[idx] <= k){
        take = f(idx-1, k-arr[idx], arr);
    }

    return take || not_take; 
}

// memoization -> t.c = O(n * k) || s.c = O(n) [auxillary stack space.] + O(n * k)
bool f(int idx, int k, vector<int>& arr, vector<vector<int>>& dp){
    // base cases->
    if(k ==0)   return true;
    if(idx == 0)    return arr[0] == k;

    if(dp[idx][k] != -1)    return dp[idx][k];

    // now possiblity of the curr idx.
    bool not_take = f(idx-1, k, arr, dp);
    bool take = false;
    if(arr[idx] <= k){
        take = f(idx-1, k-arr[idx], arr, dp);
    }

    return dp[idx][k] = take || not_take; 
}

// tabulation -> t.c = O(n * k) || s.c = O(n) [auxillary stack space.] + O(n * k)
bool f(int n, int k, vector<int>& a){
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));
    // base cases->
    for(int i=0; i<n; i++){
        // if(k ==0)   return true;
        dp[i][0] = true;
    }
    // if(idx == 0)    return arr[0] == k;
    if(a[0] <= k) dp[0][a[0]] = true;

    for(int i=1; i<n; i++){
        for(int t=1; t<=k; t++){
            // now possiblity of the curr idx.
            bool not_take = dp[i-1][t];
            bool take = false;
            if(a[i] <= t){
                take = dp[i-1][t-a[i]];
            }
            dp[i][t] = take || not_take;
        }
    }

    return dp[n-1][k]; 
}

// sapce optimisation -> t.c = O(n*k) || s.c = O(k)
bool f(int n, int k, vector<int>& a){
    vector<bool>prevRow(k+1, false);
//     // base cases->
//     for(int i=0; i<n; i++){
//         // if(k ==0)   return true;
//         dp[i][0] = true;
//     }
    prevRow[0] = true;
    
//     dp[0][a[0]] = true;
    if(a[0] <= k) prevRow[a[0]] = true;

    for(int i=1; i<n; i++){
        vector<bool>currRow(k+1, false);
        currRow[0] = true;
        for(int t=1; t<=k; t++){
            // now possiblity of the curr idx.
            bool not_take = prevRow[t];
            bool take = false;
            if(a[i] <= t){
                take = prevRow[t-a[i]];
            }
            currRow[t] = take || not_take;
        }
        prevRow = currRow;
    }

    return prevRow[k]; 
}

// target = k (here.)
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // vector<vector<int>> dp(n, vector<int>(k+1, -1));
    // return f(n-1, k, arr, dp);
    return f(n, k, arr);
}

int main()
{

    return 0;
}
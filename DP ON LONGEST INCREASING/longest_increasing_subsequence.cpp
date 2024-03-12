#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

/*
// recurrence -> memoization
int f(int idx, int prev, int arr[], int n, vector<vector<int>> &dp){
    if(idx == n)    return 0;

    if(dp[idx][prev+1] != -1) return dp[idx][prev+1];

    int notTake = f(idx+1, prev, arr, n, dp);
    int take = 0;
    if(prev == -1 || arr[idx] > arr[prev]){
        take = 1 + f(idx+1, idx, arr, n, dp);
    }

    return dp[idx][prev+1] = max(notTake, take);
}
*/

/*
// Tabulation code.
int f(int arr[], int n){

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int idx=n-1; idx>=0; idx--){
        for(int prev = idx-1; prev>=-1; prev--){

            int notTake = dp[idx+1][prev+1];
            int take = 0;
            if (prev == -1 || arr[idx] > arr[prev]) {
                take = 1 + dp[idx+1][idx + 1];
            }

            dp[idx][prev+1] = max(notTake, take);
        }
    }

    // dp[0][-1+1] = dp[0][0];
    return dp[0][0];
}*/

/*
// space optimisation
int f(int arr[], int n){

    vector<int> next(n+1, 0), curr(n+1, 0);

    for(int idx=n-1; idx>=0; idx--){
        for(int prev = idx-1; prev>=-1; prev--){

            int notTake = next[prev+1];
            int take = 0;
            if (prev == -1 || arr[idx] > arr[prev]) {
                take = 1 + next[idx + 1];
            }

            curr[prev+1] = max(notTake, take);
        }
        next = curr;
    }

    // dp[0][-1+1] = dp[0][0];
    return next[0];
}*/

int longestIncreasingSubsequence(int arr[], int n)
{
    // prev -> range = [-1, n-1] = [0, n] thus size = [n+1]
    // vector<vector<int>> dp(n, vector<int>(n+1, -1));
    // return f(0, -1, arr, n, dp);

    // return f(arr, n);

    // Approach 2 -> using the Tabulation code.
    vector<int> dp(n, 1), hash(n);
    int maxi = -1;
    int maxIndex = -1;
    for (int idx = 0; idx < n; idx++)
    {
        hash[idx] = idx;
        for (int prev_idx = 0; prev_idx < idx; prev_idx++)
        {

            // check if the prev_idx can be the part of the current subsequence.
            if (arr[prev_idx] < arr[idx] && 1 + dp[prev_idx] > dp[idx])
            {
                dp[idx] = 1 + dp[prev_idx];
                hash[idx] = prev_idx;
            }
        }
        if (maxi < dp[idx])
        {
            maxi = dp[idx];
            maxIndex = idx;
        }
    }

    // hash vector is now containing the values of the idx.
    cout << "Printing hash ->" << endl;
    for (auto it : hash)
        cout << it << " ";
    cout << endl;

    vector<int> lis;
    lis.push_back(arr[maxIndex]);

    while (maxIndex != hash[maxIndex])
    {
        maxIndex = hash[maxIndex];
        lis.push_back(arr[maxIndex]);
    }

    reverse(lis.begin(), lis.end());
    cout << "printing the lis -> " << endl;
    for (auto it : lis)
        cout << it << " ";
    cout << endl;
    return maxi;
}

int main()
{

    return 0;
}
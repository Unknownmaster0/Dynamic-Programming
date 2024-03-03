#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM


// Same approach as the -> partition with sum k question of this folder and later apply the approach of find the count of subset having sum equal to k. [mixture of two question.]

int mod = 1e9 + 7;

// // memoization -> t.c = O(n*target) || s.c = O(n*target) [for dp] + O(n) [for auxillary stack space.]
// int f(int idx, int target, vector<int>& arr, vector<vector<int>> &dp){
//     if(idx ==0){
//         if(target ==0 && arr[0] == 0)   return 2;
//         if(target ==0 || arr[0] == target)  return 1;
//         return 0;
//     }

//     if(dp[idx][target] != -1)   return dp[idx][target];

//     int not_take = f(idx-1, target, arr, dp);
//     int take = 0;
//     if(arr[idx] <= target) take = f(idx-1, target-arr[idx], arr, dp);

//     return dp[idx][target] = (not_take + take) % mod;
// }

// // tabulation -> t.c = O(n*target) || s.c = O(n*target) [for dp]
// int f(int n, int target, vector<int>& arr){

//     vector<vector<int>>dp(n,vector<int>(target+1, 0));

// // base cases.
//     if(arr[0]==0) dp[0][0] = 2;
//     else
//         dp[0][0] = 1;

//     if(arr[0] != 0 && arr[0] <= target)
//         dp[0][arr[0]] = 1;

//     for(int i=1; i<n; i++){
//         for(int k=0; k<=target; k++){
//             int not_take = dp[i-1][k];
//             int take = 0;
//             if(arr[i] <= k) take = dp[i-1][k-arr[i]];

//             dp[i][k] = (not_take + take) % mod;
//         }
//     }
//     return dp[n-1][target];
// }

// space optimisation -> t.c = O(n*target) || s.c = O(target) [for prevRow]
int f(int n, int target, vector<int> &arr)
{

    vector<int> prevRow(target + 1, 0);

    // base cases.
    if (arr[0] == 0)
        prevRow[0] = 2;
    else
        prevRow[0] = 1;

    if (arr[0] != 0 && arr[0] <= target)
        prevRow[arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        vector<int> currRow(target + 1, 0);
        for (int k = 0; k <= target; k++)
        {
            int not_take = prevRow[k];
            int take = 0;
            if (arr[i] <= k)
                take = prevRow[k - arr[i]];

            currRow[k] = (not_take + take) % mod;
        }
        prevRow = currRow;
    }
    return prevRow[target];
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int totalSum = 0;
    for (auto it : arr)
        totalSum += it;

    // we can also do this something like ->
    // if(totalSum - d < 0  || (totalSum - d) % 2 != 0) return 0;
    // int target = (totalSum - d) / 2;

    if ((totalSum + d) % 2 != 0)
        return 0;
    int target = (totalSum + d) / 2;

    // vector<vector<int>> dp(n, vector<int>(target+1, -1));
    // return f(n-1, target, arr, dp);

    return f(n, target, arr);
}

int main()
{

    return 0;
}
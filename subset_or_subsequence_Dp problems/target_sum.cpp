#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/target-sum_4127362?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

// // recurrence -> memoization => t.c = O()
// int f(int idx, int tar, vector<int>& a, map<pair<int,int>, int> &dp){
//     // base case ->
//     if(idx == 0){
//         if(tar == 0 && a[0] == 0)    return 2;
//         if(tar == a[0] || tar == -a[0])   return 1;
//         return 0;
//     }

//     if (dp.find({idx, tar}) != dp.end())
//         return dp[{idx, tar}];

//     int plus = f(idx-1, tar+a[idx], a, dp);
//     int minus = f(idx-1, tar-a[idx], a, dp);

//     return dp[{idx,tar}] = plus + minus;
// }

// // memoization ->
// int f(int n, int target, vector<int>& arr, vector<vector<int>>& dp){

//     // BASe CAse
//     if(n == 0){
//         if(target == 0 && arr[0] == 0)  return 2;
//         if(target == 0 || target == arr[0]) return 1;
//         return 0;
//     }

//     if(dp[n][target] != -1) return dp[n][target];

//     int notTake = f(n-1, target, arr, dp);
//     int take = 0;
//     if(arr[n] <= target)    take = f(n-1, target-arr[n], arr, dp);

//     return dp[n][target] = take + notTake;
// }

// tabulated.
int f(int n, int target, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    // Base case ->
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (arr[0] != 0 && arr[0] <= target)
        dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int tar = 0; tar <= target; tar++)
        {
            int notTake = dp[i - 1][tar];
            int take = 0;
            if (arr[i] <= tar)
                take = dp[i - 1][tar - arr[i]];

            dp[i][tar] = notTake + take;
        }
    }
    return dp[n - 1][target];
}

int targetSum(int n, int target, vector<int> &arr)
{
    // as here the value of target can go after the target value and less than 0 also, then
    // we can't define its size.
    // Thus, use map,
    // map<pair<int,int>, int> dp;
    // return f(n-1, target, arr, dp);

    // method 2 -> using partition array with given difference question method.
    int totalSum = 0;
    for (auto it : arr)
        totalSum += it;

    if (totalSum + target < 0 || (totalSum + target) % 2 != 0)
        return 0;
    int newTarget = (totalSum + target) / 2;
    // vector<vector<int>> dp(n, vector<int>(newTarget + 1, -1));
    // return f(n-1, newTarget, arr, dp);

    return f(n, newTarget, arr);
}

int main()
{

    return 0;
}
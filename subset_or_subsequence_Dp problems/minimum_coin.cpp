#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/minimum-elements_3843091?leftPanelTab=1%3Fsource%3Dyoutube&campaign=striver_dpseries&leftPanelTabValue=SUBMISSION


// memoization -> t.c = O(n * target), || s.c = O(n * target) + O(target)[A.S.S]
// int f(int idx, int target, vector<int>& nums, vector<vector<int>> &dp){
//     if(idx==0){
//         if((target % nums[idx]) == 0)    return target/nums[idx];
//         else
//             return 1e8;
//     }

//     if(dp[idx][target] != -1)   return dp[idx][target];

//     int notTake = f(idx-1, target, nums, dp);
//     int take = 1e8;
//     if(nums[idx] <= target) take = 1 + f(idx, target-nums[idx], nums, dp);
    
//     return dp[idx][target] = min(notTake, take);
// }

// // tabulation => t.c = O(n * target), || s.c = O(n * target)
// int f(int n, int target, vector<int>& nums){

//     vector<vector<int>> dp(n, vector<int>(target+1, 0));
//     for(int t =0; t<=target; t++){
//         if((t % nums[0]) == 0)  dp[0][t] = t/nums[0];
//         else
//             dp[0][t] = 1e9;
//     }

//     for(int idx=1; idx<n; idx++){
//         for(int t=0; t<= target; t++){

//             int notTake = dp[idx-1][t];
//             int take = INT_MAX;
//             if(nums[idx] <= t) take = 1 + dp[idx][t-nums[idx]];
            
//             dp[idx][t] = min(notTake, take);
//         }
//     }
//     return dp[n-1][target];
// }

// space optimisation => t.c = O(n * target), || s.c = O(target)
int f(int n, int target, vector<int>& nums){

    vector<int>prev(target+1, 0), curr(target+1, 0);

    for(int t =0; t<=target; t++){
        if((t % nums[0]) == 0)  prev[t] = t/nums[0];
        else
            prev[t] = 1e9;
    }

    for(int idx=1; idx<n; idx++){
        for(int t=0; t<= target; t++){

            int notTake = prev[t];
            int take = INT_MAX;
            if(nums[idx] <= t) take = 1 + curr[t-nums[idx]];
            
            curr[t] = min(notTake, take);
        }
        prev = curr;
    }
    return prev[target];
}

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    // vector<vector<int>> dp(n, vector<int>(x+1, -1));
    // int ans = f(n-1, x, num, dp);
    int ans = f(n, x, num);

    if(ans >= 1e9)  return -1;
    return ans;
}

int main()
{

    return 0;
}
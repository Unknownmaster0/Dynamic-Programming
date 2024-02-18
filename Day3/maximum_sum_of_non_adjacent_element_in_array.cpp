#include<iostream>
#include<vector>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION

// time -> O(N) && space -> O(N + N) [O(N) -> for recursion stack space]
int memoization(int idx, vector<int>& nums, vector<int>&dp){
    if(idx == 0 )   return nums[idx];
    if(idx < 0) return 0;
    if(dp[idx] != -1)   return dp[idx];

    int pick = nums[idx] + memoization(idx-2, nums, dp);
    int nonpick = memoization(idx-1, nums, dp);

    return dp[idx] = max(pick, nonpick);
}

// time -> O(N) && space -> O(N)
int tabulation(int idx, vector<int>& nums, vector<int>&dp){
    
    dp[0] = nums[0];
    for(int i=1; i<=idx; i++){
        int pick = nums[i];
        if(i-2 >= 0)    pick += dp[i-2];
        int nonpick = dp[i-1];
        dp[i] = max(pick, nonpick);
    }
    return dp[idx];
}

// time -> O(N) && space -> O(1)
int spaceOptimisation(int idx, vector<int>&nums){
    int prev2 = 0, prev = nums[0];
    for(int i=1; i<=idx; i++){
        int pick = nums[i];
        if(i-2 >= 0)    pick += prev2;
        int nonpick = prev;
        int curr = max(pick, nonpick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);

    return spaceOptimisation(n-1, nums);
}


int main()
{
    
    return 0;
}
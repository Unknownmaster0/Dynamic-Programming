#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

int main()
{

    return 0;
}

#include <bits/stdc++.h>

// time -> O(N) , space -> O(N)
int memoization(int idx, vector<int> &heights, vector<int> &dp)
{
    if (idx == 0)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    int left = memoization(idx - 1, heights, dp) + abs(heights[idx] - heights[idx - 1]);
    int right = INT_MAX;
    if (idx > 1)
        right = memoization(idx - 2, heights, dp) + abs(heights[idx] - heights[idx - 2]);

    return dp[idx] = min(left, right);
}

// time -> O(N), space -> O(N)
int tabulation(int idx, vector<int> &heights, vector<int> &dp)
{
    dp[0] = 0; // base case of recursion
    for (int i = 1; i <= idx; i++)
    {
        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        dp[i] = min(left, right);
    }
    return dp[idx];
}

// time -> O(N), space -> O(1)
int mostOPtimal(int idx, vector<int> &heights)
{
    int prev = 0, prev2 = 0;
    for (int i = 1; i <= idx; i++)
    {
        int left = prev + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = prev2 + abs(heights[i] - heights[i - 2]);
        }
        int curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int frogJump(int n, vector<int> &heights)
{
    /* The brutforce solution of using only recursion will not work here.
        As the constraints are too tight.
        N <= 10^5 -> Expected time complexity = O(N)

        but if we use recursion only it will take O(2^N)
    */
    vector<int> dp(n, -1);

    /*** Method 1 -> Dp using memoization ***********/
    // return memoization(n-1, heights, dp);

    // Method 2 -> Dp using Tabulation
    // return tabulation(n-1, heights, dp);

    // Method 3 -> MOst optimal solution
    return mostOPtimal(n - 1, heights);
}
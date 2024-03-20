#include<iostream>
#include<vector>
using namespace std;

// Problem link -> https://leetcode.com/problems/partition-array-for-maximum-sum/description/?envType=daily-question&envId=2024-02-03

// Code -> 
class Solution {
/*
// Recurrence -> memoization => t.c = O(n * n) || s.c = O(n) + O(n)[A.S.S]
    int f(int i, vector<int> &a, int k, int n, vector<int> &dp){
        if(i == n)   return 0;

        if(dp[i] != -1) return dp[i];

        int maxSum = -1, maxelement = -1;
        for(int idx=i; idx< min( n, i+k); idx++){

            maxelement = max(maxelement, a[idx]);
            int sum = maxelement * (idx-i+1) + f(idx+1, a, k, n, dp);

            maxSum = max(maxSum, sum);
        }

        return dp[i] = maxSum;
    }
*/
    int f(vector<int> &a, int k, int n){
        vector<int> dp(n+1, 0);
        dp[n] = 0;
        for(int i=n-1; i>=0; i--){

            int maxSum = -1, maxelement = -1;
            for(int idx=i; idx< min( n, i+k); idx++){

                maxelement = max(maxelement, a[idx]);
                int sum = maxelement * (idx-i+1) + dp[idx+1];

                maxSum = max(maxSum, sum);
            }

            dp[i] = maxSum;
        }

        return dp[0];
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        // for memoizaton->
        // vector<int> dp(n, -1);
        // return f(0, arr, k, n, dp) ;

        // for tabulation
        return f(arr, k, n);
    }
};


int main()
{
    
    return 0;
}
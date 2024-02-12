#include<iostream>
#include<vector>
using namespace std;

/******** Memoization Dp approach. **********/
// Time complexity -> O(N)
// Space complexity -> O(N) [for stack space] + O(N) [for dp array]
int fib(int n, vector<int>&dp){
    if(n <= 1)  return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fib(n-1,dp) + fib(n-2,dp);
}

// Normal recursive code -> 
// int fib(int n){
//     if(n <= 1)  return n;
//     return fib(n-1) + fib(n-2);
// }

int main()
{
    int n;
    cin >>n;
    vector<int>dp(n+1,-1);
    cout<<n<<"th fibonnaci number is -> "<<fib(n,dp)<<endl;

/********* Tabulation DP approach **************/
// time -> O(N), Space -> O(N)
    dp[0] = 0, dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<n<<"th fib -> "<<dp[n]<<endl;

/********* MOst OPtimal Approach ****************/
// time -> O(N), Space -> O(1)
    int prev2 = 0, prev = 1;
    for(int i=2; i<=n; i++){
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    cout<<n<<"th fib -> "<<prev<<endl;
    
    return 0;
}
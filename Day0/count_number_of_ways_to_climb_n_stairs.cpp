#include <iostream>
#include <vector>
using namespace std;

// problem link -> https://www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION

int main()
{

    return 0;
}

int mod = 1e9+7;

// Memoziation method   time -> O(n), Space -> O(n)
int ways(int n, vector<long long>&dp){
  if(n == 0 || n == 1)  return 1;
  if(dp[n] != -1) return dp[n];

  return dp[n] = ( ways(n-1,dp) + ways(n-2,dp) ) % mod;
}

// Tabulation method    time -> O(n), Space -> O(n)
int tabulation(int n, vector<long long>&dp){
  dp[0 ] = dp[1] = 1;
  // 0th stair and 1st stair base case hai.
  // then 2nd stair se nth stair tk jana baki hai
  for(int i=2; i<=n; i++){
    dp[i] = ( dp[i-1] + dp[i-2] ) % mod;
  }
  return dp[n];
}

// Most optimal space optimisation method   time -> O(n), Space -> O(1)
int optimal(int n){
  int prev2 = 1, prev = 1;
  for(int i=2; i<=n; i++){
    int curr = (prev + prev2 )% mod;
    prev2 = prev;
    prev = curr;
  }
  return prev;
}

int countDistinctWays(int n) {
  vector<long long>dp(n+1 , -1);
  // return ways(n, dp);
  // return tabulation(n,dp);
  return optimal( n);
}
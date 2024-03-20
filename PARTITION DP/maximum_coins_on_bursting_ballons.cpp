#include<iostream>
#include<vector>
using namespace std;

#include <bits/stdc++.h> 
/*
// memoization -> t.c = O(n * n * n)    ||  s.c = O(n * n)  + O(n)[auxillary stack space]
// we are just going bottom up , pahle sabse last me kon sa ballon ko forenge wo soch rhe hai.
int f(int i, int j, vector<int> &a, vector<vector<int>> &dp){
    if(i > j)   return 0;
    if(dp[i][j] != -1)  return dp[i][j];
    
    int maxi = INT_MIN;

    for(int k=i; k<=j; k++){
        int coins = a[i-1] * a[k] * a[j+1] + f(i, k-1, a, dp) + f(k+1, j, a, dp);
        maxi = max(maxi, coins);
    }
    return dp[i][j] = maxi;
}*/

// tabulation -> t.c = O(n * n * n)    ||  s.c = O(n * n)
int f(vector<int> &a){
    int n = a.size();
    a.push_back(1);
    a.insert(a.begin(), 1);

    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

    for(int i=n; i>=1; i--){
        for(int j=1; j<=n; j++){

            if(i <= j){
                                
                int maxi = INT_MIN;

                for(int k=i; k<=j; k++){
                    int coins = a[i-1] * a[k] * a[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(maxi, coins);
                }
                dp[i][j] = maxi;
            }
        }
    }

    return dp[1][n];
}

int maxCoins(vector<int>& a)
{
    // int n = a.size();
    // a.push_back(1);
    // a.insert(a.begin(), 1);

    // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    // return f(1, n, a, dp);

    return f(a);
}

int main()
{
    
    return 0;
}
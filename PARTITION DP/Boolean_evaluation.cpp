#include<iostream>
#include<vector>
using namespace std;


// Problem link -> https://www.codingninjas.com/studio/problems/problem-name-boolean-evaluation_1214650?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

// code -> 

int mod = 1e9 + 7;
/*
// MEMOIZATION SOLUTION -> T.C = O(N^2 * 2 * N) || S.C = O(N^2 * 2) + O(N)[A.S.S]
int f(int i, int j, bool need, string &exp, vector<vector<vector<int>>> &dp) {

// Base cases.
  if (i > j)
    return 0;

  if (i == j) {

    if (need == 1) {
      return exp[i] == 'T';
    } else {
      return exp[i] == 'F';
    }
  }

  if(dp[i][j][need] != -1)    return dp[i][j][need];

  long long ways = 0;
  for (int k = i + 1; k < j; k += 2) {
      
    long long LT = f(i, k - 1, 1, exp, dp);
    long long LF = f(i, k - 1, 0, exp, dp);
    long long RT = f(k + 1, j, 1, exp, dp);
    long long RF = f(k + 1, j, 0, exp, dp);

    if (exp[k] == '&') {

      if (need == 1)
        ways = (ways + (LT * RT) % mod) % mod;
      else {
        ways = (ways + (LF * RT) % mod + (LT * RF) % mod + (RF * LF) % mod) % mod;
      }
    }
    else if (exp[k] == '^') {
      if (need == 1)
        ways = (ways + (LT * RF) % mod + (LF * RT) % mod) % mod;
      else
        ways = (ways + (LF * RF) % mod + (LT * RT) % mod ) % mod;
    }
    else {
        if(need == 1)
            ways = (ways + (LT * RF) % mod + (LF * RT) % mod + (LT * RT) % mod ) % mod;
        else{
            ways = (ways + (LF * RF) % mod ) % mod;
        }
    }
  }
  return dp[i][j][need] = ways % mod;
}*/


// TABULATION SOLUTION -> T.C = O(N^2 * 2 * N) || S.C = O(N^2 * 2)
int f(string &exp){

    int n = exp.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            for(int need = 0; need < 2; need++){

// base case storation
                if(i > j)   continue;
                if(i == j){

                    if (need == 1) {
                        dp[i][j][need] = exp[i] == 'T';
                    }
                    else {
                        dp[i][j][need] = exp[i] == 'F';
                    }
                }
                else{

                    long long ways = 0;
                    for (int k = i + 1; k < j; k += 2) {
                        
                        long long LT = dp[i][k - 1][1];
                        long long LF = dp[i][k - 1][0];
                        long long RT = dp[k+1][j][1];
                        long long RF = dp[k+1][j][0];

                        if (exp[k] == '&') {

                        if (need == 1)
                            ways = (ways + (LT * RT) % mod) % mod;
                        else {
                            ways = (ways + (LF * RT) % mod + (LT * RF) % mod + (RF * LF) % mod) % mod;
                        }
                        }
                        else if (exp[k] == '^') {
                        if (need == 1)
                            ways = (ways + (LT * RF) % mod + (LF * RT) % mod) % mod;
                        else
                            ways = (ways + (LF * RF) % mod + (LT * RT) % mod ) % mod;
                        }
                        else {
                            if(need == 1)
                                ways = (ways + (LT * RF) % mod + (LF * RT) % mod + (LT * RT) % mod ) % mod;
                            else{
                                ways = (ways + (LF * RF) % mod ) % mod;
                            }
                        }
                    }
                    dp[i][j][need] = ways % mod;
                }
            }
        }
    }

    return dp[0][n - 1][1];   
}

int evaluateExp(string &exp)
{
    // int n = exp.size();
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    // return f(0, exp.size() - 1, 1, exp, dp);

    return f(exp);
}



int main()
{
    
    return 0;
}
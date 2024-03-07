#include <iostream>
#include <vector>
using namespace std;

#include <bits/stdc++.h>
/*
// recursion -> memoization ==> t.c = O(n * m)  ||  s.c = O(n * m) + O(n + m)
bool f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    if(i<0 && j<0)  return true;
    if(i<0 && j>=0) return false;
    if(j<0 && i>=0){
        for(int j=0; j<=i; j++){
            if(s[j] != '*') return false;
        }
        return true;
    }

    if(dp[i][j] != -1)  return dp[i][j];

    // if matches
    if(s[i] == t[j] || s[i] == '?'){
        return dp[i][j] = f(i-1, j-1, s, t, dp);
    }
    else if(s[i] == '*'){
        return dp[i][j] = f(i-1, j, s, t, dp) || f(i, j-1, s, t, dp); // this is when we find the * and want to take the character or not.
    }
    else{
        return dp[i][j] = false;
    }
}

// memoization->tabulation == t.c = O(n * m)  ||  s.c = O(n * m)
bool f(string &s, string &t){

    int n = s.size(), m = t.size();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

    // if(i<0 && j<0)  return true;
    dp[0][0] = true;

    for(int i=1; i<=n; i++){
        bool flag = true;
        for(int t=1; t<=i; t++){

            if(s[t-1] != '*'){
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }


    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){

            // if matches
            // consider 1-based indexing.
            if(s[i-1] == t[j-1] || s[i-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(s[i-1] == '*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1]; // this is when we find the * and want to take the character or not.
            }
            else{
                dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
}
*/

// tabulation->space optimisation ==>  t.c = O(n * m)  ||  s.c = O(m)
bool f(string &s, string &t)
{

    int n = s.size(), m = t.size();
    vector<bool> prev(m + 1, false), curr(m + 1, false);

    // if(i<0 && j<0)  return true;
    prev[0] = true;

    for (int i = 1; i <= n; i++)
    {

        // this was one of the base case.
        bool flag = true;
        for (int t = 1; t <= i; t++)
        {

            if (s[t - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        curr[0] = flag;

        for (int j = 1; j <= m; j++)
        {

            // if matches
            // consider 1-based indexing.
            if (s[i - 1] == t[j - 1] || s[i - 1] == '?')
            {
                curr[j] = prev[j - 1];
            }
            else if (s[i - 1] == '*')
            {
                curr[j] = prev[j] || curr[j - 1]; // this is when we find the * and want to take the character or not.
            }
            else
            {
                curr[j] = false;
            }
        }

        prev = curr;
    }

    return prev[m];
}

bool wildcardMatching(string pattern, string text)
{
    //    int n = pattern.size(), m = text.size();
    //    vector<vector<int>> dp(n, vector<int>(m, -1));
    //    return f(n-1, m-1, pattern, text, dp);

    return f(pattern, text);
}

int main()
{

    return 0;
}
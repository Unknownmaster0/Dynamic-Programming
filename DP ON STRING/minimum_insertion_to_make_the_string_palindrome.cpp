#include <iostream>
#include <vector>
using namespace std;

// Problem link ->

/*Approach -> finding the longest palindromic subsequence length of the given string, and get it substract from its length.*/

#include <bits/stdc++.h>

int lcs(string &s, string &t)
{
    int n = s.length();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    int maxi = -1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // if matches.
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            // not matches
            else // not execute this part if matches the current string.
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][n];
}

// longest palindromic subsequence.
int lps(string &s)
{

    string t = s;
    reverse(s.begin(), s.end());

    // Now need to find the longest common subsequence of the s and t string.
    return lcs(s, t);
}


int minimumInsertions(string &str)
{
	return str.length() - lps(str);
}


int main()
{
    string s = "abca";
    string str = "abc";
    cout<<"the minimum insertion to make string palindromic -> "<<minimumInsertions(s)<<endl;
    return 0;
}
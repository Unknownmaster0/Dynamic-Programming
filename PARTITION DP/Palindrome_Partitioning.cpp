#include <iostream>
#include <vector>
using namespace std;

// problem link -> https://www.codingninjas.com/studio/problems/palindrome-partitioning_873266?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

// Code ->
#include <bits/stdc++.h>
/*
bool isPalindrome(string &s)
{
    int i = 0, j = s.size() - 1;

    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++, j--;
    }
    return true;
}
*/
bool isPalindrome(int s, int e, string &str){
    
    while (s < e)
    {
        if(str[s++] != str[e--])    return false;
    }
    
    return true;
}

/*
// This method is working on all test cases except 1 -> why I don't know.
// This normal partition will not work here. here the "front partition will work".

// Memoization -> t.c = O() || s.c = O()
int f(int i, int j, string &s, vector<vector<int>> &dp){

    if(i >= j)  return 0;

    string sub = s.substr(i, j-i+1);
    if( isPalindrome(sub) ) return 0;

    if(dp[i][j] != -1)  return dp[i][j];

    int minPn = INT_MAX;
    for(int k=i; k<j; k++){
        int pn = 1 + f( i, k, s, dp) + f(k+1, j, s, dp);

        minPn = min(minPn, pn);
    }
    return dp[i][j] = minPn;
}


// Tabulation code -> t.c = O() || s.c = O()
int f(string &s){

    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            if(i >= j)  continue;

            string sub = s.substr(i, j-i+1);
            if( isPalindrome(sub) ) continue;

            int minPn = INT_MAX;
            for(int k=i; k<j; k++){
                int pn = 1 + dp[i][k] + dp[k+1][j];

                minPn = min(minPn, pn);
            }
            dp[i][j] = minPn;
        }
    }

    return dp[0][n-1];
}
*/

// memoization -> t.c = O(n^2)   ||  s.c = O(n) + O(n)[A.S.S]
int f(int i, string &s, vector<int> &dp)
{
    if (i == s.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int minP = INT_MAX;
    // string temp = "";
    for (int k = i; k < s.size(); k++)
    {
        // temp += s[k];

        // if (isPalindrome(temp))
        if (isPalindrome(i, k, s))
        {

            int cost = 1 + f(k + 1, s, dp);
            minP = min(minP, cost);
        }
    }

    return dp[i] = minP;
}

// tabulation -> t.c = O(n^2)   ||  s.c = O(n)
int f(string &s)
{

    int n = s.size();
    vector<int> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {

        int minP = INT_MAX;
        // string temp = "";
        for (int k = i; k < s.size(); k++)
        {
            // temp += s[k];

            if (isPalindrome(i, k, s))
            {

                int cost = 1 + dp[k + 1];
                minP = min(minP, cost);
            }
        }

        dp[i] = minP;
    }

    return dp[0] - 1;
}

int palindromePartitioning(string str)
{
    int n = str.size();
    if (isPalindrome(0,n-1,str))
        return 0;

    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // return f(0, n-1, str, dp);
    vector<int> dp(n, -1);
    return f(0, str, dp) - 1;
}

int main()
{

    return 0;
}
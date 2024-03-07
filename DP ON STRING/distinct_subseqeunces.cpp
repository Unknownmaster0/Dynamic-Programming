#include<iostream>
#include<vector>
using namespace std;


// Problem link -> https://www.codingninjas.com/studio/problems/subsequence-counting_3755256?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

int mod = 1e9+7;
/*
// recurrence -> memoization === t.c = O(n * m) || s.c = O(n * m) + O(n + m) [auxillary stack space]
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    if(j < 0)   return 1;
    if(i < 0)   return 0;

    if(dp[i][j] != -1)  return dp[i][j];

    if(s[i] == t[j])    {
        return dp[i][j] = ( f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp) ) % mod;
    }
    else{
        return dp[i][j] = f(i-1, j, s, t, dp);
    }
}
*/

/*
// memoization -> tabulation === t.c = O(n * m) || s.c = O(n * m)
int f(string &s, string &t){
	int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=0; i<=n; i++) dp[i][0] = 1;
    for(int j=1; j<=m; j++) dp[0][j] = 0; // nhi bhi likhega to kam chalega as we have intialised all dp value to 0.

    for(int i=1; i<=n; i++){
        for(int j =1; j<=m; j++){
            if(s[i-1] == t[j-1])    {
                dp[i][j] = ( dp[i-1][j-1] + dp[i-1][j] ) % mod;
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][m];
}
*/
/*
// tabulation -> Space optimisation(to two rows 1-D array) === t.c = O(n * m) || s.c = O(m)
int f(string &s, string &t){
	int n = s.size(), m = t.size();
    vector<int> prev(m+1, 0), curr(m+1, 0);

    prev[0] = 1; // base case
    curr[0] = 1; // base case for every row 0th col.
    // for(j=1; j<=m; j++) prev[j] = 0; but of no use as dp contain alredy 0 in these palces.

    for(int i=1; i<=n; i++){
        for(int j =1; j<=m; j++){
            if(s[i-1] == t[j-1])    {
                curr[j] = ( prev[j-1] + prev[j] ) % mod;
            }
            else{
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }

    return prev[m];
}
*/
// tabulation -> Space optimisation(to one rows 1-D array) === t.c = O(n * m) || s.c = O(m)
int f(string &s, string &t){
	int n = s.size(), m = t.size();
    vector<int> prev(m+1, 0);

    prev[0] = 1; // base case

    for(int i=1; i<=n; i++){
        for(int j=m; j>=0; j--){
            if(s[i-1] == t[j-1])    {
                prev[j] = ( prev[j-1] + prev[j] ) % mod;
            }
            // not necessary as the value remain same.
            // else{
                // prev[j] = prev[j];
            // }
        }
    }
    return prev[m];
}

int distinctSubsequences(string &str, string &sub)
{
	int n = str.size(), m = sub.size();
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // return f(n-1, m-1, str, sub, dp);
    return f(str, sub);
}



int main()
{
    
    return 0;
}

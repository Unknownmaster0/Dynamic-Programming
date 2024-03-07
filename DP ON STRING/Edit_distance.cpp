#include<iostream>
#include<vector>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/edit-distance_630420?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM


// recursion to memoization -> t.c = O(n * m) || s.c = O(n * m)[for dp] + O(n + m)[for auxillary stack space.]
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    // base case
    if(i < 0)   return j+1;
    if(j < 0)   return i+1;

    if(dp[i][j] != -1)  return dp[i][j];

    // if matches
    if(s[i] == t[j]){
        return dp[i][j] = 0 + f(i-1, j-1, s, t, dp);
    }else{
                                // insert               //delete                  // replace
        return dp[i][j] = 1 + min(f(i, j-1, s, t, dp), min(f(i-1, j, s, t, dp), f(i-1, j-1, s, t, dp)));
    }
}
/*
// memoization to tabulation -> t.c = O(n * m) || s.c = O(n * m)[for dp]
int f(string &s, string &t){

    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); // considering 1-based indexing for negative base cases.
    // base case
    for(int i=1; i<=n; i++) dp[i][0] = i;
    for(int j=1; j<=m; j++) dp[0][j] = j;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            // if matches
            if(s[i-1] == t[j-1]){
                dp[i][j] = 0 + dp[i-1][j-1];
            }else{
                                    // insert       //delete    // replace
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }

        }
    }
    return dp[n][m];
}
*/
// tabulation to space optimisation -> t.c = O(n * m) || s.c = O(n * m)[for dp]
int f(string &s, string &t){

    int n = s.size(), m = t.size();
    vector<int> prev(m+1, 0), curr(m+1, 0); // considering 1-based indexing for negative base cases.
    // base case
    // for(int i=0; i<=n; i++) dp[i][0] = i; for each col, but here we have only two col.
    for(int j=0; j<=m; j++) prev[j] = j;

    for(int i=1; i<=n; i++){
        curr[0]=i; // col 0th value is equal to i; // according to the first base case.
        for(int j=1; j<=m; j++){
            // if matches
            if(s[i-1] == t[j-1]){
                curr[j] = 0 + prev[j-1];
            }else{
                                    // insert   //delete   // replace
                curr[j] = 1 + min(curr[j-1], min(prev[j], prev[j-1]));
            }
        }
        prev = curr;
    }
    return prev[m];
}

int editDistance(string str1, string str2)
{
    // for memoization solution 
    // int n = str1.size(), m = str2.size();
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // return f(n-1, m-1, str1, str2, dp);


    // for tabulation and space optimisation -> 
    return f(str1, str2);
}





int main()
{
    
    return 0;
}
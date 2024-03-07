#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION

/* Shifting of index -> as the base case is for i<0 and j<0 but there is no such array index of -1.

                        Thus, we treat or do right shift of index by 1.
                        idx n -> represents n-1th idx.
                        idx 1 -> represents 0th idx.
                        idx 0 -> represents -1th idx.
*/

// // Memoization -> t.c = O(n * m)  ||  s.c = O(n * m) + O(n + m) [A.S.S]
// // for shifted index i(start from) = n, and j(start from) = m.
// int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
//  	// Base case ->
// 	// if(i < 0 || j < 0)	return 0;
// 	if(i ==0 || j == 0)	return 0;	//for right shifted idx.

// 	if(dp[i][j] != -1)	return dp[i][j];

// 	// if matches.
// 	// if(s[i] == t[j]){
// 	if(s[i-1] == t[j-1]){ // for shifted index.
// 		return dp[i][j] = 1 + f(i-1, j-1, s, t, dp);
// 	}
// 	// not matches
// 	return dp[i][j] = max( f(i-1, j, s, t, dp), f(i, j-1, s, t, dp) );
// }

// // tabulation -> t.c = O(n * m)  ||  s.c = O(n * m)
// int f(string &s, string &t){

// 	int n = s.size(), m = t.size();
// 	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
// 	// Base case ->
// 	// if(i == 0 || j == 0)	return 0;
// 	for(int j=0; j<=m; j++)	dp[0][j] = 0; // i == 0
// 	for(int i=0; i<=n; i++)	dp[i][0] = 0; // j == 0

// 	for(int i=1; i<=n; i++){
// 		for(int j=1; j<=m; j++){
// 			// if matches.
// 			if(s[i-1] == t[j-1]){
// 				dp[i][j] = 1 + dp[i-1][j-1];
// 			}
// 			// not matches
// 			else	// not execute this part if matches the current string.
// 				dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
// 		}
// 	}

// 	return dp[n][m];
// }

// space optimisation two rows uses only.-> t.c = O(n * m)  ||  s.c = O(n * m)
int f(string &s, string &t)
{

    int n = s.size(), m = t.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    // Base case ->
    // if(i == 0 || j == 0)	return 0;
    for (int j = 0; j <= m; j++)
        prev[j] = 0; // i == 0

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // if matches.
            if (s[i - 1] == t[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
            }
            // not matches
            else // not execute this part if matches the current string.
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }

    return prev[m];
}

int lcs(string s, string t)
{
    // int n = s.size(), m = t.size();
    // memoization
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // return f(n-1, m-1, s, t, dp);

    // vector<vector<int>> dp(n+1, vector<int>(m+1, -1)); // for shifted index, the dp[n+1][m+1] as, n & m also represent idx.
    // return f(n, m, s, t, dp);	// for right shifted index.

    // tabulation ->
    return f(s, t);
}

int main()
{

    return 0;
}
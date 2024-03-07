#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/longest-common-substring_1235207?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

// recursive approach 
int f(int i, int j, string &s, string &t)
{
    if (i == 0 || j == 0)
        return 0;

    if (s[i - 1] == t[j - 1])
    {
        return 1 + f(i - 1, j - 1, s, t);
    }
    else
        return 0;
}

int lcs(string &s, string &t)
{

    int n = s.size(), m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    int maxi = -1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            // tabulated method.
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0;
            }
            maxi = max(maxi, dp[i][j]);

            // recursive method.
            
            // if(s[i-1] == t[j-1]){
            //     int currLength = 1 + f(i-1, j-1, s, t);
            //     maxi = max(maxi, currLength);
            // }
        }
    }

    return maxi;
}

int main()
{

    return 0;
}
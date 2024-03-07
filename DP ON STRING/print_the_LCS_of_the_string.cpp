#include <iostream>
#include <vector>
using namespace std;

/*Brutfroce way -> Try to generate all the subsequences of the s and t string. (with the help take or notTake recursion method.)
                    then compare the subsequences of the both string, if they are equal, then store. Else leave this.
*/

/*Optimal Way -> Use the Tabulation dp code for the LCS length finding, to compute the String LCS.
 */

// tabulation -> t.c = O(n * m) + O(n + m) ||  s.c = O(n * m)
string LCS = "";
int f(string &s, string &t)
{

    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // Base case ->
    // if(i == 0 || j == 0)	return 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0; // i == 0
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0; // j == 0

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
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

    int lengthLCS = dp[n][m];
    int idx = lengthLCS - 1;
    for (int i = 0; i < lengthLCS; i++)
        LCS += '#';

    // now traversing on the Dp table on the backtracking fashion.

    int i = n, j = m;
    // t.c = O(n + m)
    while (i > 0 && j > 0)
    {
        // if the current character matches.
        if (s[i - 1] == t[j - 1])
        {
            LCS[idx] = s[i - 1];
            idx--;
            i--, j--;
        }
        // not matches, but the dp[i-1][j] > dp[i][j-1] -> means the current dp value comes from the dp[i-1][j], then go to that idx.
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i = i - 1;
        }
        else
        {
            j = j - 1; // current dp value comes from the dp[i][j-1], then go to that idx.
        }
    }

    return dp[n][m];
}

int lcs(string s, string t)
{
    // tabulation ->
    return f(s, t);
}

int main()
{
    string s = "abcde";
    string t = "bgcde";

    int getLcs = f(s, t);

    cout << "the length of the LCS is -> " << getLcs << endl;
    cout << "the LCS string is -> " << LCS << endl;
    return 0;
}
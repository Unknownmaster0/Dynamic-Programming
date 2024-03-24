#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// The problem link is about getting the length but my code is also printing the palindrome which is common.
// Problem link -> https://www.codingninjas.com/studio/problems/longest-palindromic-subsequence_842787?leftPanelTabValue=PROBLEM

/*New approach to solve this question -> directly filling the dp table, and not just create a new string after reversing.
                                            Just traverse the same string.
*/
int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i+1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;    // if we found the both character match, then we can add both character to the palindrome that's why I added 2 here.
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]); // else not matches, then simply take the max of the (left and down).
                }
            }
        }
        return dp[0][n-1];
}


/*Approach -> Palindrome means which is same after reversing the string.*/

string palindrome = "";

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

    int lcsLength = dp[n][n];
    int idx = lcsLength - 1;
    palindrome = string(lcsLength, '@');

    int i = n, j = n;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            palindrome[idx] = s[i - 1];
            idx--, i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    return dp[n][n];
}

int lps(string &s)
{

    string t = s;
    reverse(s.begin(), s.end());

    // Now need to find the longest common subsequence of the s and t string.
    return lcs(s, t);
}

int main()
{
    string s = "bbabcbcab";
    int lengthPalindromic = lps(s);

    cout << "the longest palindromic subsequence lenght is -> " << lengthPalindromic << endl;
    cout << "the longest palindromic subsequence is -> " << palindrome << endl;

    return 0;
}
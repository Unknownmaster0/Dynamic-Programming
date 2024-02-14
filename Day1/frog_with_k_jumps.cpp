#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int energy(int idx, int k, vector<int> &heights, vector<int> &dp)
{
    if (idx == 0)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];

    int minSteps = INT_MAX;

    for (int i = 1; i <= k; i++)
    {
        if (idx - i >= 0)
        {
            int jumps = energy(idx - i, k, heights, dp) + abs(heights[idx] - heights[idx - i]);
            minSteps = min(minSteps, jumps);
        }
    }

    return dp[idx] = minSteps;
}

int tabulation(int n, int k, vector<int> &heights, vector<int> &dp)
{
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jumps = dp[i - j] + abs(heights[i] - heights[i - j]);
                minSteps = min(minSteps, jumps);
            }
        }
        dp[i] = minSteps;
    }

    for (auto it : dp)
    {
        cout << it << " ";
    }
    cout << endl;

    return dp[n-1];
}

int main()
{
    int steps, k;
    cin >> steps;
    cin >> k;
    vector<int> heights;
    for (int i = 0; i < steps; i++)
    {
        int val;
        cin >> val;
        heights.push_back(val);
    }

    vector<int> dp(steps, -1);
    // cout << "total energy -> " << energy(steps - 1, k, heights, dp);
    cout << "tabulation -> " << tabulation(steps, k, heights, dp);

    return 0;
}

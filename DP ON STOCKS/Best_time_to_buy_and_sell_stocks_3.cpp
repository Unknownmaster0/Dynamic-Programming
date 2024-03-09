#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/buy-and-sell-stock_1071012?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

// total -> number of transaction allowed.
/*
int f(int idx, int buy, int total, vector<int> &values, int n, vector<vector<vector<int>>> &dp){
    if(idx >= n)    return 0;
    if(total == 0)  return 0;

    if(dp[idx][buy][total] != -1)  return dp[idx][buy][total];

    if(buy){
        return dp[idx][buy][total] = max(-values[idx] + f(idx + 1, 0, total, values, n, dp) , 0 + f(idx+1, 1, total, values, n, dp));
    }
    else{
        return dp[idx][buy][total] = max(values[idx] + f(idx + 1, 1, total-1, values, n, dp), 0 + f(idx+1, 0, total, values, n, dp));
    }
}
*/

/*
// tabulation
int f(vector<int> &values, int n){

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    // if(idx >= n)    return 0;
    // if(total == 0)  return 0;


    for(int idx=n-1; idx>=0; idx--){
        for(int buy=0; buy<2; buy++){
            for(int total=1; total<=2; total++){ // as total == 0 is the base case, so not compute for that.

                if(buy){
                    dp[idx][buy][total] = max(-values[idx] + dp[idx+1][0][total] , 0 + dp[idx+1][1][total]);
                }
                else{
                    dp[idx][buy][total] = max(values[idx] + dp[idx+1][1][total-1], 0 + dp[idx+1][0][total]);
                }
            }
        }
    }
    return dp[0][1][2];
}
*/

// Space optimisation -> t.c = O(2 * 3) || s.c = O(2 * 3) + O(n)[A.S.S]
int f(vector<int> &values, int n)
{

    vector<vector<int>> after(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));
    // if(idx >= n)    return 0;
    // if(total == 0)  return 0;

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int total = 1; total <= 2; total++)
            { // as total == 0 is the base case, so not compute for that.

                if (buy)
                {
                    curr[buy][total] = max(-values[idx] + after[0][total], 0 + after[1][total]);
                }
                else
                {
                    curr[buy][total] = max(values[idx] + after[1][total - 1], 0 + after[0][total]);
                }
            }
        }
        after = curr;
    }
    return after[1][2];
}


// dp[n][4]
// space optimised memoization code.
int f(int day, int transaction, vector<int> &prices, int n, vector<vector<int>> &dp){
    if(day == n || transaction == 4)    return 0;

    if(dp[day][transaction] != -1)  return dp[day][transaction];

// buy
    if(transaction % 2 == 0){
        return dp[day][transaction] = max( -prices[day] + f(day+1, transaction+1, prices, n, dp), f(day+1, transaction, prices, n, dp) );
    }

// sell
    else{
        return dp[day][transaction] = max( prices[day] + f(day+1, transaction+1, prices, n, dp), f(day+1, transaction, prices, n, dp) );
    }
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // memoization
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    // return f(0, 1, 2, prices, n, dp);


    // space optimised another memoization approach.
    vector<vector<int>> dp(n, vector<int>(4,-1));
    return f(0, 0, prices, n, dp);

    // return f(prices, n);
}

int main()
{

    return 0;
}
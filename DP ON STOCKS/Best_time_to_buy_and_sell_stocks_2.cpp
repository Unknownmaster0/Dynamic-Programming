#include <iostream>
#include <vector>
using namespace std;


// Problem link -> https://www.codingninjas.com/studio/problems/selling-stock_630282?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

/*
// recurrence -> memoization = t.c = O(n * 2) || s.c = O(n * 2) + O(n) [A.S.S]
long f(int idx, int buy, long *values, int n, vector<vector<long>> &dp){
    if(idx >= n)    return 0;

    if(dp[idx][buy] != -1)  return dp[idx][buy];

    long profit = 0;

    if(buy){
        profit = max(-values[idx] + f(idx + 1, 0, values, n, dp) , 0 + f(idx+1, 1, values, n, dp));
    }
    else{
        profit = max(values[idx] + f(idx + 1, 1, values, n, dp), 0 + f(idx+1, 0, values, n, dp));
    }
    return dp[idx][buy] = profit;
}
*/

/*
// memoization -> tabulation => t.c = O(n * 2) || s.c = O(n * 2)
long f(long *values, int n){
    vector<vector<long>> dp(n+1, vector<long>(2, 0));
// Base case -> Nhi bhi doge to chalega, because already dp me sara value 0 se intialised hai, then again assigning 0
//              would not make sense.
    for(int i=0; i<2; i++){
        dp[n][i] = 0;
    }

    for(int idx = n-1; idx >= 0; idx--){
        for(int buy = 0; buy<2; buy++){

            long profit = 0;
            if(buy){
                profit = max(-values[idx] + dp[idx+1][0] , 0 + dp[idx+1][1]);
            }
            else{
                profit = max(values[idx] + dp[idx+1][1], 0 + dp[idx+1][0]);
            }
            dp[idx][buy] = profit;
        }
    }

    return dp[0][1];
}
*/

/*
// tabulation -> Space optimisation => t.c = O(n * 2) || s.c = O(n * 2)
long f(long *values, int n){
    vector<long> prevRow(2, 0), currRow(2, 0);
// Base case -> Nhi bhi doge to chalega, because already dp me sara value 0 se intialised hai, then again assigning 0
//              would not make sense.
    // for(int i=0; i<2; i++){
    //     prevRow[i] = 0;
    // }

    for(int idx = n-1; idx >= 0; idx--){
        for(int buy = 0; buy<2; buy++){

            long profit = 0;
            if(buy){
                profit = max(-values[idx] + prevRow[0] , 0 + prevRow[1]);
            }
            else{
                profit = max(values[idx] + prevRow[1], 0 + prevRow[0]);
            }
            currRow[buy] = profit;
        }
        prevRow = currRow;
    }

    return prevRow[1];
}
*/

// Four variable space optimisation technique.
// t.c = O(n) || s.c = O(1)
long f(long *values, int n)
{
    long prevBuy, prevNotbuy, currBuy, currNotbuy;
    prevBuy = prevNotbuy = 0;
    for (int idx = n - 1; idx >= 0; idx--)
    {
        currBuy = max(-values[idx] + prevNotbuy, prevBuy);
        currNotbuy = max(values[idx] + prevBuy, prevNotbuy);

        prevBuy = currBuy;
        prevNotbuy = currNotbuy;
    }
    return prevBuy;
}

long getMaximumProfit(long *values, int n)
{
    // as there are many overlapping subproblems, thus, memoization
    // vector<vector<long>> dp(n, vector<long>(2, -1));
    // return f(0, 1, values, n, dp);

    return f(values, n);
}

int main()
{

    return 0;
}
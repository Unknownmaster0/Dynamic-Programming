#include<iostream>
#include<vector>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/highway-billboards_3125969?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

/*
// memoization -> t.c = O(n * 2)    ||  s.c = O(n * 2) + O(n)[auxillary stack space]
int f(int idx, int buy, vector<int> &values, int n, vector<vector<int>> &dp){
    if(idx >= n)    return 0;

    if(dp[idx][buy] != -1)  return dp[idx][buy];

    if(buy){
        return dp[idx][buy] = max(-values[idx] + f(idx + 1, 0, values, n, dp) , 0 + f(idx+1, 1, values, n, dp));
    }
    else{
        return dp[idx][buy] = max(values[idx] + f(idx + 2, 1, values, n, dp), 0 + f(idx+1, 0, values, n, dp));
    }
}*/

/*
// tabulation -> t.c = O(n * 2)    ||  s.c = O(n * 2)
int f(vector<int> &values, int n){
    
    vector<vector<int>> dp(n+2, vector<int>(2, 0));

    for(int idx=n-1; idx>=0; idx--){
        for(int buy=0; buy<2; buy++){

            if(buy){
                dp[idx][buy] = max(-values[idx] + dp[idx + 1][0], 0 + dp[idx+1][1]);
            }
            else{
                dp[idx][buy] = max(values[idx] + dp[idx + 2][1], 0 + dp[idx+1][0]);
            }
        }
    }
    return dp[0][1];
}*/


// space optimisation -> t.c = O(n * 2)    ||  s.c = O(2)
int f(vector<int> &values, int n){
    
    vector<int> prev_prev(2,0), prev(2, 0), curr(2, 0);

    for(int idx=n-1; idx>=0; idx--){

        for(int buy=0; buy<2; buy++){

            if(buy){
                curr[buy] = max(-values[idx] + prev[0], 0 + prev[1]);
            }
            else{
                curr[buy] = max(values[idx] + prev_prev[1], 0 + prev[0]);
            }
        }

        prev_prev = prev;
        prev = curr;
    }
return prev[1];
}


int stockProfit(vector<int> &prices){
    int n = prices.size();
    // vector<vector<int>> dp(n, vector<int>(2, -1));
    // return f(0, 1, prices, n, dp);

    return f(prices, n);
}

int main()
{
    
    return 0;
}

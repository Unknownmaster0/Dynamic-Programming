#include<iostream>
#include<vector>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/house-robber_839733?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

// Same question as that of maximum_sum_of_non_adjacent_element with one extra condition that (last and first element are also the adjacent of each other.)
/*to solve this problem we 

as it is said in question that (last and first element) are adjacent to each other. Thus, our answer will not contain the last and first element together at once.
                                                                Thus, we divide the array in two parts in which one have 1st element and other have last element.

        think of wise approach -> Simply divide the given array into two parts.
                                1. which doesn't contains the first element.
                                2. which doesn't contains the last element.
*/

// Time complexity -> O(N) , Space -> O(N + N) [extra O(N) for the auxillary recursion stack space.]
long long int memoization(int n, vector<int>&houses, vector<long long int>&dp){
    if(n == 0)  return houses[0];
    if(dp[n] != -1) return dp[n];
    long long int pick = houses[n];
    if(n-2 >= 0)    pick += memoization(n-2, houses,dp);
    long long int nonpick = memoization(n-1, houses,dp);
    return dp[n] = max(pick, nonpick);
}

// Time complexity -> O(N) , Space -> O(N)
long long int tabulation(vector<int>&houses){
    int n = houses.size();
    vector<long long int>dp(n,-1);
    dp[0] = houses[0];
    // dp[1]= max(houses[0], houses[1]);
    for(int i=1; i<n; i++){
        long long int pick = houses[i];
        if(i-2>=0) pick += dp[i-2];
        long long int nonpick = dp[i-1];

        dp[i] = max(pick, nonpick);
    }
    return dp[n-1];
}

// Time complexity -> O(N) , Space -> O(1)
long long int optimal(vector<int>&houses){
    int n = houses.size();
    long long int prev_prev = 0, prev = houses[0];
    for(int i=1; i<n; i++){
        long long int pick = houses[i];
        if(i-2 >= 0) pick += prev_prev;

        long long int nonpick = prev;

        long long int curr = max(pick, nonpick);

        prev_prev = prev;
        prev = curr;
    }
    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n == 1)  return valueInHouse[0];

// Making two different copy of the current given vector of valueInHouse.
    vector<int> excludingfirst, excludinglast;
    for(int i=0; i<n; i++){
        if(i != 0)  excludingfirst.push_back(valueInHouse[i]);
        if(i != n-1)  excludinglast.push_back(valueInHouse[i]);
    }

    return max(tabulation(excludingfirst), tabulation(excludinglast));
    // return max(optimal(excludingfirst), optimal(excludinglast));
}


int main()
{
    
    return 0;
}
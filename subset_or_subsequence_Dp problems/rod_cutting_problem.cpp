#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

// // memoization -> t.c = O(n * n) || s.c = O(size of rod) + O(n * n)
// int f(int idx,int size, vector<int>& price, vector<vector<int>> &dp){
// 	// Base case ->
// 	if(idx == 0){
// 		return size * price[0];
// 	}

// 	if(dp[idx][size] != -1)	return dp[idx][size];

// 	int notTake = f(idx-1, size, price, dp);
// 	int take = INT_MIN;
// 	int rodlength = idx + 1;
// 	if(rodlength <= size)	take = price[idx] + f(idx, size-rodlength, price, dp);

// 	return dp[idx][size] = max(notTake, take);
// }

// // tabulation -> t.c = O(n * n) || s.c = O(n * n)
// int f(int n, vector<int>& price){
// 	vector<vector<int>>dp(n, vector<int>(n+1, 0));
// 	// Base case ->
// 	// if(idx == 0){
// 	// 	return size * price[0];
// 	// }
// 	for(int size=0; size<=n; size++){
// 		dp[0][size] = price[0] * size;
// 	}

// 	for(int idx=1; idx<n; idx++){
// 		for(int size=0; size<=n; size++){

// 			int notTake = dp[idx-1][size];
// 			int take = INT_MIN;
// 			int rodlength = idx + 1;
// 			if(rodlength <= size)	take = price[idx] + dp[idx][size-rodlength];

// 			dp[idx][size] = max(notTake, take);
// 		}
// 	}

// 	return dp[n-1][n];
// }

// // space optimisation -> t.c = O(n * n) || s.c = O(n)
// int f(int n, vector<int>& price){
// 	vector<int>prev(n+1, 0), curr(n+1, 0);
// 	// Base case ->
// 	// if(idx == 0){
// 	// 	return size * price[0];
// 	// }
// 	for(int size=0; size<=n; size++){
// 		prev[size] = price[0] * size;
// 	}

// 	for(int idx=1; idx<n; idx++){
// 		for(int size=0; size<=n; size++){

// 			int notTake = prev[size];
// 			int take = INT_MIN;
// 			int rodlength = idx + 1;
// 			if(rodlength <= size)	take = price[idx] + curr[size-rodlength];

// 			curr[size] = max(notTake, take);
// 		}
// 		prev = curr;
// 	}

// 	return prev[n];
// }

// space optimisation in single row -> t.c = O(n * n) || s.c = O(n)
int f(int n, vector<int> &price)
{
    vector<int> prev(n + 1, 0);
    // Base case ->
    // if(idx == 0){
    // 	return size * price[0];
    // }
    for (int size = 0; size <= n; size++)
    {
        prev[size] = price[0] * size;
    }

    for (int idx = 1; idx < n; idx++)
    {
        for (int size = 0; size <= n; size++)
        {

            int notTake = prev[size];
            int take = INT_MIN;
            int rodlength = idx + 1;
            if (rodlength <= size)
                take = price[idx] + prev[size - rodlength];

            prev[size] = max(notTake, take);
        }
    }

    return prev[n];
}

int cutRod(vector<int> &price, int n)
{
    // total size of rod = n.
    // vector<vector<int>>dp(n, vector<int>(n+1, -1));
    // return f(n-1, n, price, dp);
    return f(n, price);
}

int main()
{

    return 0;
}
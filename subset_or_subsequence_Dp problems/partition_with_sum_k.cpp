#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/partition-equal-subset-sum_892980?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

// same as the question -> (subset sum to target k) in this folder only.

// memoization -> t.c = O(n * k) || s.c = O(n * k) + O(n) [for ASS]
bool f(int idx, int k, vector<int>& arr, vector<vector<int>>& dp){
	// base case -> 
	if(k == 0)	return true;
	if(idx == 0)	return arr[0] == k;

	if(dp[idx][k] != -1)	return dp[idx][k];

	bool not_take = f(idx-1, k, arr, dp);
	bool take = false;
	if(arr[idx] <= k){
		take = f(idx-1, k-arr[idx], arr, dp);
	}

	return dp[idx][k] = take || not_take;
}

// // tabulation -> t.c = O(n * k) || s.c = O(n * k)
//  k -> target
// bool f(int n, int k, vector<int>& arr){
// 	vector<vector<bool> > dp(n, vector<bool> (k+1, false));
// 	// base case -> 
// 	// if(k == 0)	return true;
// 	for(int i=0; i<n; i++)	dp[i][0] = true;
// 	// if(idx == 0)	return arr[0] == k;
// 	if(arr[0] <= k) dp[0][arr[0]] = true;

// 	for(int i=1; i<n; i++){
// 		for(int tar = 1; tar<=k; tar++){
// 			bool not_take = dp[i-1][tar];
// 			bool take = false;
// 			if(arr[i] <= tar){
// 				take = dp[i-1][tar-arr[i]];
// 			}
			
// 			dp[i][tar] = take || not_take;
// 		}
// 	}

// 	return dp[n-1][k];
// }

// space optimisation -> t.c = O(n * k) || s.c = O(k)
bool f(int n, int k, vector<int>& arr){
	vector<bool> prev(k+1, false);
	// base case -> 
	// for(int i=0; i<n; i++)	dp[i][0] = true;	// in place of this line write the below one
	prev[0] = true;

	// dp[0][arr[0]] = true;
	if(arr[0] <= k) prev[arr[0]] = true;

// replace -> dp[i-1]= prev, dp[i] = curr;
	for(int i=1; i<n; i++){
		vector<bool>curr(k+1, false); curr[0] = true;
		for(int tar = 1; tar<=k; tar++){
			bool not_take = prev[tar];
			bool take = false;
			if(arr[i] <= tar){
				take = prev[tar-arr[i]];
			}
			
			curr[tar] = take || not_take;
		}
		prev = curr;
	}

	return prev[k];
}


bool canPartition(vector<int> &arr, int n)
{
	int sum = 0;
	for(auto it:arr){
		sum += it;
	}

	if(sum % 2 != 0)	return false;

	// vector<vector<int> > dp(n, vector<int> (sum/2+1, -1));
	// return f(n-1, sum/2, arr, dp);

	// for tabulation
	return f(n, sum/2, arr);
}


int main()
{

    return 0;
}
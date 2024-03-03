#include <iostream>
#include <vector>
using namespace std;


// Problem link -> https://www.codingninjas.com/studio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=DISCUSS

int mod = 1e9+7;

// // recurrence -> t.c = O(2^n)  || 	s.c = O(n) [auxillary stack space.]
// int f(int k, vector<int>& a, int idx){

// 	if(idx == 0){
// 		if(k == 0 && a[0] == 0)	return 2;
// 		if(k == 0 || a[0] == k)	return 1;
// 		return 0;
// 	}

// 	int not_take = f(k, a, idx-1);
// 	int take = 0;
// 	if(a[idx] <= k)	take = f(k-a[idx], a, idx-1);

// 	return take+not_take;
// }

// // memoization -> t.c = O(n * k)  || 	s.c = O(n* k) + O(n) [auxillary stack space.]
// int f(int k, vector<int>& a, int idx, vector<vector<int>>& dp){
// 	// base cases -> 
	// if(idx == 0){
	// 	if(k == 0 && a[0] == 0)	return 2;
	// 	if(k == 0 || a[0] == k)	return 1;
	// 	return 0;
	// }

// 	if(dp[idx][k] != -1)	return dp[idx][k];

// 	int not_take = f(k, a, idx-1, dp);
// 	int take = 0;
// 	if(a[idx] <= k)	take = f(k-a[idx], a, idx-1, dp);

// 	return dp[idx][k] = (take + not_take) % mod;
// }

// // tabulation code -> t.c = O(n * k)  || 	s.c = O(n* k)
// int f(int k, vector<int>& a, int n){
// 	vector<vector<long long>> dp(n, vector<long long>(k+1, 0));
// 	// base cases -> 
// 	for(int i=0; i<n; i++){
// 		if(i ==0 && a[i] == 0)  dp[0][0] = 2;
// 		else
// 			dp[i][0] = 1;	// if(k == 0)	return 1;
// 	} 
// 	if(a[0] <= k) dp[0][a[0]] = 1;	// if(idx==0) return (a[0] == k);

// 	for(int i=1; i<n; i++){
// 		for(int tar = 1; tar<=k; tar++){
// 			long long int not_take = dp[i-1][tar];
// 			long long int take = 0;
// 			if(a[i] <= tar)	take = dp[i-1][tar-a[i]];

// 			dp[i][tar] = (take + not_take) % mod;
// 		}
// 	}

// 	return dp[n-1][k] % mod;
// }

// space optimised code -> t.c = O(n * k)  || 	s.c = O(k)
int f(int k, vector<int>& a, int n){
	vector<int> prev(k+1, 0);
	// base cases -> 
	if(a[0] == 0) prev[0] = 2;
	else
		prev[0] = 1;	// if(k == 0)	return 1;
	if(a[0] <= k) prev[a[0]] = 1;	// if(idx==0) return (a[0] == k);

	for(int i=1; i<n; i++){
		vector<int> curr(k+1, 0);
		// curr[0] = 1; // if inside loop tar will start from 0, then it is not needed.
		for(int tar = 0; tar<=k; tar++){
			int not_take = prev[tar];
			int take = 0;
			if(a[i] <= tar)	take = prev[tar-a[i]];

			curr[tar] = (take + not_take) % mod;
		}
		prev = curr;
	}

	return prev[k];
}

int findWays(vector<int>& a, int k)
{
	// vector<vector<int>> dp(arr.size(), vector<int>(k+1, -1));
	// return f(k, arr, arr.size()-1, dp);
	return f(k, a, a.size());
}


int main()
{

    return 0;
}
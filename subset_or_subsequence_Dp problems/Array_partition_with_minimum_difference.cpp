#include<iostream>
#include<vector>
using namespace std;

// elongate problem of the subset sum with target k.

// problem link -> https://www.codingninjas.com/studio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION

// code -> 

// space optimised code -> t.c = O(n * target) || s.c = O(target)
int f(int n, vector<int>& arr, int target){
	vector<bool>prevRow(target+1, false);
	// store the base caes 
	//when the totalSum == 0 , then whatever is the idx, the value is true.
	for(int i=0; i<n; i++) prevRow[0] =true;

	if(arr[0] <= target) prevRow[arr[0]] = true; // if(idx ==0 )  return (arr[0] == target)

	// now iterate over the loops
	for(int i=1; i<n; i++){
		vector<bool> currRow(target+1, false);
		currRow[0] = true;
		for(int k=1; k<=target; k++){
			bool not_take = prevRow[k];
			bool take = false;
			if(arr[i] <= k){
				take = prevRow[k-arr[i]];
			}

			currRow[k] = take || not_take;
		}
		prevRow = currRow;
	}

	// now the dp table is ready. Go and find the minimum sum from the dp.
	int mini = 1e8;
	for(int i=0; i<=target/2; i++){     // here you can go till target but the differnce value of sum1 and sum2 will goes on repeating same.
		if(prevRow[i] == true){
			int sum1 = i; // sum of the first subset.
			int sum2 = target - i; // sum of the second subset.
			
			mini = min(mini, abs(sum2-sum1));
		}
	}
	return mini;
}


// // tabulation code -> t.c = O(n * target) || s.c = O(n * target)
// int f(int n, vector<int>& arr, int target){
// 	vector<vector<bool>>dp(n, vector<bool>(target+1, false));
// 	// store the base caes 
// 	//when the totalSum == 0 , then whatever is the idx, the value is true.
// 	for(int i=0; i<n; i++) dp[i][0 ] =true;

// 	if(arr[0] <= target) dp[0][arr[0]] = true; // if(idx ==0 )  return (arr[0] == target)

// 	// now iterate over the loops
// 	for(int i=1; i<n; i++){
// 		for(int k=1; k<=target; k++){
// 			bool not_take = dp[i-1][k];
// 			bool take = false;
// 			if(arr[i] <= k){
// 				take = dp[i-1][k-arr[i]];
// 			}

// 			dp[i][k] = take || not_take;
// 		}
// 	}

// 	// now the dp table is ready. Go and find the minimum sum from the dp.
// 	int mini = 1e8;
// 	for(int i=0; i<=target; i++){
// 		if(dp[n-1][i] == true){
// 			int sum1 = i; // sum of the first subset.
// 			int sum2 = target - i; // sum of the second subset.
			
// 			mini = min(mini, abs(sum2-sum1));
// 		}
// 	}
// 	return mini;
// }

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalSum = 0;
	for(auto it:arr)	totalSum += it;
	// tabulation code of the subset sum with target equl to k
	return f(n, arr, totalSum);
}


int main()
{
    
    return 0;
}
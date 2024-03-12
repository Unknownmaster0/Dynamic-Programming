#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/divisible-set_3754960?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

// A subset is nothing but any possible combination of the original array.
// subset is not following the order of the original array.

// t.c = O(n^2) || s.c = O(n)
vector<int> divisibleSet(vector<int> &arr)
{
    int n = arr.size();
    // step 1 -> sort array
    sort(arr.begin(), arr.end());

    // step 2 -> declare dp, hash, maxIndex, maxLength;
    int maxIndex = 0, maxLength = -1;
    vector<int> dp(n, -1), hash(n);

    for(int i=0; i<n; i++){
        hash[i] = i;
        for(int j=0; j<i; j++){
            
            if( (arr[i] % arr[j] == 0 || arr[j] % arr[i] == 0) && (1 + dp[j] > dp[i])){
                
                dp[i] = 1+ dp[j];
                hash[i] = j;
            }
        }
        if (maxLength < dp[i]) {

            maxLength = dp[i];
            maxIndex = i;
        }
    }

    vector<int> ans;
    ans.push_back(arr[maxIndex]);

    while (maxIndex != hash[maxIndex]) {
        maxIndex = hash[maxIndex];
        ans.push_back(arr[maxIndex]);
    }

    return ans;
}


int main()
{
    
    return 0;
}
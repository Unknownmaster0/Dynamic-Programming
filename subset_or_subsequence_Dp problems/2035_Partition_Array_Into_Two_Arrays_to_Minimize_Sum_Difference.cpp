#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Problem link -> https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/

/* MEET IN MIDDLE APPROACH.*/

// code->
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        // dp will not work here becaue the tabulation or bottom up arroach to solve this question is -> 
        // O(totalSum * nums.size()) // which will totalSum will be 10^8 which will give TLE.

        // Apply the approach [MEET IN MIDDLE]
        int N = nums.size();
        int n = N/2; // this is the each subset size.

        int totalSum = 0;
        for(auto it:nums){
            totalSum += it;
        }

        vector<vector<int>> left(n+1, vector<int>()), right(n+1, vector<int>());

        // now push the sum of each subset into the left and right.
        for(int mask = 0; mask < (1<<n); mask++){
            int size = 0, leftSum = 0, rightSum = 0;
            for(int i=0; i<n; i++){

                if(mask & (1 << i)){
                    size++;
                    leftSum += nums[i];
                    rightSum += nums[i+n];
                }
            }

            left[size].push_back(leftSum);
            right[size].push_back(rightSum);
        }

        // now sort the right part.
        for(int i=0; i<n; i++)
            sort(right[i].begin(), right[i].end());

        // now you need to update the answer.
        // int ans = min( abs(totalSum - left[n][0]), abs(totalSum - right[n][0]) );
        int ans = min( abs(totalSum - 2*left[n][0]), abs(totalSum - 2*(right[n][0])) );

        for(int size = 1; size<n; size++){

            for(auto it:left[size]){
                int leftVal = it;
                int rightVal = (totalSum - 2*leftVal) / 2, rightSize = n-size;

                // now apply binary search on the right part and find closest value to the rightVal.
                auto itr = lower_bound(right[rightSize].begin(), right[rightSize].end(), rightVal);
                // value given by the lower_bound is *it.
                // int value;
                if(itr != right[rightSize].end()){

                    ans = min(ans, abs(totalSum - 2*(leftVal + *(itr))));
                }  
                // value = *itr;
                if(itr != right[rightSize].begin()){
                    auto it = itr;
                    --it;
                    // value = *it;
                    ans = min(ans, abs(totalSum - 2*(leftVal + *(it))));
                }
            }
        }

        return ans;
    }
};

int main()
{
    
    return 0;
}
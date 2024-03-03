#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM


// memoization -> t.c = O(n * target) || s.c = O(n * target) + O(target)
// long f(int idx, int value, int *a, vector<vector<long>>& dp){
//     if(idx == 0){
//         return (value % a[0]) == 0;
//     }
    
//     if(dp[idx][value] != -1)    return dp[idx][value];
    
//     long notTake = f(idx-1, value, a, dp);
//     long take = 0;
//     if(a[idx] <= value) take = f(idx, value-a[idx], a, dp);

//     return dp[idx][value] = take + notTake;
// }


// // tabulation -> t.c = O(n * target) || s.c = O(n * target)
// long f(int n, int value, int *a){
//     vector<vector<long>> dp(n, vector<long>(value+1, 0));

//     // if(idx == 0){
//     //     return (value % a[0]) == 0;
//     // }
//     for(int tar = 0; tar<= value; tar++){
//         if(tar % a[0] == 0)   dp[0][tar] = 1;
//         else
//             dp[0][tar] = 0;
//     }

//     for(int idx=1; idx<n; idx++){
//         for(int tar=0; tar<=value; tar++){
//             long notTake = dp[idx-1][tar];
//             long take = 0;
//             if(a[idx] <= tar) take = dp[idx][tar-a[idx]];

//             dp[idx][tar] = take + notTake;
//         }
//     }

//     return dp[n-1][value];
// }



// space optimisation using two row.-> t.c = O(n * target) || s.c = O(target)
long f(int n, int value, int *a){
    vector<long> prevRow(value+1, 0), currRow(value+1, 0);
    // if(idx == 0){
    //     return (value % a[0]) == 0;
    // }
    for(int tar = 0; tar<= value; tar++){
        if(tar % a[0] == 0)   prevRow[tar] = 1;
        else
            prevRow[tar] = 0;
    }

    for(int idx=1; idx<n; idx++){
        for(int tar=0; tar<=value; tar++){
            long notTake = prevRow[tar];
            long take = 0;
            if(a[idx] <= tar) take = currRow[tar-a[idx]];

            currRow[tar] = take + notTake;
        }
        prevRow = currRow;
    }

    return prevRow[value];
}



long countWaysToMakeChange(int *denominations, int n, int value)
{
    // MEMOIZATION -> 
    // vector<vector<long>> dp(n, vector<long>(value+1, -1));
    // return f(n-1, value, denominations, dp);

    // TABULATION or Space OPTIMISATION-> 
    return f(n, value, denominations);
}

int main()
{

    return 0;
}
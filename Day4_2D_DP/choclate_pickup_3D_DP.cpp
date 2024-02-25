#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

// Dp on fixed starting point but two starting point and variable ending point.

// memoization -> t.c = O(n * m * m) || s.c = O(n * m * m) [for dp] + O(n) [for auxillary stack space]
int f(int i, int ja, int jb, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (i == n - 1)
    {
        if (ja == jb)
            return grid[i][ja];
        else
            return grid[i][ja] + grid[i][jb];
    }

    if (dp[i][ja][jb] != -1)
        return dp[i][ja][jb];

    int maxi = -1e9;
    // state change.
    for (int da = -1; da <= 1; da++)
    {
        for (int db = -1; db <= 1; db++)
        {
            int val = 0;
            if (ja == jb)
                val = grid[i][ja];
            else
                val = grid[i][ja] + grid[i][jb];

            // val += f(i+1, ja+da, jb+db, n, m, grid, dp);
            if (ja + da >= 0 && ja + da < m && jb + db >= 0 && jb + db < m)
            {
                val += f(i + 1, ja + da, jb + db, n, m, grid, dp);
            }
            else
            {
                val = -1e8;
            }
            maxi = max(maxi, val);
        }
    }
    return dp[i][ja][jb] = maxi;
}

// // tabulation code. t.c = O(n * m * m) || s.c = O(n * m * m)
// int f(int n, int m, vector<vector<int>>& grid){
//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int> (m, -1)));

//     for(int j1=0; j1<m; j1++){
//         for(int j2=0; j2<m; j2++){
//             if(j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
//             else
//                 dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
//         }
//     }

//     for(int i=n-2; i>=0; i--){
//         for(int ja=0; ja<m; ja++){
//             for(int jb=0; jb<m; jb++){
//                 int maxi = -1e8;
//                 // state change.
//                 for(int da=-1; da<=1; da++){
//                   for (int db = -1; db <= 1; db++) {
//                     int val = INT_MIN;

//                     if(ja+da >= 0 && ja+da < m && jb+db >=0 && jb+db < m){
//                         if(ja == jb) val = grid[i][ja];
//                         else val = grid[i][ja] + grid[i][jb];
//                         val += dp[i+1][ja+da][jb+db];
//                     }
//                     maxi = max(maxi, val);
//                   }
//                 }
//                 dp[i][ja][jb] = maxi;
//             }
//         }
//     }

//     return dp[0][0][m-1];
// }

// space optimisation one. || t.c = O(n * m * m) || s.c = O(m * m) [removing 3D dp]
int f(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> frontRow(m, vector<int>(m, 0));

    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                frontRow[j1][j2] = grid[n - 1][j1];
            else
                frontRow[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        vector<vector<int>> currRow(m, vector<int>(m, 0));
        for (int ja = 0; ja < m; ja++)
        {
            for (int jb = 0; jb < m; jb++)
            {
                int maxi = -1e8;
                // state change.
                for (int da = -1; da <= 1; da++)
                {
                    for (int db = -1; db <= 1; db++)
                    {
                        int val = INT_MIN;

                        if (ja + da >= 0 && ja + da < m && jb + db >= 0 && jb + db < m)
                        {
                            if (ja == jb)
                                val = grid[i][ja];
                            else
                                val = grid[i][ja] + grid[i][jb];
                            val += frontRow[ja + da][jb + db];
                        }
                        maxi = max(maxi, val);
                    }
                }
                currRow[ja][jb] = maxi;
            }
        }
        frontRow = currRow;
    }

    return frontRow[0][m - 1];
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    // for memoization ->
    // vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    // return f(0, 0, c-1, r, c, grid, dp);
    return f(r, c, grid);
}

int main()
{

    return 0;
}
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION

// T.c = O(N * 4 * 3)   S.c = O(N) + O(N*4) [O(N) -> for auxillary stack space of recursion]
int memoization(int day, int lastTask, vector<vector<int>> &dp,
                vector<vector<int>> &points) {
  // base case
  if (day == 0) {
    int maxi = INT_MIN;
    for (int i = 0; i < 3; i++) {
      if (i != lastTask)
        maxi = max(maxi, points[0][i]);
    }
    return maxi;
  }

  if (dp[day][lastTask] != -1)
    return dp[day][lastTask];

  int maxi = INT_MIN;
  for (int i = 0; i < 3; i++) {
    int pts = INT_MIN;
    if (i != lastTask)
      pts = points[day][i] + memoization(day - 1, i, dp, points);
    maxi = max(maxi, pts);
  }
  return dp[day][lastTask] = maxi;
}

// T.c = O(N * 4 * 3)   S.c = O(N*4) 
int tabulation(int n, vector<vector<int>> &points) {
  vector<vector<int>> dp(n, vector<int>(4, -1));
  // dp[0][0], dp[0][1], dp[0][2], dp[0][3] -> value storing. // base cases of
  // memoization
  for (int lastTask = 0; lastTask < 4; lastTask++) {
    int maxi = 0;
    for (int currTask = 0; currTask < 3; currTask++) {
      if (lastTask != currTask)
        maxi = max(maxi, points[0][currTask]);
    }
    dp[0][lastTask] = maxi;
  }

  for (int day = 1; day < n; day++) {
    for (int lastTask = 0; lastTask < 4; lastTask++) {
        int maxi = 0;
      for (int currTask = 0; currTask < 3; currTask++) {
          if(currTask != lastTask){
            int pts = points[day][currTask] + dp[day-1][currTask];
            maxi = max(maxi, pts);
          }
      }
      dp[day][lastTask] = maxi;
    } 
  }

  // find the max of the last day and return 
//   return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));

//  (above is also computing the same thing.)
// where is your answer store-> the first recursion call that you are making in the memoization
    return dp[n-1][3];
}

// T.c = O(N * 4 * 3)   S.c = O(4) [nearly about constant]
int spaceOptimisation(int n, vector<vector<int>> &points) {
  vector<int> prev(4, -1);
  // dp[0][0], dp[0][1], dp[0][2], dp[0][3] -> value storing. // base cases of
  // memoization
  for (int lastTask = 0; lastTask < 4; lastTask++) {
    int maxi = 0;
    for (int currTask = 0; currTask < 3; currTask++) {
      if (lastTask != currTask)
        maxi = max(maxi, points[0][currTask]);
    }
    prev[lastTask] = maxi;
  }

  for (int day = 1; day < n; day++) {
    for (int lastTask = 0; lastTask < 4; lastTask++) {
        int maxi = 0;
      for (int currTask = 0; currTask < 3; currTask++) {
          if(currTask != lastTask){
            int pts = points[day][currTask] + prev[currTask];
            maxi = max(maxi, pts);
          }
      }
      prev[lastTask] = maxi;
    } 
  }
  return prev[3];
}

int ninjaTraining(int n, vector<vector<int>> &points) {
  // as this is overlapping subproblems we need the dp[n][4]
  // vector<vector<int>> dp(n, vector<int>(4,-1));
  // return memoization(n-1,3,dp,points); // day, lastTask, dp, points.
  return tabulation(n, points);
}

int main()
{

    return 0;
}
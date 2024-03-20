#include <iostream>
#include <vector>
using namespace std;

// problem link -> https://www.codingninjas.com/studio/problems/maximum-size-rectangle-sub-matrix-with-all-1-s_893017?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

// pre-requisite -> The Largest Rectangle in Histogram question.

// code ->
#include <bits/stdc++.h>

// this function is using the largest rectangle histogram question code.
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st; // monotonic stack

    int width = 0, maxArea = 0;
    // Optimal solution ->> JUst need one pass of the array.
    // t.c = O(N) + O(N) || s.c = O(N)
    for (int i = 0; i <= n; i++)
    {

        while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
        {

            int right = i;
            int element = heights[st.top()];
            st.pop();
            int left;
            if (st.empty())
                width = right;
            else
            {
                left = st.top();
                width = right - left - 1;
            }

            maxArea = max(element * width, maxArea);
        }
        st.push(i);
    }

    return maxArea;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m)
{

    // now need to pass the each row to the above function
    int maxArea = 0;
    vector<int> arr(m, 0);

    for (int i = 0; i < m; i++)
    {
        arr[i] = mat[0][i];
    }

    maxArea = max(maxArea, largestRectangleArea(arr));

    for (int row = 1; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (mat[row][col] == 0)
                arr[col] = 0;
            else
            {
                arr[col]++;
            }
        }

        maxArea = max(maxArea, largestRectangleArea(arr));
    }

    return maxArea;
}

int main()
{
    cout<<"sagar singh is the Boss!"<<endl;
    return 0;   
}
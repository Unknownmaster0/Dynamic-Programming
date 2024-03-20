#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Not a DP question but important.

// Problem link -> https://leetcode.com/problems/largest-rectangle-in-histogram/

// Code

// OPTIMAL SOLUTION
// T.C = O(N)   ||  S.C = O(N)
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st; // monotonic stack

        int width = 0, maxArea = 0;
// Optimal solution ->> JUst need one pass of the array.
// t.c = O(N) + O(N) || s.c = O(N)
        for(int i=0; i<=n; i++){

            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){

                int right = i;
                int element = heights[st.top()];
                st.pop();
                int left;
                if(st.empty())  width = right;
                else{
                    left = st.top();
                    width = right - left - 1;
                }

                maxArea = max(element * width, maxArea);
            }
            st.push(i);
        }

        return maxArea;
    }


class Solution
{
public:
    // t.c = O(4*n)     [t.c = O(2*n) for traversing twice the array, and O(2*n) for poping out the stack element ]

    // and s.c = O(3*n) [O(2*n) -> for each left and right array, and O(N)-> for stack.]

    int largestRectangleArea(vector<int> &heights)
    {
        // creating the leftSmallest and rightSmallest array

        // LeftSmallest -> The first smallest element that come on the left of the curr element. But we store just 1 more index to it, as we have to get the boundary.
        // RightSmallest -> The first smallest element that come on the right of the curr element. But we store just 1 less index to it, as we have to get the boundary.

        int n = heights.size();
        vector<int> left(n, 0), right(n, n - 1);
        stack<int> st; // monotonic stack
        st.push(0);
        // for leftSmallest
        for (int i = 1; i < n; i++)
        {

            int curr = heights[i];
            while (!st.empty() && heights[st.top()] >= curr)
            {
                st.pop();
            }

            if (st.empty())
            {
                left[i] = 0;
            }
            else
            {
                left[i] = st.top() + 1;
            }
            st.push(i);
        }

        // for rightSmallest
        st = stack<int>();
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--)
        {

            int curr = heights[i];
            while (!st.empty() && heights[st.top()] >= curr)
            {
                st.pop();
            }

            if (st.empty())
            {
                right[i] = n - 1;
            }
            else
            {
                right[i] = st.top() - 1;
            }
            st.push(i);
        }

        int area = 0, maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            area = heights[i] * (right[i] - left[i] + 1);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

// Brute solution is here.
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Brute way -> just finding out the left and right first smaller guy for each element.
    // t.c = O(n^2) || s.c = O(1)
    int maxArea = -1;
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];

        // find right smaller guy
        int j = i + 1;
        while (j < n && arr[j] >= curr)
            j++;
        // now right smaller is lies at idx = j, so we need to take just previous index to that.
        int rightIdx = j - 1;

        // find the left smaller guy
        int k = i - 1;
        while (k >= 0 && arr[k] >= curr)
        {
            k--;
        }
        // now left smaller is lies at idx = k, so we need to take just next index to that.
        int leftIdx = k + 1;

        maxArea = max(maxArea, curr * (rightIdx - leftIdx + 1));
    }

    cout << "The area is -> " << maxArea << endl;

    return 0;
}
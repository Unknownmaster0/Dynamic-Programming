#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/matrix-exponentiation2711/1

// visit this link if any doubt -> https://www.geeksforgeeks.org/matrix-exponentiation/

class Solution
{

    int mod = 1e9 + 7;

    vector<vector<long long>> multiply(vector<vector<long long>> &first, vector<vector<long long>> &second)
    {

        int n = first.size();
        int r = second.size();
        int c = second[0].size();
        vector<vector<long long>> ans(n, vector<long long>(c, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < c; j++)
            {
                for (int k = 0; k < r; k++)
                {

                    ans[i][j] += (first[i][k] * second[k][j]) % mod;
                }
            }
        }

        return ans;
    }

    vector<vector<long long>> fastPower(vector<vector<long long>> &mat, long long n)
    {

        if (n == 1)
            return mat;

        long long half = n / 2;

        vector<vector<long long>> ans = fastPower(mat, half);

        ans = multiply(ans, ans);

        if (n % 2 == 1)
        {
            ans = multiply(ans, mat);
        }

        return ans;
    }

public:
    int FindNthTerm(long long int n)
    {

        if (n == 0 || n == 1)
            return 1;

        vector<vector<long long>> mat(2, vector<long long>(2, 0));
        mat[0][0] = mat[0][1] = mat[1][0] = 1;
        mat[1][1] = 0;

        vector<vector<long long>> intial(2, vector<long long>(1, 0));
        intial[0][0] = intial[1][0] = 1;

        // multiplying the second matrix with (n-1) times.
        vector<vector<long long>> ans = fastPower(mat, n - 1);

        // multiplying second matrix with third matrix.
        ans = multiply(ans, intial);

        return ans[0][0] % mod;
    }
};

int main()
{

    return 0;
}
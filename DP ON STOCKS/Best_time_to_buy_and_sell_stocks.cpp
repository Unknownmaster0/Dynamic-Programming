#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.codingninjas.com/studio/problems/stocks-are-profitable_893405?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

int maximumProfit(vector<int> &prices)
{
    int mini = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        mini = min(mini, prices[i]);
        maxProfit = max(maxProfit, (prices[i] - mini));
    }
    return maxProfit;
}

int main()
{

    return 0;
}
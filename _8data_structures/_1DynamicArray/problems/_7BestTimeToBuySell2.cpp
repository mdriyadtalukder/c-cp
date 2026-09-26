// buy sell buy sell.this way it will go as many as it will go..not buy buy or sell sell..
// p[i]>p[i-1] follow it;
#include <bits/stdc++.h>
using namespace std;

// brute force

int solve(vector<int> &prices, int day, int n, bool buy)
{
    if (day >= n)
        return 0;

    int profit = 0;

    if (buy)
    { // buy
        int take = solve(prices, day + 1, n, false) - prices[day]; //kinle to amr tk kombei..take = future profit - buying price
        int not_take = solve(prices, day + 1, n, true);

        profit = max({profit, take, not_take});
    }
    else
    { // sell
        int sell = prices[day] + solve(prices, day + 1, n, true); //bechle to amr tk barbei ..sell = selling price + future profit
        int not_sell = solve(prices, day + 1, n, false);

        profit = max({profit, sell, not_sell});
    }

    return profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    return solve(prices, 0, n, true);
}

// optimal
int maxProfit(vector<int> &prices)
{

    int max = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i - 1])
        {
            max += prices[i] - prices[i - 1];
        }
    }
    return max;
}
int main()
{
    vector<int> v = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(v);
}
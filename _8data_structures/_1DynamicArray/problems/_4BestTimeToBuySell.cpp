#include <bits/stdc++.h>
using namespace std;
// buy once and sell once...price(buy er price) joto kom hbe and max(sell er profit) joto boro hbe..

// brute force
int maxProfit(vector<int> &prices)
{
    int ans = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        int p = prices[i];

        for (int j = i + 1; j < prices.size(); j++) // i+1 for future element
        {
            ans = max(ans, prices[j] - p);
        }
    }

    return ans;
}

// optimal
int maxProfit2(vector<int> &prices)
{
    int p = prices[0];
    int mx = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        if (p > prices[i])
        {
            p = prices[i];
        }

        if (prices[i] - p > mx)
        {
            mx = prices[i] - p;
        }
    }

    return mx;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int ans = maxProfit(prices);

    cout << "Max Profit: " << ans << endl;

    return 0;
}
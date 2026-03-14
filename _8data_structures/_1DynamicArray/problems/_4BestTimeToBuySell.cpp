#include <bits/stdc++.h>
using namespace std;
// buy once and sell once
int maxProfit(vector<int> &prices)
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
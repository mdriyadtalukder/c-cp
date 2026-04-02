// buy sell buy sell.this way it will go as many as it will go..not buy buy or sell sell..
// p[i]>p[i-1] follow it;
#include <bits/stdc++.h>
using namespace std;
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
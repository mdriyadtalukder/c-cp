// pani kon dik diye porbe right or left..jeta choto oita diye porbe.left and right er max height ber krbo then oi 2 tar min ber kre current height er shthe minus krbo.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> height = {4, 3, 0, 2, 3, 5};
    int n = height.size();
    vector<int> lmax(n, 0);
    vector<int> rmax(n, 0);
    lmax[0] = height[0];
    rmax[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++)
    {
        lmax[i] = max(lmax[i - 1], height[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        rmax[i] = max(rmax[i + 1], height[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(lmax[i], rmax[i]) - height[i];
    }
    cout << ans;

    /*two pointer approach

    int n = heights.size();
    int ans = 0;
    int l = 0, r = n - 1, lmax = 0, rmax = 0;
    while (l < r)
    {
        lmax = max(lmax, heights[l]);
        rmax = max(rmax, heights[r]);
        if (lmax < rmax)
        {
            ans += lmax - heights[l];
            l++;
        }
        else
        {
            ans += rmax - heights[r];
            r--;
        }
        return ans;*/
}
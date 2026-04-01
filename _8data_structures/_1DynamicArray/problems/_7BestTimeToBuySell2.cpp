// buy sell buy sell.this way it will go as many as it will go..not buy buy or sell sell..
// p[i]>p[i-1] follow it;
#include <bits/stdc++.h>
using namespace std;
long long abc(vector<int> &nums)
{
    long long c = 0, r = 0;
    for (int i = 0; i < nums.size(); i++)
    {

        if (nums[i] == 0)
        {
            c++;
        }
        else
        {
            r = r + ((c * 2) - 1);
            c = 0;
        }
    }
    return r;
}
int main()
{
    vector<int> v = {1, 3, 0, 0, 2, 0, 0, 4};
    cout << abc(v);
}
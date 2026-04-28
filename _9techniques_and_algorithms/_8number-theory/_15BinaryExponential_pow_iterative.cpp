// recursion er cheye iterative valo besi..1st chole besi than recursive
//TC=O(logn)
#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int binExpIter(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % M;
        }
        a = (a * 1LL * a) % M;
        b >>= 1;
    }
    return ans;
}
int main()
{
    int a = 2123123, b = 1231231;
    cout << binExpIter(a, b) << endl;
    // cout << pow(a, b);
}
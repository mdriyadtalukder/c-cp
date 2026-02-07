#include <bits/stdc++.h>
using namespace std;
int main()
{
    int length = 6;
    float key = 0;
    if (length % 2 == 0)
    {
        key = (length / 2) + 1;
    }
    else
    {
        key = ceil((float)length / 2);
    }
    cout << key;
}
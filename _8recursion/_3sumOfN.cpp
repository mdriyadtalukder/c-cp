#include <bits/stdc++.h>
using namespace std;
int sum(int n)
{
    if (n == 1)
    {
        return 1; // when 1 then it will go n=2 stack part and n+fact(n-1)=2+fact(1)=2+1=3
    }
    return n + sum(n - 1);
}
int main()
{
    int n = 3;
    cout << sum(n);
}
#include <bits/stdc++.h>
using namespace std;
int fact(int n) // 0!=1;
{
    if (n == 0)
    {
        return 1; // when 0 then it will go n=1 stack part and n*fact(n-1)=1*fact(0)=1*1=1
    }
    return n * fact(n - 1);
}
int main()
{
    int n = 5;
    cout << fact(5);
}
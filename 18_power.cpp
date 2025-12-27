#include <iostream>
#include <cmath> //for using math operation
using namespace std;
main()
{
    int n;
    cin >> n;
    int b = 0;
    for (int i = 1; i <= n; i++)
    {
        b = b + pow(i, 5);
    }
    cout << b;
}
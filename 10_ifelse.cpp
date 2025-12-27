#include <iostream>
using namespace std;
main()
{
    int a, b;
    cout << "Input for odd or even number: ";
    cin >> a;
    cout << "Input for pass or fail: ";
    cin >> b;
    if (a % 2 == 0)
    {
        cout << "Even";
    }
    else
    {
        cout << "Odd";
    }

    if (b >= 33 && b < 80)
    {
        cout << "Pass";
    }
    else if (b >= 80 && b <= 100)
    {
        cout << "A+";
    }
    else if (b > 100 || b < 0)
    {
        cout << "Not allowed";
    }
    else
    {
        cout << "fail";
    }
}
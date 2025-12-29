#include <iostream>
using namespace std;
main()
{
    double celsius, f;
    cout << "Enter fahrenheit: ";
    cin >> f;
    f = (f - 32) / 1.8;
    cout << "Result " << f;
    return 0;
}
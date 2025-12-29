#include <iostream>
using namespace std;
main()
{
    double base, height, tringle;
    cout << "Enter base and height of tringle: ";
    cin >> base >> height;
    tringle = (double)1 / 2 * (base * height); // we need to set double data type of 1 otherwise it get 0 result;
    cout << "result:" << tringle;
}
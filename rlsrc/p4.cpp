#include <iostream>
using namespace std;

int main()
{
    int num = 181;
    // Extract bits 2 to 5 (0-based from LSB).
    int bits = (num >> 2) & ((1 << 4) - 1);

    cout << bits << endl;

    // extract bits and compare
    int a = 181;
    int b = 245;

    int x = (a >> 2) & 15;
    int y = (b >> 2) & 15;

    if (x == y)
        cout << "Equal";
    else
        cout << "Not Equal";
}
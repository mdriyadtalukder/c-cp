#include <iostream>
using namespace std;
main()
{
    int a, b; // 4
    int sum = (a = 2, b = 3, sum = a + b);

    float f;     // 4
    double d;    // 8
    char c;      // 1
    char ch[20]; // 20
    cout << sum << endl;

    int s = sizeof(a);
    cout << s << endl;
}
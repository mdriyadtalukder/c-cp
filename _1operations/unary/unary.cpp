#include <iostream>
using namespace std;
main()
{
    int x = 3;

    int a = -x; //unary minus
    int b = +x; // unary plus

    int y = x++;
    
    cout << x << endl;
    cout << y<< endl;

    cout << a << endl;
    cout << b << endl;
}

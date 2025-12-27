#include <iostream>
#include <conio.h>
using namespace std;
main()
{
    int n;
    float n2;
    double n3;
    char n1;
    char n4[6];

    cout << "Enter Int input: ";
    cin >> n;

    cout << "Enter float input: ";
    cin >> n2;
    // cin >> n2 >> n3 >> n1; mul input ek shthe
    cout << "Enter double input: ";
    cin >> n3;

    cout << "Enter char input: ";
    cin >> n1;

    cout << "Enter chars input: ";
    cin >> n4;

    cout << "\nOutputs: \n";
    cout << n << endl;
    cout << n1 << endl;
    cout << n2 << endl;
    cout << n3 << endl;
    cout << n4 << endl;

    return 0;
}
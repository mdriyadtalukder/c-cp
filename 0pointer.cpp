#include <iostream>
using namespace std;
void changeX(int *pt) // pass by reference using pointer
{
    *pt = 50;
}
// void changeX(int &b) //pass by reference using alias..same x er value 50 hbe..just variable er name chnage kora hyse...b te ja chnge hbe ta x er moddeo hbe.
// {
//     b = 50;
// }
int main()
{
    int a = 5;
    int *ptr = &a;     // pointer store a adress of value; like 0xfc9a9ff924..0x means a address..fc9a9ff924 is actual address which is hexadecimal(0-9 and a-f)
    int **ptr2 = &ptr; // ** pointer store a pointer
    int *p;            // a random memory address store ase
    int *pt = NULL;    // 0x0
    cout << ptr << endl;
    cout << ptr2 << endl;
    cout << *(&a) << endl; // dereference operation which give value from its adress..value at address
    cout << *(ptr) << endl;
    cout << **(ptr2) << endl;

    // change value by pointer in a function
    int x = 10;
    changeX(&x);
    cout << x;

    int ar[] = {1, 2, 3, 4};
    cout << ar << endl;        // address dibe
    cout << *(ar) << endl;     // 1st element dibe
    cout << *(ar + 1) << endl; // 2nd element dibe..+4 ke point krbe as int
    cout << *(ar + 2) << endl; // 3rd element dibe.+8 ke point krbe as int
}
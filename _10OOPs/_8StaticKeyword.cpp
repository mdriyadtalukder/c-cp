#include <iostream>
#include <string>
using namespace std;
void fun()
{
    static int x = 0; // joto bar e funtion call hok eita just ekbar e initialize hbe..

    cout << "x:" << x << endl;
    x++;
}
int main()
{
    fun();
    fun();
    fun();
    return 0;
}

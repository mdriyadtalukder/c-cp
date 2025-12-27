#include <iostream>
using namespace std;
main()
{
    for (int i = 1; i <= 20; i++)
    {
        if (i == 15)
        {
            break;
        }
        if (i == 11)
        {
            continue;
        }
        cout << i << endl;
    }
}
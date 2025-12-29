#include <iostream>
using namespace std;
main()
{
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i <= 4; i++)
    {
        cout << arr[i] << endl;
    }

   int length = sizeof(arr) / sizeof(arr[0]);

    cout<<length;
}
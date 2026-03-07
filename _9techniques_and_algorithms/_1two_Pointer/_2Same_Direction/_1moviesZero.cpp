#include <iostream>
using namespace std;

int main()
{
    int ar[] = {9, 0, 8, 0, 0, 7, 6, 0, 5, 0, 0};
    int n = sizeof(ar) / sizeof(ar[0]);

    int slow = 0;

    for (int fast = 0; fast < n; fast++)
    {
        if (ar[fast] != 0)
        {
            int temp = ar[slow];
            ar[slow] = ar[fast];
            ar[fast] = temp;
            slow++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }

    return 0;
}
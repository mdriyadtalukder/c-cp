#include <iostream>
using namespace std;

int main()
{
    int ar[] = {1, 2, 3, 2, 1};
    int n = sizeof(ar) / sizeof(ar[0]);

    int i = 0, j = n - 1;
    bool isPalindrome = true;

    while (i < j)
    {
        if (ar[i] != ar[j])
        {
            isPalindrome = false;
            break;
        }
        i++;
        j--;
    }

    cout << (isPalindrome ? "true" : "false") << endl;

    return 0;
}
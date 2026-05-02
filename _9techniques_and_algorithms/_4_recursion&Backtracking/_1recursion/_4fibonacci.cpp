#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2); //TC=(2^n) ..like tree ..sp=O(n)
}
int main()
{

    int n = 8;
    for (int i = 0; i < n; i++)
        cout << fib(i) << " ";

    // cout << "0 1 ";
    // int a = 0, b = 1, f;
    // for (int i = 3; i <= 8; i++)
    // {
    //     f = a + b;
    //     a = b;
    //     b = f;
    //     cout << f << " ";
    // }
}


/*
Time Complexity Explanation (Recursive Fibonacci)

fib(n)
├── fib(n-1)
│   ├── fib(n-2)
│   │   ├── fib(n-3)
│   │   └── fib(n-4)
│   └── fib(n-3)
│       ├── fib(n-4)
│       └── fib(n-5)
└── fib(n-2)
    ├── fib(n-3)
    │   ├── fib(n-4)
    │   └── fib(n-5)
    └── fib(n-4)

At each level:
- Every call makes 2 more calls (except base cases)
- Height of tree ≈ n

Total nodes ≈ 2^n

Time Complexity: O(2^n)
Space Complexity: O(n)  // recursion stack
*/
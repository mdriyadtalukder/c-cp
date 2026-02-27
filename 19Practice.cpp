#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        if (n == 2)
        {
            int temp = v[0];
            v[0] = v[1];
            v[1] = temp;
        }
        if (n > 2 && n % 2 == 0)
        {
            int index = -1;
            for (int i = 0; i < n; i++)
            {
                if (v[i] == n)
                {
                    index = i;
                    break;
                }
            }
            v[index] = v[n / 2 - 1];
            v[n / 2 - 1] = v.size();
        }
        for (int el : v)
        {
            cout << el << " ";
        }
        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    pair<int, int> p;
    int x = 0, m = 0, k, inp;
    cin >> inp;
    while (inp--)
    {
        int l = p.first, r = p.second;
        cin >> l >> r >> k;

        for (int i = l; i <= r; i++)
        {

            int temp1 = i;

            while (temp1 > k - 1)
            {

                if (temp1 > 9)
                {
                    int r, temp = temp1;
                    while (temp != 0)
                    {
                        r = temp % 10;
                        v.push_back(r);
                        temp = temp / 10;
                    }
                    reverse(v.begin(), v.end());

                    if (v.size() >= 2)
                    {
                        for (int i = 0; i < v.size(); i++)
                        {
                            if (v[i] == 0)
                            {
                                v[i] = 1;
                            }
                        }
                        int s = 1;
                        for (int i = 0; i < v.size(); i++)
                        {
                            s *= v[i];
                        }

                        if (s == k)
                        {
                            x++;
                        }
                        temp1 = s;
                    }
                    m = 1;
                }

                else
                {

                    if (temp1 == k && m == 0)
                    {
                        x++;
                    }
                    temp1 = 0;
                    m = 0;
                }
                v.clear();
            }
        }
        cout << x << '\n';
        x = 0;
        m = 0;
    }
}
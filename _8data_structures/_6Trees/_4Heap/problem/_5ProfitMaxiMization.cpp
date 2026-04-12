// sob cheye besi daam er ticket bechbo..like 1st row te 5 ta ticket so er price 5..
// 1st eita bechbo then one minus hoye 4 hbe so er price 4 hbe..so eita push krbo..eivabe PQ te boro gula age thkbe.
// Total B bar bechbo
//Time: O(B log N)
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &A, int B)
{
    long long sum = 0;

    priority_queue<int> p; // max heap

    for (int i = 0; i < A.size(); i++)
    {
        p.push(A[i]);
    }

    while (B && !p.empty())
    {
        int top = p.top();
        p.pop();

        sum += top;

        if (top - 1 > 0)
        {
            p.push(top - 1);
        }

        B--;
    }

    return sum;
}

int main()
{
    vector<int> A = {5, 3, 2};
    int B = 4;

    cout << maxProfit(A, B) << endl;

    return 0;
}
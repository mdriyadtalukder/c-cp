// max weight er 2 ta stone 2tai bari khaoabo then borota-chotota ja result hbe oita abr push krbo.
//.last e j single elem thkbe oita result..

#include <bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> p;

    for (int i = 0; i < stones.size(); i++)
        p.push(stones[i]);

    while (p.size() > 1)
    {
        int y = p.top(); // largest
        p.pop();

        int x = p.top(); // second largest
        p.pop();

        int weight = y - x;

        if (weight)
            p.push(weight);
    }

    return p.empty() ? 0 : p.top(); // last weight 0 hole and oita p te push krle p empty e dekhabe as value is 0..so it is.
}

int main()
{
    vector<int> stones = {2, 7, 4, 1, 8, 1};

    cout << lastStoneWeight(stones) << endl;

    return 0;
}
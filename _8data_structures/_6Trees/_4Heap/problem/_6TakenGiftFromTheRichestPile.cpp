// sob cheye besi number wala gift nibo and oitar root squre kre abr push krbo then oita pop krbo..eita krbo k obdi
// then last e ja thke tar sum ber kre return krbo;
// Tc=O(nlogn)
#include <bits/stdc++.h>
using namespace std;
long long pickGifts(vector<int> &gifts, int k)
{
    long long sum = 0;
    priority_queue<int> p;
    for (int i = 0; i < gifts.size(); i++)
    {
        p.push(gifts[i]);
    }
    while (k > 0)
    {
        int top = p.top();
        p.pop();
        p.push(sqrt(top));
        k--;
    }
    for (int i = 0; i < gifts.size(); i++)
    {
        sum += p.top();
        p.pop();
    }
    return sum;
}
int main() {}
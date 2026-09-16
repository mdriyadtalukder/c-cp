#include <bits/stdc++.h>
using namespace std;

int minimumBoxes(vector<int> &apple, vector<int> &capacity)
{
    int sum = 0;

    for (int a : apple)
        sum += a;

    // Sort in descending order
    sort(capacity.begin(), capacity.end(), greater<int>());

    int sum2 = 0;

    for (int i = 0; i < capacity.size(); i++)
    {
        sum2 += capacity[i];

        if (sum2 >= sum)
            return i + 1;
    }

    return capacity.size();
}

int main()
{
    vector<int> apple = {1, 3, 2};
    vector<int> capacity = {4, 3, 1, 5, 2};

    cout << minimumBoxes(apple, capacity) << endl;

    return 0;
}
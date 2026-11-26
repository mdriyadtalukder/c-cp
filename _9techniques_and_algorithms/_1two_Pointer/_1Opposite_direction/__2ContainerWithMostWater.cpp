#include <bits/stdc++.h>
using namespace std;
// brute force
int maxArea(vector<int> &height)
{
    int maxArea = 0, n = height.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            maxArea = max(maxArea, (j - i) * min(height[i], height[j]));
        }
    }
    return maxArea;
}
// optimal
int maxArea(vector<int> &height)
{
    int i = 0, j = height.size() - 1;
    int sum = 0;
    while (i < j)
    {
        if (height[i] < height[j])
        {
            if (sum < (j - i) * height[i])
            {
                sum = (j - i) * height[i];
            }
            i++;
        }
        else
        {
            if (sum < (j - i) * height[j])
            {
                sum = (j - i) * height[j];
            }
            j--;
        }
    }
    return sum;
}

int main()
{

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << maxArea(height) << endl;

    return 0;
}
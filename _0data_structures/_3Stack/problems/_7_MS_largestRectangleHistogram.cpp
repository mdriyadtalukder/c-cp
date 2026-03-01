// left and right smallest element khujte hbe then dekhte hbe koita bar hy majkhe for that height.
//next count from last and pre count from beginning
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int n = heights.size();
    vector<int> left(n, 0);  // left smaller nearest
    vector<int> right(n, 0); // right smaller nearest
    stack<int> s;
    // Right smaller(smilar next greater..so its next smaller) last elem 3 so its next 3->(-1)..so on..
    for (int i = n - 1; i >= 0; i--)
    {
        while (s.size() > 0 && heights[s.top()] >= heights[i])
        {
            s.pop();
        }
        right[i] = s.empty() ? n : s.top(); // for the area calculation right will be n..not -1.
        s.push(i);
    }

    // empty stack
    while (!s.empty())
    {
        s.pop();
    }

    // left smaller(previous smaller)
    for (int i = 0; i < n; i++)
    {
        while (s.size() > 0 && heights[s.top()] >= heights[i])
        {
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int width = right[i] - left[i] - 1;
        int currArea = heights[i] * width;
        ans = max(ans, currArea);
    }
    cout << ans;
}
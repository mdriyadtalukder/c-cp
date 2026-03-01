// ekta row er sob column 0 hote hbe...stack e 1,2,3 emn nibo utill length then...a[i][j]=1 hole i re bad dibo coz celebrity kaw k chine na. and a[i][j]=0 hole j k bad dibo coz i ta j k chine na but celebrity re soabi chine... and a[i][celebrity]=1 and a[celebrity][i]=0 hote hbe.
#include <bits/stdc++.h>
using namespace std;
int getCelebrity(vector<vector<int>> arr)
{
    stack<int> s;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
    while (s.size() > 1)
    {
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();
        if (arr[i][j] == 0)
        {
            s.push(i);
        }
        else
        {
            s.push(j);
        }
    }
    int celeb = s.top();
    for (int i = 0; i < n; i++)
    {
        if ((i != celeb) && (arr[i][celeb] == 0 || arr[celeb][i] == 1))
        {
            return -1;
        }
    }
    return celeb;
}
int main()
{
    vector<vector<int>> arr = {{0, 1, 0},
                               {0, 0, 0},
                               {0, 1, 0}};
    int ans = getCelebrity(arr);
    cout << "celebrity is:" << ans << endl;
    return 0;
}
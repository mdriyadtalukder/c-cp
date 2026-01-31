#include <bits/stdc++.h>
using namespace std;
// 1st sort then this method if vector is not sort..duplicate subset not allowed
void allSets(vector<int> &v, vector<int> &ans, int i, vector<vector<int>> &allsubs)
{
    // allsubs.push_back({ans}); [[1],[1,2],[1,2,3]....]
    if (i == v.size())
    {

        for (int i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    // inclution--tick
    ans.push_back(v[i]);
    allSets(v, ans, i + 1, allsubs);

    ans.pop_back(); // backtrack--uporer index e jai

    int idx = i + 1;
    while (idx < v.size() && v[idx] == v[idx - 1]) // current and previous value ek hoya jbe na..inclusive e ek value add krle eita exclusive e add kora jbe na.
    {
        idx++;
    }

    allSets(v, ans, idx, allsubs); // exclution--cross
    // return allsubs;
}
int main()
{
    vector<int> v = {1, 2, 2}, a;
    vector<vector<int>> allsub;
    sort(v.begin(), v.end());
    allSets(v, a, 0, allsub);
}
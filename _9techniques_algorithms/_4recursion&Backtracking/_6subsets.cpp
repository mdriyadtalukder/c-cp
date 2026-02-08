#include <bits/stdc++.h>
using namespace std;
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
        return; //backtrack
    }
    // inclution--tick
    ans.push_back(v[i]);
    allSets(v, ans, i + 1, allsubs);

    ans.pop_back(); // backtracking
    allSets(v, ans, i + 1, allsubs); //exclution--cross
    // return allsubs;
}
int main()
{
    vector<int> v = {1, 2, 3}, a;
    vector<vector<int>> allsub;
    allSets(v, a, 0, allsub);
}
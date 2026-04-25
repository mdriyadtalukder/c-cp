// abcd eita human dictionary order but alien dictionary alada like bdac order follow kre..
// onk words deoya thkbe order wise tar alien order ber krte hbe by kahns algo.
// adjaceny list banabo 1st then kahns algo apply krbo.
#include <bits/stdc++.h>
using namespace std;

string findOrder(vector<string> &dict)
{
    // K and N not given
    int N = dict.size();

    // mark used characters → this defines effective K
    vector<bool> used(26, false);
    int K = 0;

    for (int i = 0; i < N; i++)
    {
        for (char c : dict[i])
        {
            if (!used[c - 'a'])
            {
                used[c - 'a'] = true;
                K++; // count unique chars
            }
        }
    }

    // Adjacency list create karo
    vector<int> adj[26];
    vector<int> InDeg(26, 0);

    for (int i = 0; i < N - 1; i++)
    {
        string str1 = dict[i], str2 = dict[i + 1];
        int j = 0, k = 0;

        while (j < str1.size() && k < str2.size() && str1[j] == str2[k])
        {
            j++;
            k++;
        }

        if (j == str1.size())
            continue;

        if (k == str2.size())
            return ""; // invalid case

        adj[str1[j] - 'a'].push_back(str2[k] - 'a');
        InDeg[str2[k] - 'a']++;
    }

    // Kahn's algorithm
    queue<int> q;

    for (int i = 0; i < 26; i++)
        if (InDeg[i] == 0 && used[i]) // only used chars
            q.push(i);

    string ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        ans += (char)('a' + node);

        for (int j = 0; j < adj[node].size(); j++)
        {
            InDeg[adj[node][j]]--;
            if (InDeg[adj[node][j]] == 0)
                q.push(adj[node][j]);
        }
    }

    return ans.size() == K ? ans : "";
}

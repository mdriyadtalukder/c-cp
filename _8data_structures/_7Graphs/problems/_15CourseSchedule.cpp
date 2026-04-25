// 14 no er motoi just order print krte hbe..
#include <bits/stdc++.h>
using namespace std;
vector<int> findOrder(int N, vector<vector<int>> &prerequisites)
{

    // Adjacency list create karo
    vector<int> adj[N];
    vector<int> InDeg(N, 0);

    int P = prerequisites.size(); // ❗ missing

    for (int i = 0; i < P; i++)
    {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        InDeg[prerequisites[i][0]]++; // ❗ bracket fix
    }

    // Kahn's algorithm
    queue<int> q;

    for (int i = 0; i < N; i++)
        if (!InDeg[i])
            q.push(i);

    vector<int> ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node); // ❗ typo fix

        // Look at the neighbour
        for (int j = 0; j < adj[node].size(); j++)
        {
            InDeg[adj[node][j]]--;
            if (!InDeg[adj[node][j]])
                q.push(adj[node][j]);
        }
    }

    vector<int> temp;

    return ans.size() == N ? ans : temp; // ❗ condition fix
}
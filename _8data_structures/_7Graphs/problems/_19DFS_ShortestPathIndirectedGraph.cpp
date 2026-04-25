// 0 to 8 er shortest path dao..like 0->1->4->8.ans=0148
// visisted array and parent array..parent array te parent node er value store hbe.like 6..6 er parent 5 ..so 6 index e 5 store krbo
// ans hbe..0-8..so 8 er index e jao and value dekho and index ta result e dukao..then value er index e jao..so on until get -1 value
#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<pair<int, int>> edges, int N, int M, int src, int dest)
{

    vector<int> adj[N];

    for (int i = 0; i < M; i++)
    {
        adj[edges[i].first - 1].push_back(edges[i].second - 1);
        adj[edges[i].second - 1].push_back(edges[i].first - 1);
    }

    src--;
    dest--;

    vector<bool> visited(N, 0);
    vector<int> parent(N, -1);

    queue<int> q;
    q.push(src);
    visited[src] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int j = 0; j < adj[node].size(); j++)
        {
            int v = adj[node][j];

            if (visited[v])
                continue;

            visited[v] = 1;
            q.push(v);
            parent[v] = node;
        }
    }

    vector<int> path;

    if (!visited[dest])
        return {}; // important

    while (dest != -1)
    {
        path.push_back(dest + 1);
        dest = parent[dest];
    }

    reverse(path.begin(), path.end());

    return path;
}
#include <bits/stdc++.h>
using namespace std;
// used kahns algo-bfs topological sort
bool isCyclic(int V, vector<int> adj[])
{
    vector<int> InDeg(V, 0);

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
            InDeg[adj[i][j]]++;
    }

    queue<int> q;

    for (int i = 0; i < V; i++)
        if (InDeg[i] == 0)
            q.push(i);

    int count = 0; // j node cycle er baire just oigula count hy..jar indegree 0 hoy..cycle node gular indegree 0 hy na

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

        for (int j = 0; j < adj[node].size(); j++)
        {
            InDeg[adj[node][j]]--;

            if (InDeg[adj[node][j]] == 0)
                q.push(adj[node][j]);
        }
    }

    return count != V;
}
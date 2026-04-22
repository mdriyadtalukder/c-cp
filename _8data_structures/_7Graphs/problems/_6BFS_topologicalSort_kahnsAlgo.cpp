// topological sort using BFS..Kahn's algorithm
// jader parent(incoming/indegree edge) thkbe na tader print krbo r remove krbo.then tader child print krbo.so on..
#include <bits/stdc++.h>
using namespace std;
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<int> InDeg(V, 0);

    // store the indegree
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            InDeg[adj[i][j]]++;
        }
    }

    // Push all nodes with zero indegree into queue
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (InDeg[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        // decrease indegree of neighbours
        for (int j = 0; j < adj[node].size(); j++)
        {
            InDeg[adj[node][j]]--;

            if (InDeg[adj[node][j]] == 0)
            {
                q.push(adj[node][j]);
            }
        }
    }

    return ans;
}
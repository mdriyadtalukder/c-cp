// directed acyclic graph hote hbe..
//  eitar node linear vabe sort hbe as jar dike age jai seta pore hbe..like 0->1 so 01..4
// TC = O(V + E),SC = O(V)
#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool> &visited, stack<int> &s)
{
    visited[node] = 1;

    // look at its neighbour one by one
    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]])
        {
            DFS(adj[node][j], adj, visited, s);
        }
    }

    s.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<bool> visited(V, 0);
    stack<int> s;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFS(i, adj, visited, s);
        }
    }

    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}
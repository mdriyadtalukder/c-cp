// ekti graph er subgraph er sob node ektar shthe r ekta connected like..1st node theke 2nd tai jete parbo and 2nd theke 1st tai jete parbo by any path...emn vabe sob node connected in a subgraph..eita k strongly connected component(subgraph ta) bole
// jdi just ekta node thke..seita kono sungraph er shthe na..tahole oi ekta node o ekta component hishebe count hbe.
// emn koita component ase ta count krte hbe.
//Time Complexity: O(V + E)
//Space Complexity: O(V + E)
#include <bits/stdc++.h>
using namespace std;
void Topological(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s)
{
    visited[node] = 1;

    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]])
            Topological(adj[node][j], adj, visited, s);
    }

    s.push(node);
}

void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = 1;

    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]])
            DFS(adj[node][j], adj, visited);
    }
}

int kosaraju(int V, vector<vector<int>> &edges)
{

    // 🔥 Convert edges → adjacency list
    vector<vector<int>> adj(V);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v); // directed graph
    }

    stack<int> s;
    vector<bool> visited(V, 0);

    // 1. Topological sort
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            Topological(i, adj, visited, s);
    }

    // 2. Reverse graph
    vector<vector<int>> adj2(V);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            int u = i;
            int v = adj[i][j];
            adj2[v].push_back(u);
        }
    }

    // 3. DFS on reversed graph
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    int SCC = 0;

    while (!s.empty())
    {
        int node = s.top();
        s.pop();

        if (!visited[node])
        {
            SCC++;
            DFS(node, adj2, visited);
        }
    }

    return SCC;
}

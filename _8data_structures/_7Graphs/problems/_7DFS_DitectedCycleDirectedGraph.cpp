// node er neighbor jdi visited thke but seita node tir parent na hy tahole it is a cycle.
#include <bits/stdc++.h>
using namespace std;
bool DetectCycle(int node, vector<int> adj[], vector<bool> &visited, vector<bool> &path)
{
    visited[node] = 1;
    path[node] = 1;

    // look at adjacent nodes
    for (int j = 0; j < adj[node].size(); j++)
    {
        // if neighbour is already in current path → cycle present
        if (path[adj[node][j]])
            return 1;

        if (!visited[adj[node][j]] && DetectCycle(adj[node][j], adj, visited, path))
            return 1;
    }

    path[node] = 0;
    return 0;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> path(V, 0);
    vector<bool> visited(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && DetectCycle(i, adj, visited, path))
            return 1;
    }

    return 0;
}
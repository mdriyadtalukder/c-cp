#include <bits/stdc++.h>
using namespace std;
bool checkBip(int node, vector<int> adj[], vector<int> &color)
{

    // look at each neighbour
    for (int j = 0; j < adj[node].size(); j++)
    {

        // color is not assigned
        if (color[adj[node][j]] == -1)
        {
            color[adj[node][j]] = (color[node] + 1) % 2;

            if (!checkBip(adj[node][j], adj, color))
                return 0;
        }
        // color is already assigned
        else
        {
            if (color[node] == color[adj[node][j]])
                return 0;
        }
    }
    return 1;
}

bool dfs(int V, vector<int> adj[])
{
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        { // not assigned
            color[i] = 0;

            if (!checkBip(i, adj, color)) // ⚠️ i, not 0
                return 0;
        }
    }
    return 1;
}
// bridge sei edge jake remove krle graph 2 part e vag hbe..baa sei edge ta cycle er part na..
// 2 ta array hbe disc and low...jdi cycle hy tahole parent and child er low er min ta parent k dibo.pichate thkbe and low update krte thkbo min ta diye jdi amra cycle er maddhome oi min e powchate pari.
// and jdi disc[parent]<low[child] hole bridge hbe
// Time: O(V + E)---Space: O(V + E)
#include <bits/stdc++.h>
using namespace std;

void DFS(int node, int parent, vector<vector<int>> &adj,
         vector<int> &disc, vector<int> &low,
         vector<bool> &visited,
         vector<vector<int>> &Bridges,
         int &count)
{
    disc[node] = low[node] = count;
    visited[node] = 1;

    for (int j = 0; j < adj[node].size(); j++)
    {
        int neib = adj[node][j];

        if (neib == parent)
            continue;

        else if (visited[neib])
        {
            // back edge
            low[node] = min(low[node], disc[neib]);
        }
        else
        {
            count++;
            DFS(neib, node, adj, disc, low, visited, Bridges, count);

            // update low
            low[node] = min(low[node], low[neib]);

            // bridge condition
            if (low[neib] > disc[node])
            {
                vector<int> temp;
                temp.push_back(node);
                temp.push_back(neib);
                Bridges.push_back(temp);
            }
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<vector<int>> adj(n);

    for (int i = 0; i < connections.size(); i++)
    {
        int u = connections[i][0];
        int v = connections[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> Bridges;
    vector<int> disc(n);
    vector<int> low(n);
    vector<bool> visited(n, 0);

    int count = 0;

    DFS(0, -1, adj, disc, low, visited, Bridges, count);

    return Bridges;
}
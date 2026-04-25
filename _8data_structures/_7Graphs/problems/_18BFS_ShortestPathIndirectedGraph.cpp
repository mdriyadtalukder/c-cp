// 0 theke shorte way te ekek ta node o jaoya..dorlam every egdes weight 1 as its unweighted..
// bfs vabe node traversal krbo..ekbar jeitai jbo seitai r jbo na..
/// ekta visited node nibo..visited hyle 1 baniye dibi..na hy 0 thkbe.
//.r ekta distances array with -1 values..oita +1 krbo ager distance+1;
#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int V, vector<vector<int>> &edges, int src)
{
    // code here
    // adjacency list create karna
    vector<int> adj[V];

    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    // array dist
    vector<int> dist(V, -1);
    vector<bool> visited(V, 0);

    queue<int> q;
    q.push(src);

    dist[src] = 0;
    visited[src] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        // Look at all the neighbours
        for (int j = 0; j < adj[node].size(); j++)
        {
            int v = adj[node][j];

            if (visited[v])
                continue;

            visited[v] = 1;
            q.push(v);
            dist[v] = dist[node] + 1;
        }
    }

    return dist;
}
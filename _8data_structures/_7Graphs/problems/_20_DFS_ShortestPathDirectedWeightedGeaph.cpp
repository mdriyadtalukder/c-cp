// dfs er topological sort use hbe
// stack e sob node dukabo jokhn backtracking er time hbe tokhn current ode dukabo.
// then oigular dist ber krbo and ans vector e rakhbo
// sob node er value infinite thkbe 1st e..then pre nodes weight er sum and je node e jabe tar value er min ber kre oi node er value dibo(jetai jabe)
// jdi visited hy and value boro hy tahole min value ta nibo
#include <bits/stdc++.h>
using namespace std;
void DFS(int node, vector<pair<int, int>> adj[], stack<int> &s, vector<bool> &visited)
{
    visited[node] = 1;

    // look at its all neighbours
    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j].first])
            DFS(adj[node][j].first, adj, s, visited);
    }

    s.push(node);
}
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    // adjacency list create
    vector<pair<int, int>> adj[N];

    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        adj[u].push_back({v, weight});
    }

    // Topological sort (DFS)
    stack<int> s1;
    vector<bool> visited(N, 0);

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
            DFS(i, adj, s1, visited);
    }

    vector<int> dist(N, INT_MAX);
    dist[0] = 0;

    // process stack
    while (!s1.empty())
    {
        int node = s1.top();
        s1.pop();

        if (dist[node] != INT_MAX)
        {
            for (int j = 0; j < adj[node].size(); j++)
            {
                int neighbour = adj[node][j].first;
                int weight = adj[node][j].second;

                dist[neighbour] = min(dist[neighbour], dist[node] + weight);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (dist[i] == INT_MAX)
            dist[i] = -1;
    }

    return dist;
}
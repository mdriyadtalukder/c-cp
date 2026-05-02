// euler bole sob edge re exact ekbr kre traversal krte hbe but Hamiltonian  bole sob node re exact ekbar kre traversal krte hbe.
// every node e jbo..onk edge thkle ekta node er tahole ekta ekta check krte thkbo j konta sothik poth..jdi node sesh hoye jai ekta path er tahole backtracking kre onno path e jbo for checking current path.
//  HC==HP but HP!=HC
// TC=O(N!)..SC=O(N);
#include <bits/stdc++.h>
using namespace std;

bool DFS(int node, vector<vector<int>> &adj, vector<bool> &visited, int &count, int N)
{
    visited[node] = 1;
    count++;

    if (count == N)
        return 1;

    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]] &&
            DFS(adj[node][j], adj, visited, count, N))
        {
            return 1;
        }
    }

    visited[node] = 0;
    count--;

    return 0;
}

bool check(int N, int M, vector<vector<int>> Edges)
{
    vector<vector<int>> adj(N);

    for (int i = 0; i < M; i++)
    {
        adj[Edges[i][0] - 1].push_back(Edges[i][1] - 1);
        adj[Edges[i][1] - 1].push_back(Edges[i][0] - 1);
    }

    vector<bool> visited(N, 0);

    for (int i = 0; i < N; i++)
    {
        int count = 0; // important reset

        if (DFS(i, adj, visited, count, N))
            return 1;
    }

    return 0;
}

// kon ta choto and explore hy nai oita find na kre minheap use krbo
// TC=O(elogv);sc=(e+v)--its better for sparse graph --for single source
// multisource  TC=O(velogv)
// j graph e edge besi(dense) oitai eita use krle TC hote pare=(v^3logv) for multipleSorce..SO DO NOT USE
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{

    // Step 1: create adjacency list
    vector<vector<vector<int>>> adj(V);

    for (auto &e : edges)
    {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove if directed
    }

    // Step 2: Dijkstra (your way with min-heap + Explored)
    vector<bool> Explored(V, 0);
    vector<int> dist(V, INT_MAX);

    // min-heap (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;

    dist[src] = 0;
    p.push({0, src});

    while (!p.empty())
    {
        int node = p.top().second;
        p.pop();

        if (Explored[node] == 1)
            continue;

        Explored[node] = 1;

        // Relax the edges
        for (int j = 0; j < adj[node].size(); j++)
        {
            int neighbour = adj[node][j][0];
            int weight = adj[node][j][1];

            if (!Explored[neighbour] && (dist[node] + weight < dist[neighbour]))
            {
                dist[neighbour] = dist[node] + weight;
                p.push({dist[neighbour], neighbour});
            }
        }
    }

    return dist;
}

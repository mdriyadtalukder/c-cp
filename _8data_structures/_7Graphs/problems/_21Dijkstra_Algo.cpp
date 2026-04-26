// src ba 0 theke sob node er shortest path ber kra..undirected weighted graph
// initial sob node er value inifine thkbe..then src or 0 theke weight er maddome node er value count krbo
// j child er value/weight(value na thkle) choto oita age explore krbo.jdi value set kri node er and oi value ta boro hy any path to that node then oita value ta min value ta hbe.
// ekbar kono node er child explore krle oi parent node er edge er dike r jbo na..
// explore and dist er 2 ta array thkbe..dist er modde jeita sob cheye choto but exlpore hy nai oita pick krbo and explore krbo each time and dist er value update hbe if needed.
// node er vitorer value ta index no
// TC=O(n^2),SC=O(n)---its better for dense graph
#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{

    // Step 1: create adjacency list..deoya nai tai create kre nitesi
    vector<vector<vector<int>>> adj(V);

    for (auto &e : edges)
    {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove this if graph is directed
    }

    // Step 2: your Dijkstra logic
    vector<bool> Explored(V, 0);
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;

    int count = V;

    while (count--)
    {
        int node = -1, value = INT_MAX;

        // select min distance node
        for (int i = 0; i < V; i++)
        {
            if (!Explored[i] && dist[i] < value)
            {
                node = i;
                value = dist[i];
            }
        }

        
        Explored[node] = 1;

        // Relax edges
        for (int j = 0; j < adj[node].size(); j++)
        {
            int neighbour = adj[node][j][0];
            int weight = adj[node][j][1];

            if (!Explored[neighbour] && dist[node] + weight < dist[neighbour])
            {
                dist[neighbour] = dist[node] + weight;
            }
        }
    }

    return dist;
}
// Articulation Point emn ekta point jake disconnect krle graph eker besi component e vag hbe..ekta node k remove krbo with its all edges.
#include <bits/stdc++.h>
using namespace std;
// O(V + E)..SC=O(V)
void DFS(int node, int parent, vector<int> adj[],
         vector<bool> &visited,
         vector<int> &disc,
         vector<int> &low,
         vector<bool> &artpoint,
         int &timer)
{
    visited[node] = 1;
    disc[node] = low[node] = timer;

    int child = 0;

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
            child++;
            timer++;

            DFS(neib, node, adj, visited, disc, low, artpoint, timer);

            // update low
            low[node] = min(low[node], low[neib]);

            // articulation condition
            if (disc[node] <= low[neib] && parent != -1)
            {
                artpoint[node] = 1;
            }
        }
    }

    // root node case
    if (child > 1 && parent == -1)
    {
        artpoint[node] = 1;
    }
}

vector<int> articulationPoints(int V, vector<int> adj[])
{
    vector<bool> artpoint(V, 0);
    vector<int> disc(V);
    vector<int> low(V);
    vector<bool> visited(V, 0);

    int timer = 0;

    DFS(0, -1, adj, visited, disc, low, artpoint, timer);

    vector<int> ans;

    for (int i = 0; i < V; i++)
    {
        if (artpoint[i])
            ans.push_back(i);
    }

    if (ans.size() == 0)
        ans.push_back(-1);

    return ans;
}

/*
Problem: Articulation Point (Cut Vertex)

Given an undirected connected graph with V vertices and adjacency list adj[].

An Articulation Point (Cut Vertex) is a vertex that, if removed
(along with all its connected edges), increases the number of
connected components in the graph.

Return all articulation points in sorted order.
If no articulation point exists, return {-1}.

Example:

Input:
V = 5
Edges:
0-1
1-2
2-0
1-3
3-4

Output:
1 3

Explanation:
Removing vertex 1 disconnects {3,4} from the rest of the graph.
Removing vertex 3 disconnects vertex 4.
Hence both 1 and 3 are articulation points.
*/
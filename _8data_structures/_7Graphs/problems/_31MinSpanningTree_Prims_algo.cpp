/* graph connected hote hbe ei problm solve er jnnp..then disconnected hbe as solve like
A --- B
|
C --- D
spanning tree is a subset of graph.
..It is a subset of Edges of the graph that form a tree, where every node of the graph is a part of tree.it includes
#No cycle
#Minimum edges (4 nodes → 3 edges)--n-node, h-1 edges
#all nodes are connected

1 ti graph dorbo then oita dara possible spanning tree create krbo..weight deoya thkbe..so min weight er spanning tree konta hbe seita ber krbo.

/* prim's algo
Top Graph (Original):

    0 ------4------ 1          4 ------5------ 7
    |               |          |               |
    |               |          |               |
    3               1          7               3
    |               |          |               |
    |               |          |               |
    2 ------2------ 3 ----5---- 5 ------2------ 6

                6
ans:
    0-1 and 4-5 edges will be removed..cicle remove krte hbe..and min value e spanning tree banate hbe..j kono node theke suru krte pari

*/
//Sparse graph → Kruskal---Dense graph → Prim
//its better for dense graph
// Time: O(E log V)--Space: O(V + E)
#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> &edges)
{
    // code here
    // step 1: build adjacency list
    vector<vector<pair<int, int>>> adj(V);

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // step 2: Prim's algorithm (same as your previous code)
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;

    vector<bool> IsMST(V, 0);
    vector<int> parent(V);

    int cost = 0;

    pq.push({0, {0, -1}});

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;
        pq.pop();

        if (IsMST[node])
            continue;

        IsMST[node] = 1;
        cost += wt;
        parent[node] = par;

        for (int j = 0; j < adj[node].size(); j++)
        {
            if (!IsMST[adj[node][j].first])
            {
                pq.push({adj[node][j].second, {adj[node][j].first, node}});
            }
        }
    }

    return cost;
}
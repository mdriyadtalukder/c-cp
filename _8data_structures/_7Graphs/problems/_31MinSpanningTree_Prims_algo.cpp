/* graph connected hote hbe ei problm solve er jnop..then disconnected hbe as solve like
A --- B
|
C --- D
spanning tree is a subset of graph.
..It is a subset of Edges of the graph that form a tree, where every node of the graph is a part of tree.it includes
#No cycle
#Minimum edges (4 nodes → 3 edges)--n-node, n-1 edges
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

    vector<bool> IsMST(V, 0); //isMinSpanningTree
    vector<int> parent(V);

    int cost = 0;

    pq.push({0, {0, -1}});

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second; //parenet
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

/*
Minimum Spanning Tree (Prim's Algorithm)

Problem Statement:

Given a connected, undirected,
weighted graph with V vertices
and E edges,

find the total weight of its
Minimum Spanning Tree (MST).

A Minimum Spanning Tree is a subset
of edges that:

1. Connects all vertices.
2. Contains exactly (V - 1) edges.
3. Does not contain any cycle.
4. Has the minimum possible total weight.

Return the total weight of the MST.

------------------------------------------------

Example 1:

Input:

V = 3

Edges =

{
    {0,1,5},
    {1,2,3},
    {0,2,1}
}

Output:

4

Explanation:

Choose edges:

0 - 2 (1)

2 - 1 (3)

Total Weight = 1 + 3 = 4

------------------------------------------------

Example 2:

Input:

V = 4

Edges =

{
    {0,1,10},
    {0,2,6},
    {0,3,5},
    {1,3,15},
    {2,3,4}
}

Output:

19

Explanation:

Choose edges:

2 - 3 (4)

0 - 3 (5)

0 - 1 (10)

Total Weight = 19

------------------------------------------------

Constraints:

1 <= V <= 10^5

1 <= E <= 2 × 10^5

0 <= Weight <= 10^6

The graph is connected.

------------------------------------------------

Expected Time Complexity:

O((V + E) log V)

Expected Auxiliary Space:

O(V + E)

------------------------------------------------

Approach:

1. Build the adjacency list.
2. Start Prim's Algorithm from any vertex
   (vertex 0).
3. Use a Min Heap to always select
   the minimum-weight edge.
4. Ignore vertices already included
   in the MST.
5. Add the selected edge's weight
   to the answer.
6. Push all adjacent edges of the
   current vertex into the Min Heap.
7. Continue until all vertices
   are included in the MST.
8. Return the total weight.
*/
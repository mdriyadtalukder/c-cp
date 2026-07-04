// dijkstra algo negative weight er jnno fail kre
// so bellman ford negative er jnno kaj kre..directed weighted graph...undirected graph er upor eita use krbona.undirected graph e negative weight thkle oitar shortest path ber kra jbe na..ans possibe na..
// negative circle er shortest path ber kra impossible..negative circle means all weight er sum negative songkha hbe
// step-1: initially sob node er dist value infinite thkbe..just 0 er 0 hbe..  0---3(weight)--->2...dis[u]+w<dist[v]--dist[0]+3<dist[2]..condition mille update hbe..mane 2 no index dist[0]+3 value ta hbe..v-1 bar ei loop cholbe and value updtae hbe--edges relax koranor formolla
// step-2:  v-1.after that r ekbar loop chalabo mane edges relax korabo jdi eibr value update hy tahole eita negative circle ase..so shortest path ber kra jbe na..otherwise we got shortest path
// better for sparse
// time complexity:--for sparse
// Worst case: V*E
// Best case: E
// Space:V
// for dense--
// TC=V^2E
// TC=O(V4)--with multilpe sourse
#include <bits/stdc++.h>
using namespace std;
vector<int> bellmanFord(int V, vector<vector<int>> &edges, int S)
{
    // Code here
    vector<int> dist(V, 1e8); // infinite

    // 1e8 = 10^8
    dist[S] = 0;

    int e = edges.size();

    for (int i = 0; i < V - 1; i++)
    {
        // Relax all the edges
        int flag = 0;
        for (int j = 0; j < e; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] == 1e8)
                continue;

            if (dist[u] + wt < dist[v]) // this means relax edge

            {
                flag = 1;
                dist[v] = dist[u] + wt;
            }
        }
        if (!flag) //jdi kono edge relax na hy
            return dist;
    }

    // To detect the cycle(relax edge one more time)
    for (int j = 0; j < e; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] == 1e8)
            continue;

        if (dist[u] + wt < dist[v]) //if it is then cycle present
        {
            // cycle detected
            vector<int> ans;
            ans.push_back(-1);
            return ans;
        }
    }

    return dist;
}

/*
LeetCode / GFG Style Problem

Bellman-Ford Algorithm

Problem Statement:
You are given a directed weighted graph with V vertices numbered from 0 to V-1.
The graph may contain negative edge weights but does not contain any
negative weight cycle reachable from the source.

Your task is to find the shortest distance from the source vertex S to
every other vertex using the Bellman-Ford algorithm.

If a negative weight cycle is reachable from the source, return {-1}
since the shortest path is not well-defined.

Input:
- V: Number of vertices.
- edges: A list where each edge is represented as
         {u, v, wt}, meaning there is a directed edge
         from u to v with weight wt.
- S: Source vertex.

Here, S = 0 means:

Find the shortest distance from 0 → 0
Find the shortest distance from 0 → 1
Find the shortest distance from 0 → 2
Find the shortest distance from 0 → 3
Find the shortest distance from 0 → 4

Output:
- Return a vector<int> of size V where dist[i] is the
  shortest distance from S to vertex i.
- If a vertex is unreachable, its distance remains INF (1e8).
- If a negative weight cycle exists, return {-1}.

Example 1:
Input:
V = 5
edges = {
    {0,1,-1},
    {0,2,4},
    {1,2,3},
    {1,3,2},
    {1,4,2},
    {3,2,5},
    {3,1,1},
    {4,3,-3}
}
S = 0

Output:
{0, -1, 2, -2, 1}

Explanation:
The Bellman-Ford algorithm relaxes every edge (V-1) times,
producing the shortest distance from the source to every vertex.

Example 2:
Input:
V = 3
edges = {
    {0,1,1},
    {1,2,-1},
    {2,1,-1}
}
S = 0

Output:
{-1}

Explanation:
Vertices 1 and 2 form a negative weight cycle.
Since the cycle is reachable from the source,
the shortest path is undefined.

Constraints:
1 <= V <= 500
1 <= E <= 5000
-10^4 <= wt <= 10^4

Expected Time Complexity:
O(V * E)

Expected Auxiliary Space:
O(V)
*/
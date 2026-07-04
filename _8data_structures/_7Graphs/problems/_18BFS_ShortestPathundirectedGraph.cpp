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

            if (visited[adj[node][j]])
                continue;

            visited[adj[node][j]] = 1;
            q.push(adj[node][j]);
            dist[adj[node][j]] = dist[node] + 1;
        }
    }

    return dist;
}

/*
LeetCode / GFG Style Problem

Shortest Path in an Undirected Unweighted Graph

Problem Statement:
You are given an undirected unweighted graph with V vertices numbered
from 0 to V-1 and a list of edges.

Your task is to find the shortest distance from a given source vertex
(src) to every other vertex.

Since the graph is unweighted, every edge has a weight of 1.

If a vertex cannot be reached from the source, its distance should remain -1.

Input:
- V: Number of vertices.
- edges: A list where each edge is represented as
         {u, v}, indicating an undirected edge
         between u and v.
- src: Source vertex.

Output:
- Return a vector<int> of size V where dist[i] is the
  minimum number of edges required to reach vertex i
  from the source.
- If a vertex is unreachable, return -1 for that vertex.

Example 1:
Input:
V = 6
edges = {
    {0,1},
    {0,2},
    {1,3},
    {2,4},
    {4,5}
}
src = 0

Output:
{0, 1, 1, 2, 2, 3}

Explanation:
The shortest path from vertex 0 is:
0 -> 0 = 0
0 -> 1 = 1
0 -> 2 = 1
0 -> 3 = 2
0 -> 4 = 2
0 -> 5 = 3

Example 2:
Input:
V = 5
edges = {
    {0,1},
    {1,2}
}
src = 0

Output:
{0, 1, 2, -1, -1}

Explanation:
Vertices 3 and 4 are not reachable from the source.

Constraints:
1 <= V <= 10^5
0 <= E <= 2 × 10^5
0 <= src < V

Expected Time Complexity:
O(V + E)

Expected Auxiliary Space:
O(V)
*/
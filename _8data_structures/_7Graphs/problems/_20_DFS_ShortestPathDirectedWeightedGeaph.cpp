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

/*
LeetCode / GFG Style Problem

Shortest Path in a Directed Acyclic Graph (DAG)

Problem Statement:
You are given a Directed Acyclic Graph (DAG) with N vertices numbered
from 0 to N-1 and M weighted directed edges.

Your task is to find the shortest distance from the source vertex 0
to every other vertex.

If a vertex is not reachable from the source, its distance should be -1.

Note:
The graph is guaranteed to be a DAG (contains no cycles).

Input:
- N: Number of vertices.
- M: Number of edges.
- edges: A list where each edge is represented as
         {u, v, wt}, meaning there is a directed edge
         from u to v with weight wt.

Output:
- Return a vector<int> of size N where dist[i] is the
  shortest distance from source vertex 0 to vertex i.
- If a vertex is unreachable, return -1 for that vertex.

Example 1:
Input:
N = 6
M = 7
edges = {
    {0,1,2},
    {0,4,1},
    {4,5,4},
    {4,2,2},
    {1,2,3},
    {2,3,6},
    {5,3,1}
}

Output:
{0, 2, 3, 6, 1, 5}

Explanation:
The shortest distances from source vertex 0 are:
0 -> 0 = 0
0 -> 1 = 2
0 -> 4 = 1
0 -> 2 = 3   (0 -> 4 -> 2)
0 -> 5 = 5   (0 -> 4 -> 5)
0 -> 3 = 6   (0 -> 4 -> 5 -> 3)

Example 2:
Input:
N = 5
M = 3
edges = {
    {0,1,2},
    {1,2,4},
    {3,4,1}
}

Output:
{0, 2, 6, -1, -1}

Explanation:
Vertices 3 and 4 are not reachable from source 0.

Constraints:
1 <= N <= 10^5
0 <= M <= 2 × 10^5
-10^4 <= wt <= 10^4

Expected Time Complexity:
O(N + M)

Expected Auxiliary Space:
O(N)

Approach:
1. Build the adjacency list of the DAG.
2. Perform a DFS-based Topological Sort and store the
   vertices in a stack.
3. Initialize all distances as INF except dist[0] = 0.
4. Process vertices in topological order.
5. Relax all outgoing edges of the current vertex.
6. Replace remaining INF values with -1.
*/
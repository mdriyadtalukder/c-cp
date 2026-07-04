// 0 to 8 er shortest path dao..like 0->1->4->8.ans=0148
// visisted array and parent array..parent array te parent node er value store hbe.like 6..6 er parent 5 ..so 6 index e 5 store krbo
// ans hbe..0-8..so 8 er index e jao and value dekho and index ta result e dukao..then value er index e jao..so on until get -1 value
#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<pair<int, int>> edges, int N, int M, int src, int dest)
{

    vector<int> adj[N];

    for (int i = 0; i < M; i++)
    {
        adj[edges[i].first - 1].push_back(edges[i].second - 1);
        adj[edges[i].second - 1].push_back(edges[i].first - 1);
    }

    src--;
    dest--;

    vector<bool> visited(N, 0);
    vector<int> parent(N, -1);

    queue<int> q;
    q.push(src);
    visited[src] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int j = 0; j < adj[node].size(); j++)
        {
            int v = adj[node][j];

            if (visited[v])
                continue;

            visited[v] = 1;
            q.push(v);
            parent[v] = node;
        }
    }

    vector<int> path;

    if (!visited[dest])
        return {}; // important

    while (dest != -1)
    {
        path.push_back(dest + 1);
        dest = parent[dest];
    }

    reverse(path.begin(), path.end());

    return path;
}

/*
LeetCode / GFG Style Problem

Shortest Path Between Two Vertices in an Undirected Unweighted Graph

Problem Statement:
You are given an undirected unweighted graph with N vertices numbered
from 1 to N and M edges.

Your task is to find one of the shortest paths from the source vertex
(src) to the destination vertex (dest).

Since the graph is unweighted, every edge has a weight of 1.

If multiple shortest paths exist, return any one of them.
If no path exists, return an empty vector.

Input:
- N: Number of vertices.
- M: Number of edges.
- edges: A list of M pairs {u, v}, representing an
         undirected edge between u and v.
- src: Source vertex.
- dest: Destination vertex.

Output:
- Return a vector containing the vertices on one of the
  shortest paths from src to dest (inclusive).
- If dest is unreachable from src, return {}.

Example 1:
Input:
N = 8
M = 9
edges = {
    {1,2},
    {1,3},
    {2,4},
    {3,5},
    {4,6},
    {5,6},
    {6,7},
    {7,8},
    {5,8}
}
src = 1
dest = 8

Output:
{1, 3, 5, 8}

Explanation:
One of the shortest paths from vertex 1 to vertex 8 is:
1 -> 3 -> 5 -> 8

Example 2:
Input:
N = 5
M = 2
edges = {
    {1,2},
    {2,3}
}
src = 1
dest = 5

Output:
{}

Explanation:
There is no path from vertex 1 to vertex 5.

Constraints:
1 <= N <= 10^5
0 <= M <= 2 × 10^5
1 <= src, dest <= N

Expected Time Complexity:
O(N + M)

Expected Auxiliary Space:
O(N)

Approach:
1. Perform BFS starting from src.
2. Store the parent of every visited vertex.
3. If dest is unreachable, return {}.
4. Otherwise, start from dest and repeatedly move to its parent
   until reaching -1, storing each vertex.
5. Reverse the collected vertices to obtain the path from
   src to dest.
*/
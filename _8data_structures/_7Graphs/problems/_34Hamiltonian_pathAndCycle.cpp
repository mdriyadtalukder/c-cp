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

    visited[node] = 0; //count==n na hole..sob node visited na hole
    count--; //count==n na hole..sob node visited na hole

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
/*
-------------------------------------------------------
Explanation

Hamiltonian Path (HP)

A path that visits every vertex
exactly once.

Every node must be visited exactly once.

Edges may or may not all be visited.

-------------------------------------------------------

Hamiltonian Cycle (HC)

A Hamiltonian Path
whose starting and ending vertex
are the same.

-------------------------------------------------------

Example

1 ---- 2
|      |
|      |
4 ---- 3

Hamiltonian Path

1 → 2 → 3 → 4

Hamiltonian Cycle

1 → 2 → 3 → 4 → 1

-------------------------------------------------------

Difference Between Euler and Hamiltonian

Euler

Visit every EDGE exactly once.

Nodes may be visited many times.

-------------------------------------------------------

Hamiltonian

Visit every NODE exactly once.

Edges may remain unused.

-------------------------------------------------------

Idea

Start DFS from every node.

For every neighbour,

Two choices

Go there

or

Try another neighbour.

If a path cannot visit all vertices,

Backtrack and try another path.

-------------------------------------------------------

Backtracking

Suppose

1

/ \

2  3

We first try

1 → 2

If it fails,

Undo

visited[2]=false

Then try

1 → 3

-------------------------------------------------------

Stopping Condition

If

count == N

All vertices are visited.

Return true.

-------------------------------------------------------

Why start DFS from every node?

Hamiltonian Path
can start from any vertex.

So we try every possible starting node.

-------------------------------------------------------

Time Complexity

Worst Case

O(N!)

because every permutation of vertices
may need to be explored.

-------------------------------------------------------

Space Complexity

Visited Array

O(N)

Recursion Stack

O(N)

Overall

O(N)

-------------------------------------------------------

Remember

Euler Path
→ Visit every EDGE exactly once.

Hamiltonian Path
→ Visit every NODE exactly once.

Hamiltonian Cycle = Hamiltonian Path + Last node connects back to First node.

HC ⇒ HP

HP ⇏ HC
*/
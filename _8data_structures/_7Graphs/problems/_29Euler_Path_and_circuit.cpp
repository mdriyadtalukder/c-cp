// every edges k ekbar kre visit kre in graph..its called euler path..every edge ekbr kre visit kre..node/vertex onkbar visit krleo prblm nei.
//  every edges k ekbar kre visit kre in graph and starting node and ending node same hbe..like circle..its called euler circuit.
// every edges ekbar kre visit kre..not every node..like ekta node ase jar kono edge nai in a graph..oita visit na kreo EP ba EC hobe jdi eder condition meet kre..every edge ekbr visit kre.
// every node er degree(koita egde er shthe connected ekta node) jdi even shongkha hy and all non zero degree connected hy tahole EC possible.
// 0 r 2 node will be odd degree and others node will be even degree and non zero degree will be conncted hole euler path hbe..
// EC==EP but EP!=EC
// TC: V+E
// SC:V

// EC hole 2 return krbo..EP hole 1..otherwise 0
#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = 1;
    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]])
        {
            DFS(adj[node][j], adj, visited);
        }
    }
}

int isEulerCircuit(int V, vector<int> adj[])
{
    // Euler Circuit: 2
    // Calculate the Degree of Each node
    // All node should have even degree
    // All non-zero degree node should be connected

    // Euler path: 1
    // Calculate the Degree of Each node
    // zero or two node can have odd degree and remaining have even degree
    // All non-zero degree node should be connected

    vector<int> Deg(V, 0);
    int Odd_Deg = 0; // number of nodes having odd degree

    for (int i = 0; i < V; i++)
    {
        Deg[i] = adj[i].size();
        if (Deg[i] % 2)
            Odd_Deg++;
    }

    if (Odd_Deg != 2 && Odd_Deg != 0)
        return 0;

    vector<bool> visited(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (Deg[i])
        {
            DFS(i, adj, visited);
            break;
        }
    }

    // If non zero degree node is still not visited, return 0
    // Degree zero hai, usko ignore (Koi edge nahi hai)

    for (int i = 0; i < V; i++)
    {
        if (Deg[i] && !visited[i])
            return 0;
    }

    // Eulerian circuit: 2
    // Eulerian Path: 1

    if (Odd_Deg == 0)
        return 2;
    else
        return 1;
}


/*
Euler Path and Circuit

Problem Statement:

Given an undirected graph, determine whether it has:

1. Euler Circuit
2. Euler Path
3. Neither

Definitions:

Euler Path:
A path that visits every EDGE exactly once.

Euler Circuit:
A path that visits every EDGE exactly once
and starts and ends at the same vertex.

A vertex may be visited multiple times.

Only every edge must be visited exactly once.

Vertices having degree 0
(isolated vertices)
are ignored.

Return:

2 -> Euler Circuit exists

1 -> Euler Path exists

0 -> Neither exists

------------------------------------------------

Example 1:

Input:

0 ----- 1
|       |
|       |
3 ----- 2

Output:

2

Explanation:

All vertices have even degree.

The graph is connected.

Euler Circuit exists.

------------------------------------------------

Example 2:

Input:

0 ----- 1 ----- 2

Output:

1

Explanation:

Vertex 0 has odd degree.

Vertex 2 has odd degree.

Exactly two odd-degree vertices exist.

Euler Path exists,
but Euler Circuit does not.

------------------------------------------------

Example 3:

Input:

0 ----- 1

2 ----- 3

Output:

0

Explanation:

The graph is disconnected.

All non-zero degree vertices
are not connected.

Therefore neither Euler Path
nor Euler Circuit exists.

------------------------------------------------

Conditions:

Euler Circuit:

1. Every vertex has even degree.
2. All vertices having non-zero degree
   are connected.

Euler Path:

1. Exactly 0 or 2 vertices
   have odd degree.
2. All vertices having non-zero degree
   are connected.

------------------------------------------------

Constraints:

1 <= V <= 10^5

0 <= E <= 2 × 10^5

Expected Time Complexity:
O(V + E)

Expected Auxiliary Space:
O(V)

Approach:

1. Calculate the degree of every vertex.
2. Count the number of odd-degree vertices.
3. If odd-degree vertices are neither
   0 nor 2, return 0.
4. Perform DFS from any non-zero degree vertex.
5. Verify that every non-zero degree vertex
   is visited.
6. If the graph is disconnected,
   return 0.
7. If odd-degree vertices = 0,
   return 2 (Euler Circuit).
8. Otherwise return 1 (Euler Path).
*/
// every edges k ekbar kre visit kre in graph..its called euler path..
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
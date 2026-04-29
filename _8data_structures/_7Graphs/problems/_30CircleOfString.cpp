// kisu string deoya thkbe..oita chain hbe nki eita check kra,,jdi hy taile true return krbo otherwise false
// ab bc cd da(it a chain)---jdi kono string er last character onno kono string er 1st character er shthe mile and every string jdi ei circle er vitor thke tahole chain hbe
// abc cde edf--f er shthe 1st string er 1st character mile nai so its not a chain.. sob string present thkte hbe in chain.
// current string er last er shthe joto guli string er 1st ta mile sob gulir shthe connection dibo correct ans find korar jnno..

// solve: sob gulir shthe edges connect krbo based on condition then jdi EC hy taile eita true hbe..
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

int isCircle(int N, vector<string> A)
{
    // edges create karna
    // Adjacency list
    // a-z
    // a-0, b-1, c-2, ... z-25

    vector<int> adj[26];
    vector<int> InDeg(26, 0);
    vector<int> OutDeg(26, 0);

    for (int i = 0; i < N; i++)
    {
        string temp = A[i];
        int u = temp[0] - 'a';
        int v = temp[temp.size() - 1] - 'a'; // FIX

        adj[u].push_back(v);
        OutDeg[u]++;
        InDeg[v]++;
    }

    // Eulerian Circuit
    // Find Indegree and OutDegree

    for (int i = 0; i < 26; i++)
    {
        if (InDeg[i] != OutDeg[i])
            return 0;
    }

    // All the edges are part of one component

    vector<bool> visited(26, 0);

    int node = A[0][0] - 'a';
    DFS(node, adj, visited);

    for (int i = 0; i < 26; i++)
    {
        if (InDeg[i] && !visited[i])
            return 0; // FIX
    }

    return 1;
}
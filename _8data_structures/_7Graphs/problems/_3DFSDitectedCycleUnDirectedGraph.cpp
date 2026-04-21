// ekta node jdi 1 er besi visisted hy taile oitai cycle ase..ekadin node er child same ase nki
// TC=O(v+e)..SC=O(v)
#include <bits/stdc++.h>
using namespace std;
bool CycleDetect(int node, int parent, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = 1;

    for (int j = 0; j < adj[node].size(); j++)
    {
        if (adj[node][j] == parent)
            continue;

        if (visited[adj[node][j]])
            return 1;

        if (CycleDetect(adj[node][j], node, adj, visited))
            return 1;
    }

    return 0;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, 0);
    // return CycleDetect(0, -1, adj, visited);//-1 is parent ..0 is node
    // disconnected graph also
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (CycleDetect(i, -1, adj, visited))
                return 1;
        }
    }

    return 0;
}

/* updated version in GFG


bool cycleDFS(int node, int parent, vector<bool> & visited, vector<vector<int>>& edges) {
        visited[node] = 1;

        for(int i = 0; i < edges[node].size(); i++) {
            if(edges[node][i] == parent)
            continue;

            if(visited[edges[node][i]])
            return 1;

            if(cycleDFS(edges[node][i], node, visited, edges))
            return 1;
        }

        return 0;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        // Converting Edges to the adjacency list
        vector<vector<int>> adjList(V);

        for(int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        // Simulating the logic
        vector<bool> visited(V, 0);

        for(int i = 0; i < V; i++)
        if(!visited[i] && cycleDFS(i, -1, visited, adjList))
        return 1;

        return 0;
    }*/
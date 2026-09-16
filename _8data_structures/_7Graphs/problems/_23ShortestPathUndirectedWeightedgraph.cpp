
// src to destination er shortest path..0-5 er shortest path
//  dijkstra er motoi just jokhn node er value set krbo with previous weighted sum tokhn tar parents k just parents array te array krbo
//  initially parents array er value thkbe -1
//  jar parent sei no index e tar parent value rakhbe..0 er parent -1.
//  src and destination deoya thkbe tar shortest path dite hbe like 0357..
//  TC=O(elogv+v)..sc=O(e+v)
#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int V, int m, vector<vector<int>> &edges)
{

    // adjacency list create
    // neighbour, weight
    vector<pair<int, int>> adj[V + 1];

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    // Dijkstra Algorithm
    vector<bool> Explored(V + 1, 0);
    vector<int> dist(V + 1, INT_MAX);
    vector<int> parent(V + 1, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;

    p.push({0, 1});
    dist[1] = 0;

    while (!p.empty())
    {
        int node = p.top().second;
        p.pop();

        if (Explored[node])
            continue;

        Explored[node] = 1;

        for (int j = 0; j < adj[node].size(); j++)
        {
            int neighbour = adj[node][j].first;
            int weight = adj[node][j].second;

            if (!Explored[neighbour] && dist[node] + weight < dist[neighbour])
            {
                dist[neighbour] = dist[node] + weight;
                p.push({dist[neighbour], neighbour});
                parent[neighbour] = node; // current node er parent storing
            }
        }
    }

    vector<int> path;
    if (parent[V] == -1) // if i cant reach my destination
    {
        path.push_back(-1);
        return path;
    }
    int dest = V;
    // i can reach
    while (dest != -1)
    {
        path.push_back(dest);
        dest = parent[dest];
    }
    path.push_back(dist[V]); // 0 to des er weight ja 1st a hbe tai reverse krlm
    reverse(path.begin(), path.end());

    return path;
}

/*
vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {

        vector<pair<int,int>> adj[V+1];

        for(auto &e:edges){
            int u=e[0];
            int vl=e[1];
            int w=e[2];

            adj[u].push_back({vl,w});
            adj[vl].push_back({u,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

        vector<int> dist(V+1,INT_MAX);

        dist[dest]=0;
        q.push({0,dest});

        while(!q.empty()){
            int dis=q.top().first;
            int node=q.top().second;
            q.pop();

            if(dis>dist[node]) continue;

            for(int i=0;i<adj[node].size();i++){
                int nei=adj[node][i].first;
                int wei=adj[node][i].second;

                if(dist[node]+wei<dist[nei]){
                    dist[nei]=dist[node]+wei;
                    q.push({dist[nei],nei});
                }
            }
        }

        vector<int> path;

        if(dist[src]==INT_MAX){
            path.push_back(-1);
            return path;
        }

        int node=src;
        path.push_back(node);

        while(node!=dest){

            int nextNode=-1;

            for(int i=0;i<adj[node].size();i++){
                int nei=adj[node][i].first;
                int wei=adj[node][i].second;

                if(dist[node]==dist[nei]+wei){

                    if(nextNode==-1 || nei<nextNode)
                        nextNode=nei;
                }
            }

            node=nextNode;
            path.push_back(node);
        }

        return path;
    }

*/
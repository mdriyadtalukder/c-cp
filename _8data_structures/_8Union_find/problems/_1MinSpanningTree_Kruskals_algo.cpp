// node j koita thkbe oitar theke ekta kom egde nibo..egde nite thkbo untill get node-1 edge from small weights..
// then jdi dekhi small weight but eita nile circle hbe tahole oita bad dia porer ta nibo..so on..Kruskal's with greedy

// disjoint set-->jdi 2 tar node same set er vitor thke tahole tader edge nibona..all connected nodes will be in same set..j kono vabe connet hoilei hyse sob gula..oita sob tuku 1ta set hbe
// 1st node er shthe jar connect krbo tar value nibo 1st node ta..then joto guli eder shthe connect krbo tar value 1st node er value nibo
// jdi 2 tar node er value e 1st node na hy(like 1tar value 1st node r ektar other value..so they will be connected) tahole tader modde edge dibo.

// Sparse graph → Kruskal---Dense graph → Prim
// its better for sparse graph
//  Best case: O(E + V log V)--Worst case: O(E log E) or elogv
//  sc=O(V + E)
#include <bits/stdc++.h>
using namespace std;

int FindParent(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return parent[u] = FindParent(parent[u], parent);
}

void UnionByRank(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int pu = FindParent(u, parent);
    int pv = FindParent(v, parent);

    if (pu == pv)
        return;

    if (rank[pu] > rank[pv])
    {
        parent[pv] = pu;
    }
    else if (rank[pu] < rank[pv])
    {
        parent[pu] = pv;
    }
    else
    {
        parent[pv] = pu;
        rank[pu]++;
    }
}

int spanningTree(int V, vector<vector<int>> &edges)
{
    // 🔹 STEP 1: create adjacency list from edges
    vector<vector<vector<int>>> adj(V);

    for (auto &e : edges)
    {
        int u = e[0];
        int v = e[1];
        int wt = e[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // undirected
    }

    // 🔹 DSU init
    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // 🔹 STEP 2: temp edges
    vector<pair<int, pair<int, int>>> temp;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            int v = adj[i][j][0];
            int wt = adj[i][j][1];
            temp.push_back({wt, {i, v}});
        }
    }

    // 🔹 STEP 3: pq from temp
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>
        pq(temp.begin(), temp.end());

    int cost = 0;
    int edgeCount = 0;

    // 🔹 STEP 4: Kruskal
    while (!pq.empty())
    {
        int wt = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        if (FindParent(u, parent) != FindParent(v, parent))
        {
            cost += wt;
            UnionByRank(u, v, parent, rank);
            edgeCount++;
        }

        if (edgeCount == V - 1)
            break;
    }

    return cost;
}
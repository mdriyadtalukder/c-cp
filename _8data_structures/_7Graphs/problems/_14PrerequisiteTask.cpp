// 0->1 then 1->2..age ager task gula complete hbe then next gula..directed graph
//kahns algo use krbo bfs er...cycle hole complet hbe na task..so oitai check krbo.
#include <bits/stdc++.h>
using namespace std;
bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
    
    // Adjacency list create karo
    vector<int> adj[N];
    vector<int> InDeg(N, 0);

    for(int i = 0; i < P; i++)
    {
        adj[prerequisites[i].second].push_back(prerequisites[i].first);
        InDeg[prerequisites[i].first]++;
    }

    // Kahn's algorithm
    queue<int> q;

    for(int i = 0; i < N; i++)
        if(!InDeg[i])
            q.push(i);

    int count = 0; // Kitna size ka mera topological sort hoga

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

        // Look at the neighbour
        for(int j = 0; j < adj[node].size(); j++)
        {
            InDeg[adj[node][j]]--;
            if(!InDeg[adj[node][j]])
                q.push(adj[node][j]);
        }
    }

    return count == N;
}
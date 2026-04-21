// TC=O(v+e)..SC=O(v)
//1st e ekta node slect krbo then tar child print krbo then tader child print krbo..so on
#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    queue<int> q;
    q.push(0);

    vector<bool> visited(V, 0);
    visited[0] = 1;

    vector<int> ans;
    int node;

    while (!q.empty())
    {
        node = q.front();
        q.pop();
        ans.push_back(node);

        for (int j = 0; j < adj[node].size(); j++)
        {
            if (!visited[adj[node][j]])
            {
                visited[adj[node][j]] = 1;
                q.push(adj[node][j]);
            }
        }
    }

    return ans;
}

int main()
{
    int V = 5;

    vector<int> adj[V];

    // hardcoded graph (undirected)
    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[1].push_back(0);
    adj[1].push_back(3);

    adj[2].push_back(0);
    adj[2].push_back(4);

    adj[3].push_back(1);
    adj[4].push_back(2);

    vector<int> ans = bfsOfGraph(V, adj);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
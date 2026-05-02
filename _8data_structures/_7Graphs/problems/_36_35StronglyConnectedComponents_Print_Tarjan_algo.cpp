// 35 num e prblm..just eita print krbo..and algo alada..
// print kro every component er node value serially or any order(based on ques) like 1 2 3 4.--like [[1,2,3,4],[5,6,7],[8]]
// Time Complexity: O(V + E)
// Space Complexity: O(V)
#include <bits/stdc++.h>
using namespace std;
void DFS(int node, vector<int> adj[],
         vector<int> &disc, vector<int> &low,
         vector<bool> &visited, stack<int> &s,
         vector<bool> &InStack, vector<vector<int>> &ans,
         int &timer)
{
    visited[node] = 1;
    disc[node] = low[node] = timer;
    s.push(node);
    InStack[node] = 1;

    for (int j = 0; j < adj[node].size(); j++)
    {
        int neib = adj[node][j];

        if (!visited[neib])
        {
            timer++;
            DFS(neib, adj, disc, low, visited, s, InStack, ans, timer);

            low[node] = min(low[node], low[neib]);
        }
        else
        {
            if (InStack[neib])
            {
                low[node] = min(low[node], disc[neib]);
            }
        }
    }

    if (disc[node] == low[node])
    {
        vector<int> temp;

        while (!s.empty() && s.top() != node)
        {
            temp.push_back(s.top());
            InStack[s.top()] = 0;
            s.pop();
        }

        temp.push_back(node);
        InStack[node] = 0;
        s.pop();

        sort(temp.begin(), temp.end());
        ans.push_back(temp);
    }
}

vector<vector<int>> tarjans(int V, vector<vector<int>> &adj)
{
    vector<vector<int>> ans;

    vector<int> disc(V);
    vector<int> low(V);
    vector<bool> visited(V, 0);
    vector<bool> InStack(V, 0);

    stack<int> s;

    int timer = 0;

    // convert vector<vector<int>> to vector<int> adj[]
    vector<int> g[V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            g[i].push_back(adj[i][j]);
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFS(i, g, disc, low, visited, s, InStack, ans, timer);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}
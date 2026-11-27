#include <bits/stdc++.h>
using namespace std;

// dfs
int maxTime = 0;

void DFS(unordered_map<int, vector<int>> &adj,
         vector<int> &informTime,
         int curr_employee,
         int curr_time)
{

    maxTime = max(maxTime, curr_time);

    for (int i = 0; i < adj[curr_employee].size(); i++)
    {
        int employee = adj[curr_employee][i];

        DFS(adj, informTime, employee,
            curr_time + informTime[curr_employee]);
    }
}

int numOfMinutes(int n, int headID,
                 vector<int> &manager,
                 vector<int> &informTime)
{

    unordered_map<int, vector<int>> adj;

    for (int i = 0; i < manager.size(); i++)
    {
        if (manager[i] != -1)
        {
            adj[manager[i]].push_back(i);
        }
    }

    DFS(adj, informTime, headID, 0);

    return maxTime;
}

// bfs
int numOfMinutes(int n, int headID,
                 vector<int> &manager,
                 vector<int> &informTime)
{

    unordered_map<int, vector<int>> adj;

    for (int i = 0; i < manager.size(); i++)
    {
        if (manager[i] != -1)
        {
            adj[manager[i]].push_back(i);
        }
    }

    queue<pair<int, int>> q;
    q.push({headID, 0});

    int maxTime = 0;

    while (!q.empty())
    {
        int curr_employee = q.front().first;
        int curr_time = q.front().second;
        q.pop();

        maxTime = max(maxTime, curr_time);

        for (int &employee : adj[curr_employee])
        {
            q.push({employee, curr_time + informTime[curr_employee]});
        }
    }

    return maxTime;
}
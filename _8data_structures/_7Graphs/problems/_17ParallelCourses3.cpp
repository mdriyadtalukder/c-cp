//[[1,3],[2,3]]->3 no korar age 1 o 2 no course comple krte hbe..[3,2,5]-1st course krte 3 mnth lgbe,2nd course e 2 month o 3rd krte 5 month.
// min koto time lgbe sob course krte 3+5=8 month..1st and 2nd ek shthe suru krsi kora coz eder dependancy nai ..so 3 month lgbe..last ta 5 month..
// like onk gula pre course ase last course krte..max time jeitai lagbe oita+last course er month hbe ans.
#include <bits/stdc++.h>
using namespace std;
int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
{

    // create adjacency list
    vector<int> adj[n];

    for (int i = 0; i < relations.size(); i++)
    {
        // Convert them into 0 based indexing
        adj[relations[i][0] - 1].push_back(relations[i][1] - 1);
    }

    vector<int> InDeg(n, 0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < adj[i].size(); j++)
            InDeg[adj[i][j]]++;

    queue<int> q;

    for (int i = 0; i < n; i++)
        if (!InDeg[i])
            q.push(i);

    // Maximum time to complete Previous Course
    vector<int> CourseTime(n, 0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int j = 0; j < adj[node].size(); j++)
        {
            InDeg[adj[node][j]]--;

            // Maximum Time To Complete Previous Course + Present Course Time
            CourseTime[adj[node][j]] = max(
                CourseTime[adj[node][j]],
                CourseTime[node] + time[node]);

            if (!InDeg[adj[node][j]])
                q.push(adj[node][j]);
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, CourseTime[i] + time[i]);
    }

    return ans;
}
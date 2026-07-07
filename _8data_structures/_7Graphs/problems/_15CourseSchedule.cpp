// 14 no er motoi just order print krte hbe..
#include <bits/stdc++.h>
using namespace std;
vector<int> findOrder(int N, vector<vector<int>> &prerequisites)
{

    // Adjacency list create karo
    vector<int> adj[N];
    vector<int> InDeg(N, 0);

    int P = prerequisites.size(); // ❗ missing

    for (int i = 0; i < P; i++)
    {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        InDeg[prerequisites[i][0]]++; // ❗ bracket fix
    }

    // Kahn's algorithm
    queue<int> q;

    for (int i = 0; i < N; i++)
        if (!InDeg[i])
            q.push(i);

    vector<int> ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node); // ❗ typo fix

        // Look at the neighbour
        for (int j = 0; j < adj[node].size(); j++)
        {
            InDeg[adj[node][j]]--;
            if (!InDeg[adj[node][j]])
                q.push(adj[node][j]);
        }
    }

    vector<int> temp;

    return ans.size() == N ? ans : temp; // ❗ condition fix
}

/*
LeetCode 210. Course Schedule II

Problem Statement:

There are a total of N courses labeled from 0 to N-1.

You are given a list of prerequisite pairs where:

{a, b} means you must complete course b before taking course a.

Return one valid order in which you can finish all courses.

If there are multiple valid answers, return any one of them.

If it is impossible to finish all courses because of a cycle,
return an empty vector.

Input:
- N: Number of courses.
- prerequisites: A list of prerequisite pairs.

Output:
- Return a vector containing one valid order of courses.
- If no valid order exists, return {}.

Example 1:

Input:
N = 2
prerequisites = {
    {1,0}
}

Output:
{0,1}

Explanation:
Complete course 0 first, then course 1.

------------------------------------------------

Example 2:

Input:
N = 4
prerequisites = {
    {1,0},
    {2,0},
    {3,1},
    {3,2}
}

Output:
{0,1,2,3}

Explanation:
One valid order is:

0 -> 1 -> 2 -> 3

Another valid answer is:

0 -> 2 -> 1 -> 3

------------------------------------------------

Example 3:

Input:
N = 2
prerequisites = {
    {1,0},
    {0,1}
}

Output:
{}

Explanation:
A cycle exists:

0 -> 1
↑    ↓
└────┘

Therefore, no valid ordering exists.

Constraints:
1 <= N <= 2000
0 <= prerequisites.length <= 5000

Expected Time Complexity:
O(N + P)

Expected Auxiliary Space:
O(N)

Approach:
1. Build the directed graph.
2. Compute the indegree of every course.
3. Push all courses having indegree 0 into a queue.
4. Perform Kahn's Algorithm (BFS Topological Sort).
5. Store each processed course in the answer.
6. If the answer contains all N courses, return it.
7. Otherwise, return an empty vector because the graph contains a cycle.
*/
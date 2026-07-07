// 0->1 then 1->2..age ager task gula complete hbe then next gula..directed graph
//kahns algo use krbo bfs er...cycle hole complet hbe na task..so oitai check krbo.
#include <bits/stdc++.h>
using namespace std;

bool isPossible(int N, int P, vector<pair<int, int>>& prerequisites)
{
    // -------------------------------
    // Step 1:
    // Build adjacency list and
    // calculate indegree of every node.
    // -------------------------------

    vector<int> adj[N];
    vector<int> InDeg(N, 0);

    for (int i = 0; i < P; i++)
    {
        // prerequisite.second -> prerequisite.first
        // (second must be done before first)

        adj[prerequisites[i].second].push_back(prerequisites[i].first);

        // Increase indegree of destination node
        InDeg[prerequisites[i].first]++;
    }

    // -------------------------------
    // Step 2:
    // Push every node having indegree 0.
    // These courses have no prerequisites.
    // -------------------------------

    queue<int> q;

    for (int i = 0; i < N; i++)
    {
        if (InDeg[i] == 0)
            q.push(i);
    }

    // Number of processed courses
    int count = 0;

    // -------------------------------
    // Step 3:
    // Perform Kahn's Algorithm (BFS)
    // -------------------------------

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        count++;

        // Remove all outgoing edges
        for (int j = 0; j < adj[node].size(); j++)
        {
            int neighbour = adj[node][j];

            InDeg[neighbour]--;

            // If indegree becomes 0,
            // this course can now be taken.
            if (InDeg[neighbour] == 0)
                q.push(neighbour);
        }
    }

    // -------------------------------
    // Step 4:
    // If every node was processed,
    // no cycle exists.
    //
    // Otherwise, a cycle exists,
    // so finishing all courses
    // is impossible.
    // -------------------------------

    return count == N;
}

/*
LeetCode 207. Course Schedule

Problem Statement:

There are a total of N courses labeled from 0 to N-1.

You are given a list of prerequisite pairs where:

{a, b} means you must complete course b before taking course a.

Determine whether it is possible to finish all courses.

If it is possible, return true.
Otherwise, return false.

Input:
- N: Number of courses.
- P: Number of prerequisite pairs.
- prerequisites: A list of pairs {course, prerequisite}.

Output:
- Return true if all courses can be completed.
- Otherwise return false.

Example 1:

Input:
N = 2
prerequisites = {
    {1,0}
}

Output:
true

Explanation:
Complete course 0 first, then course 1.

Topological order:
0 -> 1

------------------------------------------------

Example 2:

Input:
N = 2
prerequisites = {
    {1,0},
    {0,1}
}

Output:
false

Explanation:
There is a cycle:

0 -> 1
↑    ↓
└────┘

Neither course can be completed first.

------------------------------------------------

Example 3:

Input:
N = 4
prerequisites = {
    {1,0},
    {2,0},
    {3,1},
    {3,2}
}

Output:
true

Explanation:
One valid order is:

0 -> 1 -> 2 -> 3

or

0 -> 2 -> 1 -> 3

Constraints:
1 <= N <= 2000
0 <= P <= 5000

Expected Time Complexity:
O(N + P)

Expected Auxiliary Space:
O(N)

Approach:
1. Build the directed graph.
2. Compute the indegree of every course.
3. Push all courses with indegree 0 into a queue.
4. Perform Kahn's Algorithm (BFS Topological Sort).
5. Count the number of processed courses.
6. If count == N, no cycle exists, so all courses can be completed.
7. Otherwise, a cycle exists, making it impossible to finish all courses.
*/
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
        if (InDeg[i] == 0)
            q.push(i);

    // Maximum time to complete Previous Course
    vector<int> CourseTime(n, 0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int j = 0; j < adj[node].size(); j++)
        {
            InDeg[adj[node][j]]--; // jar dike gese tir tar indeg-- hy

            // Maximum Time To Complete Previous Course + Present Course Time
            CourseTime[adj[node][j]] = max(
                CourseTime[adj[node][j]],
                CourseTime[node] + time[node]); // jar dike gese tir tar indrx e current value and prev er value add hote thkbe..pre value na thkle 0 er shthe compare hbe as this has no indeg

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

/*
LeetCode 2050. Parallel Courses III

Problem Statement:

There are n courses labeled from 1 to n.

You are given:

- relations, where
  relations[i] = {prevCourse, nextCourse}

meaning prevCourse must be completed before nextCourse can begin.

You are also given an array time where:

time[i] = number of months required to complete course (i+1).

Rules:

- You may begin any number of courses simultaneously.
- A course can only begin after ALL of its prerequisites
  have been completed.

Return the minimum number of months required to complete
all courses.

--------------------------------------------------------

Example 1:

Input:

n = 3

relations = {
    {1,3},
    {2,3}
}

time = {3,2,5}

Output:

8

Explanation:

Month 0:

Course 1 starts (3 months)
Course 2 starts (2 months)

Month 2:

Course 2 finishes.

Course 3 cannot start yet because
Course 1 is still running.

Month 3:

Course 1 finishes.

Now all prerequisites are completed.

Start Course 3.

Month 8:

Course 3 finishes.

Answer = 8

--------------------------------------------------------

Example 2:

Input:

n = 5

relations = {
    {1,5},
    {2,5},
    {3,5},
    {3,4},
    {4,5}
}

time = {1,2,3,4,5}

Output:

12

Explanation:

Course 5 depends on:

Course 1
Course 2
Course 3
Course 4

Course 4 itself depends on Course 3.

Earliest completion:

Course 1 = 1
Course 2 = 2
Course 3 = 3
Course 4 = 7
Course 5 = 12

--------------------------------------------------------

Constraints:

1 <= n <= 5 × 10^4

0 <= relations.length <= 5 × 10^4

relations[i].length == 2

1 <= time[i] <= 10^4

The prerequisite graph is a Directed Acyclic Graph (DAG).

Expected Time Complexity:
O(n + m)

Expected Auxiliary Space:
O(n + m)

Approach:

1. Build the directed graph.
2. Compute indegree of every course.
3. Perform Kahn's Topological Sort.
4. Maintain CourseTime[i], the earliest start time of course i.
5. For every edge u -> v:

   CourseTime[v] =
       max(CourseTime[v],
           CourseTime[u] + time[u])

6. After processing all courses,
   answer =

   max(CourseTime[i] + time[i])

because completion time =
start time + course duration.
*/
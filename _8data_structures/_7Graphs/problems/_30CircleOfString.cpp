// kisu string deoya thkbe..oita chain hbe nki eita check kra,,jdi hy taile true return krbo otherwise false
// ab bc cd da(it a chain)---jdi kono string er last character onno kono string er 1st character er shthe mile and every string jdi ei circle er vitor thke(ab->bc->ca->ab) tahole chain hbe
// abc cde edf--f er shthe 1st string er 1st character mile nai so its not a chain.. sob string present thkte hbe in chain.
// current string er last er shthe joto guli string er 1st ta mile sob gulir shthe connection dibo correct ans find korar jnno..

// solve: sob gulir shthe edges connect krbo based on condition then jdi EC hy taile eita true hbe..
#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = 1;
    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]])
        {
            DFS(adj[node][j], adj, visited);
        }
    }
}

int isCircle(int N, vector<string> A)
{
    // edges create karna
    // Adjacency list
    // a-z
    // a-0, b-1, c-2, ... z-25

    vector<int> adj[26];
    vector<int> InDeg(26, 0);  // jar dike jai
    vector<int> OutDeg(26, 0); // jar theke tir ber hy

    for (int i = 0; i < N; i++)
    {
        string temp = A[i];
        int u = temp[0] - 'a';
        int v = temp[temp.size() - 1] - 'a'; // FIX

        adj[u].push_back(v);
        OutDeg[u]++;
        InDeg[v]++;
    }

    // Eulerian Circuit
    // Find Indegree and OutDegree

    for (int i = 0; i < 26; i++)
    {
        if (InDeg[i] != OutDeg[i])
            return 0;
    }

    // All the edges are part of one component

    vector<bool> visited(26, 0);

    int node = A[0][0] - 'a';
    DFS(node, adj, visited);

    for (int i = 0; i < 26; i++)
    {
        if (InDeg[i] && !visited[i])
            return 0; // FIX
    }

    return 1;
}

/*
Circle of Strings

Problem Statement:

You are given an array of strings.

Determine whether all the strings
can be chained together to form
a circle.

A string X can be followed by string Y
if the last character of X
is equal to the first character of Y.

Every string must be used exactly once.

Return:

1 -> If a circular chain exists.

0 -> Otherwise.

------------------------------------------------

Example 1:

Input:

A = {
    "ab",
    "bc",
    "cd",
    "da"
}

Output:

1

Explanation:

ab -> bc -> cd -> da -> ab

Every string is used exactly once
and the last string connects back
to the first.

------------------------------------------------

Example 2:

Input:

A = {
    "abc",
    "cde",
    "edf"
}

Output:

0

Explanation:

The last character of "edf" is 'f'.

No string starts with 'f'.

Therefore, a circular chain
cannot be formed.

------------------------------------------------

Example 3:

Input:

A = {
    "for",
    "rig",
    "geek",
    "kaf"
}

Output:

1

Explanation:

for -> rig -> geek -> kaf -> for

Forms a valid circle.

------------------------------------------------

Constraints:

1 <= N <= 10^5

1 <= length of each string <= 100

Strings contain only lowercase English letters.

Expected Time Complexity:
O(N + 26)

Expected Auxiliary Space:
O(26)

Approach:

1. Represent each character ('a' to 'z')
   as a graph vertex.
2. For every string,
   create an edge from its first character
   to its last character.
3. Compute indegree and outdegree
   of every vertex.
4. If any vertex has
   indegree != outdegree,
   return 0.
5. Perform DFS from any vertex
   having a non-zero degree.
6. Verify that every vertex with
   non-zero degree is visited.
7. If both conditions hold,
   an Euler Circuit exists,
   so return 1.
*/
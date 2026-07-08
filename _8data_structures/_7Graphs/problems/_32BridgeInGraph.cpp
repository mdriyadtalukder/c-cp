// bridge sei edge jake remove krle graph 2 part e vag hbe..baa sei edge ta cycle er part na..
// 2 ta array hbe disc and low...jdi cycle hy tahole jar vitor theke tir ashe and jar vitore tir jai eder low er min ta jar vitor theke tir ashe take k dibo...and back krbo and eivbe sobar low set krte thkbo until get new edge..low update krte thkbo min ta diye jdi amra cycle er maddhome oi min e powchate pari.
// and jdi disc[parent]<low[child] hole bridge hbe..jar theke tir ashe tar dis<jar dike jai tar low..back er khetre parents na..ashol parent vs child
// Time: O(V + E)---Space: O(V + E)
#include <bits/stdc++.h>
using namespace std;

void DFS(int node, int parent, vector<vector<int>> &adj,
         vector<int> &disc, vector<int> &low,
         vector<bool> &visited,
         vector<vector<int>> &Bridges,
         int &count)
{
    disc[node] = low[node] = count;
    visited[node] = 1;

    for (int j = 0; j < adj[node].size(); j++)
    {
        int neib = adj[node][j];

        if (neib == parent)
            continue;

        else if (visited[neib])
        {
            // back edge
            low[node] = min(low[node], disc[neib]);
        }
        else
        {
            count++;
            DFS(neib, node, adj, disc, low, visited, Bridges, count);

            // update low
            low[node] = min(low[node], low[neib]);

            // bridge condition
            if (low[neib] > disc[node])
            {
                vector<int> temp;
                temp.push_back(node);
                temp.push_back(neib);
                Bridges.push_back(temp);
            }
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<vector<int>> adj(n);

    for (int i = 0; i < connections.size(); i++)
    {
        int u = connections[i][0];
        int v = connections[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> Bridges;
    vector<int> disc(n);
    vector<int> low(n);
    vector<bool> visited(n, 0);

    int count = 0;

    DFS(0, -1, adj, disc, low, visited, Bridges, count);

    return Bridges;
}

/*
-------------------------------------------------------
Explanation

Bridge

A bridge is an edge whose removal disconnects the graph.

Example

0-----1-----2

Removing edge (1,2)

0-----1     2

Graph becomes disconnected.

So (1,2) is a Bridge.

-------------------------------------------------------

If the edge belongs to a cycle,

it is NOT a bridge.

Example

0
|\
| \
1--2

Remove edge (0,1)

Still

0 -> 2 -> 1

So graph remains connected.

Hence it is NOT a bridge.

-------------------------------------------------------

Idea

During DFS we maintain two arrays.

1.

disc[node]

Discovery Time

The time when this node is first visited.

Example

disc

0 1 2 3 ...

-------------------------------------------------------

2.

low[node]

The earliest (minimum discovery time)
reachable from this node
using

Tree edges
+
At most one back edge.

Initially

low[node]=disc[node]

Later it becomes smaller
if a back edge exists.

-------------------------------------------------------

Back Edge

A visited neighbour
that is NOT the parent.

Example

0
|\
| \
1--2

DFS

0→1→2

Edge

2→0

is Back Edge.

So

low[2]=min(low[2],disc[0])

-------------------------------------------------------

Tree Edge

Edge through which DFS goes deeper.

0→1

1→2

Both are tree edges.

-------------------------------------------------------

After returning from child

Update

low[parent]

using

low[child]

low[parent]=min(low[parent],low[child])

-------------------------------------------------------

Bridge Condition

If

low[child] > disc[parent]

then

Parent cannot be reached again
through any alternate path.

Therefore

Parent ----- Child

is the ONLY connection.

Hence

It is a Bridge.

-------------------------------------------------------

Example

0
|
1
|\
| \
2--3

Suppose

disc

0 : 0

1 : 1

2 : 2

3 : 3

Because

2 and 3 form a cycle

low

3=2

2=2

1=1

Now

low[2]=2

disc[1]=1

2>1

So

1-2

is Bridge.

-------------------------------------------------------

Why

low[child] > disc[parent]

?

If

low[child]

cannot go above parent

(no back edge)

then

removing

parent-child

disconnects child subtree.

-------------------------------------------------------

Time Complexity

Building Graph

O(E)

DFS

O(V+E)

Overall

O(V+E)

-------------------------------------------------------

Space Complexity

Adjacency List

O(V+E)

disc

O(V)

low

O(V)

visited

O(V)

Recursion Stack

O(V)

Overall

O(V+E)
*/
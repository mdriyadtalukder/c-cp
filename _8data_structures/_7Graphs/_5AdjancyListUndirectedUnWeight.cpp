#include <iostream>
#include <vector>
using namespace std;

// undirected unweighted graph

/*
    0
   / \
  1---2
   \
    3

Edges:
0-1, 0-2, 1-2, 1-3

so,
0 -> 1, 2
1 -> 0, 2, 3
2 -> 0, 1
3 -> 1

in adjency list,we store data this form..0 node connects with 1,2 then 1 node connected with 0,2,3..so on..
*/

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<int>> AdjList(vertex); // Array with vector

    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u); // undirected
    }

    // printing adjacency list
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (auto x : AdjList[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
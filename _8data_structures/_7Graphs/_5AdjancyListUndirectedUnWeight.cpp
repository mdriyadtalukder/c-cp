#include <iostream>
#include <vector>
using namespace std;

// undirected unweighted graph

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
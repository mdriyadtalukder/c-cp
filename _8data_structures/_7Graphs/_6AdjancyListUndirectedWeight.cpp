#include <iostream>
#include <vector>
using namespace std;

// undirected weighted graph

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<pair<int, int>>> AdjList(vertex); // every index ba array te vector of pair(with node and its weight)(0-(1,45))--0->1=45

    int u, v, weight;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weight;

        AdjList[u].push_back({v, weight});
        AdjList[v].push_back({u, weight}); // undirected
    }

    // Print the list
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (auto &p : AdjList[i])
        {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
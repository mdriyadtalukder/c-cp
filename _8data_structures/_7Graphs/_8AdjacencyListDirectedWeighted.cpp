#include <iostream>
#include <vector>
using namespace std;

// directed weighted graph

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<pair<int, int>>> AdjList(vertex);

    int u, v, weight;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weight;

        AdjList[u].push_back({v, weight}); // only one direction
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
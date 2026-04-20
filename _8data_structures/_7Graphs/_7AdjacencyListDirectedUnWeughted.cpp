#include <iostream>
#include <vector>
using namespace std;

// directed unweighted graph

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<int>> AdjList(vertex);

    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;

        AdjList[u].push_back(v); // only one direction
    }

    // Print the list
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
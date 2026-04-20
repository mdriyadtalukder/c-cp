#include <iostream>
#include <vector>
using namespace std;
// Adjacency matrix
// undirected weighted graph
int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<int>> AdjMat(vertex, vector<int>(vertex, 0));

    int u, v, w;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> w;

        // if input is 1-based, use u--, v--
        AdjMat[u][v] = w;
        AdjMat[v][u] = w; // undirected
    }

    // print matrix
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            cout << AdjMat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
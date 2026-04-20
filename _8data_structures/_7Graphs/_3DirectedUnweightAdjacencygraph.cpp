#include <iostream>
#include <vector>
using namespace std;

// Adjacency matrix
// directed unweighted graph

int main()
{
    int vertex, edges; // node and row
    cin >> vertex >> edges;

    vector<vector<bool>> AdjMat(vertex, vector<bool>(vertex, 0));

    int u, v; // u=row and v=column
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v; // conected graph er edges bolbo from graph
        AdjMat[u][v] = 1;
    }

    // printing the matrix (optional)
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
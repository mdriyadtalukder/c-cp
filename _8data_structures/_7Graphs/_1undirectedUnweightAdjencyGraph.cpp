#include <iostream>
#include <vector>
using namespace std;
// 1-4 number prblm er TC=SC=O(n^2)
//  Adjacency matrix
//  undirected unweighted graph
//remove e TC=O(1)..just r and c dibo then or value zero kre dibo..like ad[r][c]=0 and ad[c][r]=0..this way


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
        AdjMat[v][u] = 1; // because undirected
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
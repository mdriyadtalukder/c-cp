// 0->2->3->0...0 theke 2,3 er shortest path..then 2 theke 1,3 er shortest path..then 3 theke 1,2 er shortest path ber krte hbe
// multisource thakbe.. directed weighted graph..
// ager gulai just src theke baki gular shortest path silo..but eitai multisource thkbe.
// choto choto path theke boro boro path banabo and er maddome shortest path hole tar value update kre min ta dibo.like
// A-D=8,A-B=2,B-C=1,C-D=2 so A-D=2+1+2=5..so 8 value update kre 5 dibo..2+1+2 eikhne intermadiate node holo B..coz everytime B er maddhome all path e jete hyse
// 2d matrix nibo solve er jnno..initially edges e weight dibo i,j te..jader edge direction nei tader infinite value dibo r 0,0 ba 1,1 ba 2,2 emn e 0 value dibo
// then intermadiate 0(0 er maddome sob path e jaoa) dore matrix er value update krbo then 1 k intermadiate dorbo...so on..utill get last node value.
//.like 1 intermadiate so 1 row and 1 column er value same thkbe and i,j same eitar value 0 hbe.r sob cell er min value ta dibo min(pre,cur)
// TC=O(n^3)..sc=O(1)
// why use? coz implementation easy and we can use it for all graph(dense or sparse)..sob graph e same TC ashbe..
// better for dense graph.
#include <bits/stdc++.h>
using namespace std;
void floydWarshall(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Replace 1e8 with INT_MAX
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
            { // 1e8
                matrix[i][j] = INT_MAX;
            }
        }
    }

    // Floyd Warshall Algorithm
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                // Important check to avoid overflow
                if (matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
                    continue;

                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // Convert back INT_MAX to 1e8
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == INT_MAX)
            {
                matrix[i][j] = -1; // 1e8
            }
        }
    }
}
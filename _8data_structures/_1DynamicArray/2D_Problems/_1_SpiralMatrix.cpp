#include <bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;

    int r = matrix.size();
    int c = matrix[0].size();

    int topRow = 0, bottomRow = r - 1;
    int leftCol = 0, rightCol = c - 1;

    int total = 0;

    while (total < r * c)
    {

        // left → right
        for (int i = leftCol; i <= rightCol && total < r * c; i++)
        {
            ans.push_back(matrix[topRow][i]);
            total++;
        }
        topRow++;

        // top | bottom
        for (int i = topRow; i <= bottomRow && total < r * c; i++)
        {
            ans.push_back(matrix[i][rightCol]);
            total++;
        }
        rightCol--;

        // right <- left
        for (int i = rightCol; i >= leftCol && total < r * c; i--)
        {
            ans.push_back(matrix[bottomRow][i]);
            total++;
        }
        bottomRow--;

        // bottom |^ top
        for (int i = bottomRow; i >= topRow && total < r * c; i--)
        {
            ans.push_back(matrix[i][leftCol]);
            total++;
        }
        leftCol++;
    }

    return ans;
}
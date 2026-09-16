#include <bits/stdc++.h>
using namespace std;
/*
There is a food track consisting of cells marked with 0, 1, or other numbers.
Here, 0 signifies the cell is not traceable, 1 signifies it is traceable, and any other number represents the destination.
 Starting from the top-left point, determine the longest path to reach the destination. If no path exists, print -1.

1	1	1
1	0	1
1	9	1

*/
class Solution
{
public:
    int N;
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool valid(int i, int j)
    {
        return i >= 0 && j >= 0 && i < N && j < N;
    }

    int dfs(int i, int j, vector<vector<int>> &mat)
    {

        if (mat[i][j] > 1)
            return 0;

        int temp = mat[i][j];
        mat[i][j] = 0; // visited

        int ans = -1;

        for (int k = 0; k < 4; k++)
        {

            int ni = i + row[k];
            int nj = j + col[k];

            if (valid(ni, nj) && mat[ni][nj])
            {

                int len = dfs(ni, nj, mat);

                if (len != -1)
                    ans = max(ans, len + 1);
            }
        }

        mat[i][j] = temp; // backtracking

        return ans;
    }

    int longestPath(vector<vector<int>> &mat)
    {

        N = mat.size();

        if (mat[0][0] == 0)
            return -1;

        return dfs(0, 0, mat);
    }
};




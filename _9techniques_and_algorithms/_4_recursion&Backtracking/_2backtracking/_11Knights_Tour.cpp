#include <bits/stdc++.h>
using namespace std;
//TC=O(8^n^2)..n*n er matrix ase sekhne 0-8 num ase..0,0 index theke suru krbo and dekhbo sequencely 0,1,2,3,4,5,6,7,8 value travel krte parbo nki..krle parble true dibo..er 8 ta move ase ja star er moto dekhte..circle
bool isValid(vector<vector<int>> &grid, int r, int c, int n, int expVal)
{
    if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expVal)
    {
        return false;
    }

    if (expVal == n * n - 1)
    {
        return true;
    }

    // 8 possible knight moves
    bool ans1 = isValid(grid, r - 2, c + 1, n, expVal + 1);
    bool ans2 = isValid(grid, r - 1, c + 2, n, expVal + 1);
    bool ans3 = isValid(grid, r + 1, c + 2, n, expVal + 1);
    bool ans4 = isValid(grid, r + 2, c + 1, n, expVal + 1);
    bool ans5 = isValid(grid, r + 2, c - 1, n, expVal + 1);
    bool ans6 = isValid(grid, r + 1, c - 2, n, expVal + 1);
    bool ans7 = isValid(grid, r - 1, c - 2, n, expVal + 1);
    bool ans8 = isValid(grid, r - 2, c - 1, n, expVal + 1);

    return ans1 ||
           ans2 ||
           ans3 ||
           ans4 ||
           ans5 ||
           ans6 ||
           ans7 ||
           ans8;
}

bool checkValidGrid(vector<vector<int>> &grid)
{
    return isValid(grid, 0, 0, grid.size(), 0);
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    if (checkValidGrid(grid))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}
// 2d matrix thkbe..value 0 mane pani and 1 mane iland..
// each 1 er upor,nich,dan,bam and diagonali te joto 1 ase mane iland ase sob mile ekta iland hbe..0 mane pani or break or bad..
// first 1 ke khujbo then ilend++ krbo and oitar row and column er index queue te dukabo and er ashepasher o diagonal sob zero banabo..
#include <bits/stdc++.h>
using namespace std;

int r;
int c;

int row[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
int col[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

bool valid(int i, int j)
{
    return i >= 0 && i < r && j >= 0 && j < c;
}

int countIslands(vector<vector<char>> &grid)
{

    r = grid.size();
    c = grid[0].size();

    queue<pair<int, int>> q;
    int count = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 'L') // 🔥 FIX
            {
                count++;

                q.push(make_pair(i, j));
                grid[i][j] = 'W'; // 🔥 FIX

                while (!q.empty())
                {
                    int new_i = q.front().first;
                    int new_j = q.front().second;
                    q.pop();

                    for (int k = 0; k < 8; k++)
                    {
                        if (valid(new_i + row[k], new_j + col[k]) &&
                            grid[new_i + row[k]][new_j + col[k]] == 'L') // 🔥 FIX //1
                        {
                            grid[new_i + row[k]][new_j + col[k]] = 'W'; // 0
                            q.push(make_pair(new_i + row[k], new_j + col[k]));
                        }
                    }
                }
            }
        }
    }

    return count;
}

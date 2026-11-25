#include <bits/stdc++.h>
using namespace std;

// dfs
void dfs(vector<vector<int>> &image, int i, int j, int newColor, int orgColor)
{
    if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() ||
        image[i][j] == newColor || image[i][j] != orgColor)
    {
        return;
    }

    image[i][j] = newColor;

    dfs(image, i - 1, j, newColor, orgColor); // top
    dfs(image, i, j + 1, newColor, orgColor); // right
    dfs(image, i + 1, j, newColor, orgColor); // bottom
    dfs(image, i, j - 1, newColor, orgColor); // left
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    dfs(image, sr, sc, color, image[sr][sc]);

    return image;
}

// bfs
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int m = image.size();
    int n = image[0].size();

    int orgColor = image[sr][sc];

    queue<pair<int, int>> q;
    q.push({sr, sc});
    image[sr][sc] = color;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        // auto [i, j] = q.front();
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int ni = i + dr[k];
            int nj = j + dc[k];

            if (ni >= 0 && nj >= 0 && ni < m && nj < n &&
                image[ni][nj] == orgColor && orgColor != color)
            {
                image[ni][nj] = color;
                q.push({ni, nj});
            }
        }
    }

    return image;
}
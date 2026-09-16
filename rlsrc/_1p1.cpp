#include <bits/stdc++.h>
using namespace std;

// const int ROWS = 11;
// const int COLS = 11;

// int maze[ROWS][COLS] = {
//     {4, 3, 7, 8, 3, 6, 5, 4, -1, 2, 3},
//     {6, -1, -1, -1, -1, -1, -1, 5, 2, 0, 94},
//     {7, -1, -1, 16, -1, -1, 7, 1, -1, -1, 5},
//     {1, 15, 25, 0, 3, 5, 6, -1, 6, 2, 6},
//     {9, -1, -1, 21, -1, -1, -1, -1, 5, -1, 2},
//     {2, -1, -1, 22, -1, -1, 5, -1, 4, -1, 7},
//     {8, -1, -1, 26, -1, -1, 5, -1, 3, -1, 6},
//     {20, 5, 3, 4, 11, 23, 11, -1, 2, -1, 5},
//     {2, -1, -1, -1, -1, -1, 20, -1, 2, -1, 4},
//     {4, -1, 4, -1, -1, -1, 4, -1, 1, -1, 3},
//     {6, 7, 8, 8, 7, 6, 5, 10, 4, -1, 2}};
extern const int ROWS;
extern const int COLS;
extern int maze[ROWS][COLS];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool valid(int r, int c)
{
    return r >= 0 && c >= 0 && r < ROWS && c < COLS;
}

int highest4Bits(int x)
{
    int bits = 0, temp = x;

    while (temp)
    {
        bits++;
        temp >>= 1;
    }

    if (bits <= 4)
        return x;

    return x >> (bits - 4);
}

int solve(int sr, int sc)
{

    const int INF = 1e9;

    vector<vector<int>> dist(ROWS, vector<int>(COLS, INF));

    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>
        pq;

    dist[sr][sc] = maze[sr][sc];
    pq.push({dist[sr][sc], {sr, sc}});

    while (!pq.empty())
    {

        int cost = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();

        if (cost != dist[r][c])
            continue;

        if (maze[r][c] == 0)
            return highest4Bits(cost);

        for (int i = 0; i < 4; i++)
        {

            int nr = r + dr[i];
            int nc = c + dc[i];

            if (!valid(nr, nc) || maze[nr][nc] == -1)
                continue;

            int newCost = cost + maze[nr][nc];

            if (newCost < dist[nr][nc])
            {
                dist[nr][nc] = newCost;
                pq.push({newCost, {nr, nc}});
            }
        }
    }

    return -1;
}

int main()
{

    int startRow, startCol;

    cout << "Enter starting row and column: ";
    cin >> startRow >> startCol;

    cout << "Answer = " << solve(startRow, startCol) << endl;

    return 0;
}


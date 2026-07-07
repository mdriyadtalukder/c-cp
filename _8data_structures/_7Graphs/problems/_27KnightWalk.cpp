// ekta ghora dise and target dise..ghorar oikhne jaite min koita step lgbe..
// ghora 2 step straight(for all straight top or bottom or right or left) jai then 1 step right or left e jbo. so on...ei 3 step ta mile 1 step hbe..
// BFS use krbo
#include <bits/stdc++.h>
using namespace std;
int row[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int col[8] = {1, -1, 1, -1, 2, 2, -2, -2};

bool valid(int i, int j, int n)
{
    return i >= 0 && j >= 0 && i < n && j < n;
}

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    //1 based indexing silo..tai 0 based banalam
    KnightPos[0]--;
    KnightPos[1]--;
    TargetPos[0]--;
    TargetPos[1]--;
    // base case
    if (TargetPos[0] == KnightPos[0] && TargetPos[1] == KnightPos[1])
        return 0;
    queue<pair<int, int>> q;
    vector<vector<bool>> chess(N, vector<bool>(N, 0));

    q.push({KnightPos[0], KnightPos[1]});
    chess[KnightPos[0]][KnightPos[1]] = 1; //1st ta jeta traversal hyse

    int step = 0;

    while (!q.empty())
    {
        int count = q.size(); //curent{i,j}

        while (count--)
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if (i == TargetPos[0] && j == TargetPos[1])
                return step;

            for (int k = 0; k < 8; k++)
            {
                int new_i = i + row[k];
                int new_j = j + col[k];

                if (valid(new_i, new_j, N) && !chess[new_i][new_j])//!chess ei cell ta jate traversal na thke
                {
                    chess[new_i][new_j] = 1;
                    q.push({new_i, new_j});
                }
            }
        }
        step++;
    }

    return -1;
}

/*
Knight Walk

Problem Statement:

Given an N × N chessboard, a Knight is placed at a
starting position.

You are also given a target position.

Find the minimum number of moves required
for the Knight to reach the target.

The Knight moves according to the standard
chess rules:

- 2 squares in one direction
- then 1 square perpendicular

A Knight has exactly 8 possible moves.

If the target cannot be reached,
return -1.

------------------------------------------------

Example 1:

Input:

N = 6

KnightPos = {4,5}

TargetPos = {1,1}

Output:

3

Explanation:

One shortest path is:

(4,5)
→ (2,4)
→ (3,2)
→ (1,1)

Total moves = 3

------------------------------------------------

Example 2:

Input:

N = 8

KnightPos = {1,1}

TargetPos = {1,1}

Output:

0

Explanation:

Knight is already at the destination.

------------------------------------------------

Example 3:

Input:

N = 8

KnightPos = {1,1}

TargetPos = {8,8}

Output:

6

Explanation:

The minimum number of Knight moves is 6.

------------------------------------------------

Constraints:

1 <= N <= 500

1 <= KnightPos[i], TargetPos[i] <= N

Expected Time Complexity:
O(N²)

Expected Auxiliary Space:
O(N²)

Approach:

1. Convert positions to 0-based indexing.
2. Start BFS from the Knight's position.
3. Store visited cells in a visited matrix.
4. From each cell, explore all 8 possible Knight moves.
5. Each BFS level represents one Knight move.
6. When the target is reached, return the current level.
7. If BFS finishes without reaching the target, return -1.
*/
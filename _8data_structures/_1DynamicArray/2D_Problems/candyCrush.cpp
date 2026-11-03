#include <bits/stdc++.h>
using namespace std;

// brute force
vector<vector<int>> candyCrush(vector<vector<int>> &board)
{
    int m = board.size();
    int n = board[0].size();

    bool shouldContinue = true;
    while (shouldContinue)
    {
        shouldContinue = false;
        vector<vector<bool>> crush(m, vector<bool>(n, false));

        // Mark horizontal runs of 3+
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n - 2; j++)
            {
                int val = board[i][j];
                if (val != 0 && val == board[i][j + 1] && val == board[i][j + 2])
                {
                    crush[i][j] = crush[i][j + 1] = crush[i][j + 2] = true;
                    shouldContinue = true;
                }
            }
        }

        // Mark vertical runs of 3+
        for (int i = 0; i < m - 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int val = board[i][j];
                if (val != 0 && val == board[i + 1][j] && val == board[i + 2][j])
                {
                    crush[i][j] = crush[i + 1][j] = crush[i + 2][j] = true;
                    shouldContinue = true;
                }
            }
        }

        // Crush marked cells
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (crush[i][j])
                {
                    board[i][j] = 0;
                }
            }
        }

        // Apply gravity column by column
        for (int j = 0; j < n; j++)
        {
            int writePos = m - 1;
            for (int i = m - 1; i >= 0; i--)
            {
                if (board[i][j] != 0)
                {
                    board[writePos][j] = board[i][j];
                    if (writePos != i)
                    {
                        board[i][j] = 0;
                    }
                    writePos--;
                }
            }
            while (writePos >= 0)
            {
                board[writePos][j] = 0;
                writePos--;
            }
        }
    }

    return board;
}

// optimal
vector<vector<int>> candyCrush2(vector<vector<int>> &board)
{
    int m = board.size();
    int n = board[0].size();

    bool shouldContinue = true;
    while (shouldContinue)
    {
        shouldContinue = false;

        // Mark horizontal runs by negating values
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n - 2; j++)
            {
                int val = abs(board[i][j]);
                if (val != 0 && val == abs(board[i][j + 1]) && val == abs(board[i][j + 2]))
                {
                    board[i][j] = -val;
                    board[i][j + 1] = -val;
                    board[i][j + 2] = -val;
                    shouldContinue = true;
                }
            }
        }

        // Mark vertical runs by negating values
        for (int i = 0; i < m - 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int val = abs(board[i][j]);
                if (val != 0 && val == abs(board[i + 1][j]) && val == abs(board[i + 2][j]))
                {
                    board[i][j] = -val;
                    board[i + 1][j] = -val;
                    board[i + 2][j] = -val;
                    shouldContinue = true;
                }
            }
        }

        // Crush and apply gravity
        for (int j = 0; j < n; j++)
        {
            int writePos = m - 1;
            for (int i = m - 1; i >= 0; i--)
            {
                if (board[i][j] > 0)
                {
                    board[writePos][j] = board[i][j];
                    if (writePos != i)
                    {
                        board[i][j] = 0;
                    }
                    writePos--;
                }
            }
            while (writePos >= 0)
            {
                board[writePos][j] = 0;
                writePos--;
            }
        }
    }

    return board;
}
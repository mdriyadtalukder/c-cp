#include <bits/stdc++.h>
using namespace std;

//brute force
bool validBox(vector<vector<char>>& board, int sr, int er, int sc, int ec)
{
    unordered_set<char> st;

    // Validate 3*3 box
    for(int i = sr; i <= er; i++)
    {
        for(int j = sc; j <= ec; j++)
        {
            if(board[i][j] == '.') continue;

            if(st.find(board[i][j]) != st.end())
                return false;

            st.insert(board[i][j]);
        }
    }

    return true;
}

bool isValidSudoku(vector<vector<char>>& board)
{
    // Validate rows
    for(int row = 0; row < 9; row++)
    {
        unordered_set<char> st;

        for(int col = 0; col < 9; col++)
        {
            if(board[row][col] == '.') continue;

            if(st.find(board[row][col]) != st.end())
                return false;

            st.insert(board[row][col]);
        }
    }

    // Validate columns
    for(int col = 0; col < 9; col++)
    {
        unordered_set<char> st;

        for(int row = 0; row < 9; row++)
        {
            if(board[row][col] == '.') continue;

            if(st.find(board[row][col]) != st.end())
                return false;

            st.insert(board[row][col]);
        }
    }

    // Validate 3*3 boxes
    for(int sr = 0; sr < 9; sr += 3)
    {
        int er = sr + 2;

        for(int sc = 0; sc < 9; sc += 3)
        {
            int ec = sc + 2;

            if(!validBox(board, sr, er, sc, ec))
                return false;
        }
    }

    return true;
}

//optimal
bool isValidSudoku2(vector<vector<char>>& board) {
    int rows[9] = {0}, cols[9] = {0}, boxes[9] = {0};

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') continue;

            // Bitmask for the current digit
            int mask = 1 << (board[r][c] - '1');
            int boxIdx = (r / 3) * 3 + (c / 3);

            // If bit is already set in any group, it's a duplicate
            if ((rows[r] & mask) ||
                (cols[c] & mask) ||
                (boxes[boxIdx] & mask)) {
                return false;
            }

            // Mark the digit as seen
            rows[r] |= mask;
            cols[c] |= mask;
            boxes[boxIdx] |= mask;
        }
    }

    return true;
}
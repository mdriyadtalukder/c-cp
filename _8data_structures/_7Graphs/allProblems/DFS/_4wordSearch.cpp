#include <bits/stdc++.h>
using namespace std;

// dfs(brute force)

bool dfs(vector<vector<char>> &board, string &word, int i, int j, int k)
{

    if (k == word.size())
        return true;

    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[k])
        return false;

    char temp = board[i][j];
    board[i][j] = '#';

    bool found = dfs(board, word, i + 1, j, k + 1) ||
                 dfs(board, word, i - 1, j, k + 1) ||
                 dfs(board, word, i, j + 1, k + 1) ||
                 dfs(board, word, i, j - 1, k + 1);

    board[i][j] = temp;

    return found;
}

bool exist(vector<vector<char>> &board, string word)
{

    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (dfs(board, word, i, j, 0))
                return true;
        }
    }

    return false;
}

// dfs(optimal)

bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size(), n = board[0].size();

    // Count character frequencies in the board
    int boardCount[128] = {};
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            boardCount[board[i][j]]++;
        }
    }

    // Check if the board has enough of each character
    int wordCount[128] = {};
    for (char c : word)
    {
        wordCount[c]++;
        if (wordCount[c] > boardCount[c])
        {
            return false;
        }
    }

    // Reverse the word if the first character is more common than the last
    if (boardCount[word[0]] > boardCount[word[word.length() - 1]])
    {
        reverse(word.begin(), word.end());
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (backtrack(board, word, i, j, 0))
            {
                return true;
            }
        }
    }
    return false;
}

bool backtrack(vector<vector<char>> &board, string &word, int i, int j, int index)
{
    if (index == (int)word.length())
    {
        return true;
    }
    if (i < 0 || i >= (int)board.size() || j < 0 || j >= (int)board[0].size() || board[i][j] != word[index])
    {
        return false;
    }

    char temp = board[i][j];
    board[i][j] = '#';

    bool found = backtrack(board, word, i + 1, j, index + 1) || backtrack(board, word, i - 1, j, index + 1) || backtrack(board, word, i, j + 1, index + 1) || backtrack(board, word, i, j - 1, index + 1);

    board[i][j] = temp;
    return found;
}

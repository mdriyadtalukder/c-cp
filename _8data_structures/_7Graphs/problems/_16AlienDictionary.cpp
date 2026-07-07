// abcd eita human dictionary order but alien dictionary alada like bdac order follow kre..
// onk words deoya thkbe order wise tar alien order ber krte hbe by kahns algo.
// adjaceny list banabo 1st then kahns algo apply krbo.
#include <bits/stdc++.h>
using namespace std;

string findOrder(vector<string> &dict)
{
    // K and N not given
    int N = dict.size();

    // mark used characters → this defines effective K
    vector<bool> used(26, false);
    int K = 0;

    for (int i = 0; i < N; i++)
    {
        for (char c : dict[i])
        {
            if (!used[c - 'a'])
            {
                used[c - 'a'] = true;
                K++; // count unique chars
            }
        }
    }

    // Adjacency list create karo
    vector<int> adj[26];
    vector<int> InDeg(26, 0);

    for (int i = 0; i < N - 1; i++)
    {
        string str1 = dict[i], str2 = dict[i + 1];
        int j = 0, k = 0;

        while (j < str1.size() && k < str2.size() && str1[j] == str2[k])
        {
            j++;
            k++;
        }
        // absc
        if (j == str1.size())
            continue;
        // abcf
        if (k == str2.size())
            return ""; // invalid case

        adj[str1[j] - 'a'].push_back(str2[k] - 'a');
        InDeg[str2[k] - 'a']++;
    }

    // Kahn's algorithm
    queue<int> q;

    for (int i = 0; i < 26; i++)
        if (InDeg[i] == 0 && used[i]) // only used chars
            q.push(i);

    string ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        ans += (char)('a' + node);

        for (int j = 0; j < adj[node].size(); j++)
        {
            InDeg[adj[node][j]]--;
            if (InDeg[adj[node][j]] == 0)
                q.push(adj[node][j]);
        }
    }

    return ans.size() == K ? ans : "";
}
/*
Alien Dictionary

Problem Statement:

There is a new alien language that uses the English lowercase letters,
but the order of the letters is different from the normal English alphabet.

You are given a dictionary of words that is already sorted
according to the rules of the alien language.

Your task is to determine one possible order of the characters
in the alien language.

If multiple valid orders exist, return any one of them.

If the given dictionary is invalid or no valid ordering exists,
return an empty string.

Input:
- dict: A list of words sorted according to the alien language.

Output:
- Return a string representing one valid ordering
  of the alien alphabet.
- Return "" if the dictionary is invalid.

Example 1:

Input:
dict = {
    "baa",
    "abcd",
    "abca",
    "cab",
    "cad"
}

Output:
"bdac"

Explanation:

Compare adjacent words:

"baa"  -> "abcd"  => b comes before a
"abcd" -> "abca"  => d comes before a
"abca" -> "cab"   => a comes before c
"cab"  -> "cad"   => b comes before d

One valid ordering is:

b -> d -> a -> c

Output:
"bdac"

--------------------------------------------

Example 2:

Input:
dict = {
    "abc",
    "ab"
}

Output:
""

Explanation:

The second word is a prefix of the first word.

A longer word cannot come before its own prefix,
so the dictionary is invalid.

--------------------------------------------

Constraints:

1 <= dict.size() <= 10^4
1 <= word.length <= 100
Words contain only lowercase English letters.

Expected Time Complexity:
O(N × L + K)

where
N = number of words
L = average word length
K = number of unique characters

Expected Auxiliary Space:
O(K)

Approach:

1. Compare every pair of adjacent words.
2. Find the first differing character.
3. Create a directed edge from the first character
   to the second character.
4. Compute indegrees of all characters.
5. Apply Kahn's Algorithm (Topological Sort).
6. If every unique character is processed,
   return the topological ordering.
7. Otherwise, return an empty string.
*/
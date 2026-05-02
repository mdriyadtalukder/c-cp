// string of array thkbe tader modde common prefix konta like
//[coding,code,coder,coders]-->longest common prefix holo "cod".

#include <iostream>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++; // important
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans)
    {
        TrieNode *curr = root;

        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if (curr->childCount == 1)
            {
                ans.push_back(ch);
                int index = ch - 'a';
                curr = curr->children[index];
            }
            else
            {
                break;
            }

            if (curr->isTerminal)
                break;
        }
    }
};

string longestCommonPrefix(vector<string> &arr)
{
    Trie *t = new Trie();

    // insert all words
    for (int i = 0; i < arr.size(); i++)
    {
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);

    return ans;
}

int main()
{
    vector<string> arr = {"flower", "flow", "flight"};

    string result = longestCommonPrefix(arr);

    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}
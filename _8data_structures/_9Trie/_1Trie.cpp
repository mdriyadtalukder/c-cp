#include <iostream>
using namespace std;
/* deletion

1. Go till last character
2. Unmark isTerminal
3. Check:
        # If node has children → STOP (shared prefix)
        # If no children → DELETE node
4. Backtrack and clean unused nodes



| Operation | Time Complexity | Space Complexity         |
| --------- | --------------- | ------------------------ |
| Insert    | O(L)            | O(L)                     |
| Search    | O(L)            | O(L) (rec) / O(1) (iter) |
| Delete    | O(L)            | O(L)                     |

*/
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
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
    // adding
    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // assuming lowercase letters
        int index = word[0] - 'a';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // absent
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion (IMPORTANT: always call)
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    // deletion
    bool removeUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            // word end
            if (root->isTerminal)
            {
                root->isTerminal = false;

                // check if node has no children
                for (int i = 0; i < 26; i++)
                {
                    if (root->children[i] != NULL)
                        return false; // can't delete node
                }
                return true; // delete this node
            }
            return false;
        }

        int index = word[0] - 'a';
        TrieNode *child = root->children[index];

        if (child == NULL)
            return false; // word not found

        bool shouldDeleteChild = removeUtil(child, word.substr(1));

        // delete child node if needed
        if (shouldDeleteChild)
        {
            delete child;
            root->children[index] = NULL;

            // check if current node can be deleted
            if (root->isTerminal)
                return false;

            for (int i = 0; i < 26; i++)
            {
                if (root->children[i] != NULL)
                    return false;
            }
            return true;
        }

        return false;
    }

    void removeWord(string word)
    {
        removeUtil(root, word);
    }

    // searching
    bool searchUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        // recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();

    t->insertWord("abc");
    t->insertWord("abcd");

    cout << "abc: " << t->searchWord("abc") << endl;   // 1
    cout << "abcd: " << t->searchWord("abcd") << endl; // 1

    t->removeWord("abc");

    cout << "After deleting abc:" << endl;
    cout << "abc: " << t->searchWord("abc") << endl;   // 0
    cout << "abcd: " << t->searchWord("abcd") << endl; // 1

    return 0;
}
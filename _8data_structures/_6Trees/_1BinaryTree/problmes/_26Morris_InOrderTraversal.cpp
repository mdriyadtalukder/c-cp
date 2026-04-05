/*1. If Left Child Doesn't Exist
Action: "Note down the data" (Visit/print the current node).
Move: "Move to Right" child of the current node.

2. If Left Part Exists

Case A: If Left Subtree is Not Traversed
*not traversal
*create link
*move to left

Case B: Else (Already Traversed / Link Exists)
Action: "Remove the link"
Action: "Note down the data"
Move: "Move to Right."
*/
// TC=O(n) bt SC=O(1)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

vector<int> morrisInorder(Node *root)
{
    vector<int> ans;

    while (root)
    {
        // Case 1: no left child
        if (!root->left)
        {
            ans.push_back(root->data);
            root = root->right;
        }
        else
        {
            // find inorder predecessor
            Node *curr = root->left;

            while (curr->right && curr->right != root)
            {
                curr = curr->right;
            }

            // make thread (connection)
            if (curr->right == NULL)
            {
                curr->right = root;
                root = root->left;
            }
            else
            {
                // remove thread(connection)
                curr->right = NULL;
                ans.push_back(root->data); // eita just age tai hbe..
                root = root->right;
            }
        }
    }

    return ans;
}
int main() {}
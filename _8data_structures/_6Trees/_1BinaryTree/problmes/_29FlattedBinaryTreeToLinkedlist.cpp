// preOrder tree to single linkedlist
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

void flatten(Node *root)
{
    while (root)
    {
        // Case 1: no left child
        if (!root->left)
        {
            root = root->right;
        }
        else
        {
            // find rightmost node of left subtree
            Node *curr = root->left;

            while (curr->right)
            {
                curr = curr->right;
            }

            // attach original right subtree
            curr->right = root->right;

            // move left subtree to right
            root->right = root->left;
            root->left = NULL;

            // move forward
            root = root->right;
        }
    }
}
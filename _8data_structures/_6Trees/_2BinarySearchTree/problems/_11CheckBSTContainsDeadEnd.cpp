// emn leaf node ase nki jeta te r kono node attach kra jbe na..all value will be unique

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Helper function
bool Dead(Node *root, int lower, int upper)
{
    if (!root)
        return false;

    // leaf node
    if (!root->left && !root->right)
    {
        if (root->data - lower == 1 && upper - root->data == 1)
            return true;
        else
            return false;
    }

    return Dead(root->left, lower, root->data) ||
           Dead(root->right, root->data, upper);
}

// Main function
bool isDeadEnd(Node *root)
{
    return Dead(root, 0, INT_MAX);
}

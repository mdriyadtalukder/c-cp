/*
inOrder ber krbo then dekhbo accending order a ase nki
jdi thke then it is BST..eta strict accending order hote hbe..mane 2 ta elem soman hoya jbe na.
//nicher solution more optimizing than above one..eitao inorder follow kre pre check kre.
*/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool BST(Node *root, int &prev)
{
    if (!root)
        return true;

    if (!BST(root->left, prev))
        return false;

    if (root->data <= prev)
        return false;

    prev = root->data;

    return BST(root->right, prev);
}

// Function to check whether a Binary Tree is BST
bool isBST(Node *root)
{
    int prev = INT_MIN;
    return BST(root, prev);
}
int main() {}
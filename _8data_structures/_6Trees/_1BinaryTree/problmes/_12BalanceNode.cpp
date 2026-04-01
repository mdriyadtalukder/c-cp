#include <bits/stdc++.h>
using namespace std;
// every node er khetre -1<=leftHeight-rightHeight<=1 hote hbe..
class Node
{
public:
    int data;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

// Build Tree (DFS style input)
Node *BinaryTree()
{
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    Node *temp = new Node(x);

    temp->left = BinaryTree();
    temp->right = BinaryTree();

    return temp;
}

// Height + Balance check
int height(Node *root, bool &valid)
{
    if (!root)
        return 0;

    int l = height(root->left, valid);
    int r = height(root->right, valid);

    if (abs(l - r) > 1)
        valid = false;

    return 1 + max(l, r);
}

bool isBalanced(Node *root)
{
    bool valid = true;
    height(root, valid);
    return valid;
}

int main()
{
    Node *root = BinaryTree();

    cout << isBalanced(root);

    return 0;
}
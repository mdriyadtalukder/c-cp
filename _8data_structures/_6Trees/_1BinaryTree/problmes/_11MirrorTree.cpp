#include <bits/stdc++.h>
using namespace std;

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

// Build tree (DFS style input)
Node *BinaryTree()
{
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    Node *temp = new Node(x);

    cout << "Enter left child of " << x << ": ";
    temp->left = BinaryTree();

    cout << "Enter right child of " << x << ": ";
    temp->right = BinaryTree();

    return temp;
}

// Mirror Tree
void Mirror(Node *root)
{
    if (root == NULL)
        return;

    swap(root->left, root->right);

    Mirror(root->left);
    Mirror(root->right);
}

int main()
{
    cout << "Enter root node: ";
    Node *root = BinaryTree();

    Mirror(root);

    return 0;
}
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

// Build Tree (DFS style)
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
int Preorder(Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(Preorder(root->left), Preorder(root->right));
}

int main()
{
    cout << "Enter root node: ";
    Node *root = BinaryTree();

    cout << "Height: " << Preorder(root);

    return 0;
}
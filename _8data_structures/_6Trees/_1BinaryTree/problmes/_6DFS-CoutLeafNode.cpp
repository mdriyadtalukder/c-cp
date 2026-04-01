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
void Preorder(Node *root, int &c)
{
    if (root == NULL)
        return;

    if (!root->left && !root->right)
    {
        c++; // count leaf node
        return;
    }

    Preorder(root->left, c);
    Preorder(root->right, c);

    // recursion

    // if (!root->left && !root->right)

    //     return 1;
    // return Preorder(root->left) + Preorder(root->right);
}

int main()
{
    cout << "Enter root node: ";
    Node *root = BinaryTree();

    int c = 0;
    Preorder(root, c);

    cout << "Total Leaf Nodes: " << c;

    return 0;
}
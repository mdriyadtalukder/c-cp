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
Node* BinaryTree()
{
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    Node* temp = new Node(x);

    cout << "Enter left child of " << x << ": ";
    temp->left = BinaryTree();

    cout << "Enter right child of " << x << ": ";
    temp->right = BinaryTree();

    return temp;
}

// Postorder Traversal---problem--TC=SC=O(n)
void Postorder(Node* root)
{
    if (root == NULL) return;

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    cout << "Enter root node: ";
    Node* root = BinaryTree();

    cout << "Postorder Traversal: ";
    Postorder(root);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// Binary Tree using DFS (Depth-First Search)..TC=O(n)..SC=max height of tree O(n)
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

Node *BinaryTree()
{
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    Node *temp = new Node(x);

    cout << "Enter the left child of " << x << " ";
    temp->left = BinaryTree();

    cout << "Enter the right child of " << x << " ";
    temp->right = BinaryTree();

    return temp; // left/right side's adress --to go to previous node's right or left side
}

int main()
{
    cout << "Enter the root Node: ";
    Node *root;
    root = BinaryTree();
}
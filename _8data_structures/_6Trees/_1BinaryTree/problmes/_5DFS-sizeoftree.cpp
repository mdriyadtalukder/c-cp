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

    c++; // count current node.
    // c += root->data; //.sum of all node same as it..

    Preorder(root->left, c);
    Preorder(root->right, c);
    // return 1+ Preorder(root->left)+ Preorder(root->right)--for that fun will be int--for count
    // return root->data+ Preorder(root->left)+ Preorder(root->right)--for that fun will be int--for sum
}

int main()
{
    cout << "Enter root node: ";
    Node *root = BinaryTree();

    int c = 0;
    Preorder(root, c);

    cout << "Total Nodes: " << c;

    return 0;
}
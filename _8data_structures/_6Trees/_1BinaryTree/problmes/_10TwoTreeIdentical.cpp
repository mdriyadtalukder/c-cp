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

// Check if two trees are identical
bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
        return true;

    if (r1 == NULL || r2 == NULL)
        return false;

    if (r1->data != r2->data)
        return false;

    return isIdentical(r1->left, r2->left) &&
           isIdentical(r1->right, r2->right);
}

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

int main()
{
    cout << "Enter first tree root: ";
    Node *root1 = BinaryTree();

    cout << "Enter second tree root: ";
    Node *root2 = BinaryTree();

    if (isIdentical(root1, root2))
        cout << "Trees are Identical";
    else
        cout << "Trees are Not Identical";

    return 0;
}
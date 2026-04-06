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

// Insert function
Node *insert(Node *root, int target)
{
    // base case
    if (!root)
    {
        Node *temp = new Node(target);
        return temp;
    }

    if (target < root->data)
    { // Left side
        root->left = insert(root->left, target);
    }
    else
    { // Right side
        root->right = insert(root->right, target);
    }

    return root;
}
bool search(Node *root, int target)
{
    if (!root)
        return 0;
    if (root->data == target)
        return 1;
    if (root->data > target)
    {
        return search(root->left, target);
    }
    else
        return search(root->right, target);
}

Node *deleteNode(Node *root, int target)
{
    // base condition
    if (!root)
        return NULL;

    if (root->data > target)
    {
        root->left = deleteNode(root->left, target);
        return root;
    }
    else if (root->data < target)
    {
        root->right = deleteNode(root->right, target);
        return root;
    }
    else
    {
        // case 1: no child
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }

        // case 2: one child (left)
        else if (!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // case 2: one child (right)
        else if (!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // case 3: two children
        else
        {
            // find the greatest element from left subtree
            Node *child = root->left;
            Node *parent = root;

            // go to rightmost node
            while (child->right)
            {
                parent = child;
                child = child->right;
            }

            // if successor is not direct child
            if (parent != root)
            {
                parent->right = child->left; //root->18....parent-12->(right-14(child)->(eitar left 13))
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else
            {
                // direct left child case
                child->right = root->right;
                delete root;
                return child;
            }
        }
    }
}

// Inorder traversal (for checking)
void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    int arr[] = {6, 3, 17, 5, 11, 18, 2, 1, 20, 14};
    Node *root = NULL;
    for (int i = 0; i < 10; i++)
        root = insert(root, arr[i]);
    cout << search(root, 1451) << endl;
    // Print BST (sorted order)
    inorder(root);

    return 0;
}
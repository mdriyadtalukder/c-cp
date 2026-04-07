// 6 no er motoi just post order k reverse theke krte hbe..reverse krte hbe r ki..last theke suru hy kaj ta..
// just right part age hbe and left part pore..
#include <bits/stdc++.h>
using namespace std;

// Structure of Node
struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Build BST from postorder using range method
Node *BST(int post[], int &index, int lower, int upper)
{
    // base case
    if (index < 0 || post[index] < lower || post[index] > upper)
        return NULL;

    // create root
    Node *root = new Node(post[index--]);

    // IMPORTANT: build right first
    root->right = BST(post, index, root->data, upper);

    // then left
    root->left = BST(post, index, lower, root->data);

    return root;
}

Node *constructTree(int post[], int size)
{
    int index = size - 1;
    return BST(post, index, INT_MIN, INT_MAX);
}

// inorder traversal (to verify BST)
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
    int post[] = {1, 7, 5, 12, 10, 8};
    int size = sizeof(post) / sizeof(post[0]);

    Node *root = constructTree(post, size);

    cout << "Inorder: ";
    inorder(root);

    return 0;
}
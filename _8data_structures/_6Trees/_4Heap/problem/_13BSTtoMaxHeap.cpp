// BST theke max heap banate hbe
// 2 condition thkbe--1:parent>childe;2: left subtree<right subtree..ei type max heap banate hbe.
// inorder traversal kre ans array sort krbo
// sorted array te 1st e left e vorbo then right e then last ta top node e..choto gula then majari gula then boro ta..eita Holo postOrder-LRN
// then postOrder-LRN
//TC=O(n)
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// inorder traversal (store sorted values)
void inorder(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

// postorder traversal (assign values)
void postOrder(Node *root, vector<int> &ans, int &index)
{
    if (!root)
        return;

    // left
    postOrder(root->left, ans, index);

    // right
    postOrder(root->right, ans, index);

    // node
    root->data = ans[index];
    index++;
}

// main function
void convertToMaxHeapUtil(Node *root)
{
    // inorder traversal
    vector<int> ans;
    inorder(root, ans);

    // postorder traversal
    int index = 0;
    postOrder(root, ans, index);
}
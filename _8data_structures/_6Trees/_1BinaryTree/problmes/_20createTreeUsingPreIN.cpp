#include <bits/stdc++.h>
using namespace std;
// pre ta order bole..first theke...always 1st e left e khujbo. and in te direction root er bam pash er gula left and right gula right for each node
//..eita eveytime check krbo..sob unique elem hbe..
//left will be instart,pos-1...right->pos+1,inEnd..
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Find element in inorder
int Find(int in[], int target, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == target)
            return i;
    }
    return -1;
}

// Build tree using preorder + inorder
Node *Tree(int in[], int pre[], int InStart, int InEnd, int index)
{
    if (InStart > InEnd)
        return NULL;

    // Create root
    Node *root = new Node(pre[index]);

    // Find root in inorder
    int pos = Find(in, pre[index], InStart, InEnd);

    // Left subtree
    root->left = Tree(in, pre, InStart, pos - 1, index + 1);

    // Right subtree
    root->right = Tree(in, pre, pos + 1, InEnd,
                       index + (pos - InStart) + 1);

    return root;
}

// Print inorder (to verify)
void printInorder(Node *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    int in[] = {4, 2, 5, 1, 6, 3};
    int pre[] = {1, 2, 4, 5, 3, 6};

    int n = 6;

    Node *root = Tree(in, pre, 0, n - 1, 0);

    cout << "Inorder of constructed tree: ";
    printInorder(root);

    return 0;
}
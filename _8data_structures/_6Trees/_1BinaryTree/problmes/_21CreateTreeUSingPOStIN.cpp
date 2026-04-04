// post ta order bole..last theke..always 1st e right e khujbo. and in te direction root er bam pash er gula left and right gula right for each node
//..eita eveytime check krbo..sob unique elem hbe..
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Find in inorder
int Find(int in[], int target, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == target)
            return i;
    }
    return -1;
}

// Build tree using postorder + inorder
Node* Tree(int in[], int post[], int InStart, int InEnd, int index)
{
    if (InStart > InEnd)
        return NULL;

    // root from postorder
    Node* root = new Node(post[index]);

    int pos = Find(in, post[index], InStart, InEnd);

    // RIGHT subtree first (important!)
    root->right = Tree(in, post, pos + 1, InEnd, index - 1);

    // LEFT subtree
    root->left = Tree(in, post, InStart, pos - 1,
                      index - (InEnd - pos) - 1);

    return root;
}

// Print inorder to verify
void printInorder(Node* root)
{
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    int in[]   = {4, 2, 5, 1, 6, 3};
    int post[] = {4, 5, 2, 6, 3, 1};

    int n = 6;

    Node* root = Tree(in, post, 0, n - 1, n - 1);

    cout << "Inorder of constructed tree: ";
    printInorder(root);

    return 0;
}
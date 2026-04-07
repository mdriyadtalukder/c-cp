// 2ta node deoya thakbe and tader purbo purush like baba,dada,tar baba etc..
// eder modde 2jn er e ancestor and sob cheye niche seita konta.
// 2ta node er value milate thkbo j kon side e jbe..tokhni different side e jbe tokhni stop krbo and ager node ta ancestor hbe.

#include <bits/stdc++.h>
using namespace std;

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

// Insert into BST
Node *insert(Node *root, int val)
{
    if (!root)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// LCA function (your logic)
Node *LCA(Node *root, int n1, int n2) //node *n1 hole n1->data hbe
{
    if (!root)
        return NULL;

    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);

    else if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);

    else
        return root;
}

int main()
{
    Node *root = NULL;

    // Build BST
    vector<int> v = {20, 10, 30, 5, 15};
    for (int x : v)
        root = insert(root, x);

    int n1 = 5, n2 = 15;

    Node *ans = LCA(root, n1, n2);

    if (ans)
        cout << "LCA: " << ans->data << endl;
    else
        cout << "LCA not found\n";

    return 0;
}
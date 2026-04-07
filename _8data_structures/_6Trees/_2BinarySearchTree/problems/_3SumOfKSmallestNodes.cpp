/*
BF-.inorder ber kre array te store krbo then 1st 3 tar ba kth er sum ber krbo
k=3;so sobcheye choto 3 tar sum dibo
er jnno inorder er 1st 3ta value er sum dibo then inorder stop kre dibo..
*/
#include <bits/stdc++.h>
using namespace std;

// Definition of Node
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

// Insert into BST (for testing)
Node *insert(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Kth smallest using inorder traversal
void KSum(Node *root, int &sum, int &k)
{
    if (!root)
        return;

    // Inorder Traversal
    KSum(root->left, sum, k);

    k--;
    if (k >= 0)
    {
        sum += root->data;
    }

    if (k < 0)
        return;

    KSum(root->right, sum, k);
}

int main()
{
    Node *root = NULL;

    int n, k;
    cin >> n >> k;

    // Build BST
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int sum = 0;

    KSum(root, sum, k);
   // return sum;

    cout << sum << endl;

    return 0;
}
//l=60,h=70..60-70 er vitor er elem dite hbe in sorted way
//2ta node er value milate thkbo j kon side e jbe.
//jdi eder range e thke then left(2 tar theke boro hole) or right() e jbo and inOrder way print krbo

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Insert in BST
Node* insert(Node* root, int val)
{
    if (!root) return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find nodes in range
void find(Node* root, int low, int high, vector<int>& ans)
{
    if (!root) return;

    // go left
    if (root->data > low)
        find(root->left, low, high, ans);

    // include current node
    if (root->data >= low && root->data <= high)
        ans.push_back(root->data);

    // go right
    if (root->data < high)
        find(root->right, low, high, ans);
}

// Main function
vector<int> printNearNodes(Node *root, int low, int high)
{
    vector<int> ans;
    find(root, low, high, ans);
    return ans;
}

int main()
{
    Node* root = NULL;

    vector<int> v = {20, 10, 30, 5, 15, 25, 35};
    for (int x : v)
        root = insert(root, x);

    int low = 10, high = 25;

    vector<int> res = printNearNodes(root, low, high);

    for (int x : res)
        cout << x << " ";

    return 0;
}
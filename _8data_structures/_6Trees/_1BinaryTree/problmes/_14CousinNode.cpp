/*
1.same level e hbe but parent alada.
*/

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

// check if same parent (siblings)
bool parent(Node *root, int a, int b)
{
    if (!root)
        return false;

    if (root->left && root->right)
    {
        if (root->left->data == a && root->right->data == b)
            return true;

        if (root->left->data == b && root->right->data == a)
            return true;
    }

    if (parent(root->left, a, b))
        return true;
    if (parent(root->right, a, b))
        return true;

    return false;
}

// check cousins
bool isCousins(Node *root, int a, int b)
{
    if (!root)
        return false;

    queue<Node *> q;
    q.push(root);

    int l1 = -1, l2 = -1;
    int level = 0;

    while (!q.empty())
    {
        int n = q.size();

        while (n--)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->data == a)
                l1 = level;

            if (temp->data == b)
                l2 = level;

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
        level++;
        // if only one found → not cousins
        if (l1 != l2)
            return 0;

        // if both found at same level → stop
        if (l1 != -1 && l2 != -1)
            break;
    }

    // same level but different parent
    return !parent(root, a, b);
}

int main()
{
    // Example usage (you can change input method)
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    cout << isCousins(root, 4, 3);

    return 0;
}
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

// Build Tree (optional if needed for testing)
Node *BinaryTree()
{
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    Node *temp = new Node(x);

    temp->left = BinaryTree();
    temp->right = BinaryTree();

    return temp;
}

// Iterative Preorder Traversal
vector<int> preorder(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    stack<Node *> s;
    s.push(root);

    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();

        ans.push_back(temp->data);

        // push right first
        if (temp->right)
            s.push(temp->right);

        // then push left
        if (temp->left)
            s.push(temp->left);
    }

    return ans;
}

int main()
{
    Node *root = BinaryTree();

    vector<int> ans = preorder(root);

    for (int x : ans)
        cout << x << " ";

    return 0;
}
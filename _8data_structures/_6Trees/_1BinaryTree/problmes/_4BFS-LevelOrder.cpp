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

// Build Binary Tree (Level-wise input)
Node *buildTree()
{
    int x;
    cout << "Enter root: ";
    cin >> x;

    if (x == -1)
        return NULL;

    Node *root = new Node(x);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int l, r;

        cout << "Enter left child of " << temp->data << ": ";
        cin >> l;
        if (l != -1)
        {
            temp->left = new Node(l);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->data << ": ";
        cin >> r;
        if (r != -1)
        {
            temp->right = new Node(r);
            q.push(temp->right);
        }
    }

    return root;
}

// Level Order Traversal (BFS)---TC=SC=(n/2)+1=O(n)..last er node gula hy total node/2+1;
vector<int> levelOrder(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        ans.push_back(temp->data);

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    return ans;
}

int main()
{
    Node *root = buildTree();

    vector<int> result = levelOrder(root);

    cout << "Level Order Traversal: ";
    for (int x : result)
        cout << x << " ";

    return 0;
}
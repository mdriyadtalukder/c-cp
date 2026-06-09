#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
Node *createTree()
{
    int x;
    cin >> x;
    if (x == -1)
    {
        return NULL;
    }
    Node *root = new Node(x);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int l, r;
        cin >> l;
        if (l != -1)
        {
            temp->left = new Node(l);
            q.push(temp->left);
        }
        cin >> r;
        if (r != -1)
        {
            temp->right = new Node(r);
            q.push(temp->right);
        }
    }
    return root;
};
void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}
int main()
{
    Node *root = createTree();
    levelOrder(root);
}
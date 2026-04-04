#include <bits/stdc++.h>
using namespace std;
// 2 ta stack banabo..left ot right ba 1 no stack e root node dibo then er child 2n stack e dibo er eder child 1 no e dibo..so on
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

// Build Tree
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

// Zigzag Traversal
vector<int> zigzagTraversal(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    stack<Node *> s1, s2;

    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {
        // Left to Right
        while (!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();

            ans.push_back(temp->data);

            if (temp->left)
                s2.push(temp->left);

            if (temp->right)
                s2.push(temp->right);
        }

        // Right to Left
        while (!s2.empty())
        {
            Node *temp = s2.top();
            s2.pop();

            ans.push_back(temp->data);

            if (temp->right)
                s1.push(temp->right);

            if (temp->left)
                s1.push(temp->left);
        }
    }

    return ans;
}

int main()
{
    Node *root = BinaryTree();

    vector<int> ans = zigzagTraversal(root);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// every level er 1st left side er value nibe..same concept as right side
// 1-15 all O(n)
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

// Left View
vector<int> leftView(Node *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        // first node of this level
        ans.push_back(q.front()->data);

        while (n--)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);

            if (temp->right) //in right view eita upore hbe and left ta niche hbe just
                q.push(temp->right);
        }
    }

    return ans;
}

int main()
{
    Node *root = BinaryTree();

    vector<int> ans = leftView(root);

    return 0;
}

/*// using DFS Left View helper
void Lview(Node *root, int level, vector<int>& ans)
{
    if (!root)
        return;

    // first node at this level
    if (level == ans.size())
        ans.push_back(root->data);

    Lview(root->left, level + 1, ans);
    Lview(root->right, level + 1, ans); //in right view eita upore hbe and left ta niche hbe just
}

// Main Left View function
vector<int> leftView(Node *root)
{
    vector<int> ans;

    if (!root)
        return ans;

    Lview(root, 0, ans);

    return ans;
}

*/
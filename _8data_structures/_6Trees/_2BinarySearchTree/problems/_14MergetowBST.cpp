// 2ta BST er sob elem ekta vector e borbo then seita sort kre return krbo
// optimal->2ta vector nibo then oi 2 tai inorder kre 2 ta tree er value boshabo.
//.then 2 ta compare kre ans vector e bore return krbo.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void inorder(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

vector<int> merge(Node *root1, Node *root2)
{
    vector<int> ans1;
    vector<int> ans2;

    inorder(root1, ans1);
    inorder(root2, ans2);

    vector<int> ans;
    int i = 0, j = 0;

    while (i < ans1.size() && j < ans2.size())
    {
        if (ans1[i] < ans2[j])
            ans.push_back(ans1[i++]);
        else
            ans.push_back(ans2[j++]);
    }

    while (i < ans1.size())
        ans.push_back(ans1[i++]);

    while (j < ans2.size())
        ans.push_back(ans2[j++]);

    return ans;
}

/* iterator way
vector<int> merge(Node *root1, Node *root2)
{
    stack<Node*> s1, s2;
    vector<int> ans;

    while (root1 || root2 || !s1.empty() || !s2.empty())
    {
        // push left of both trees
        while (root1)
        {
            s1.push(root1);
            root1 = root1->left;
        }
        while (root2)
        {
            s2.push(root2);
            root2 = root2->left;
        }

        // decide which stack to process
        if (s2.empty() || (!s1.empty() && s1.top()->data <= s2.top()->data))
        {
            root1 = s1.top();
            s1.pop();
            ans.push_back(root1->data);
            root1 = root1->right;
        }
        else
        {
            root2 = s2.top();
            s2.pop();
            ans.push_back(root2->data);
            root2 = root2->right;
        }
    }

    return ans;
}
*/
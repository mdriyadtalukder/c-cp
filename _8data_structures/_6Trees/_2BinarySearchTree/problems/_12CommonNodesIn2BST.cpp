// 2 ta BST er modde common value gula dibo output
// left er sob elem k stack e dao
// then seigula pop ..like compare kro 2nd tree er oi ele er shthe jdi mile print kro..then pop..na milleo pop hbe
// jegula pop krso oigular right side e giye sob left side gula stack e dukao
// so on in 3 steps
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

vector<int> findCommon(Node *root1, Node *root2)
{
    vector<int> ans;
    stack<Node *> s1, s2;

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

    while (!s1.empty() && !s2.empty())
    {
        // equal
        if (s1.top()->data == s2.top()->data)
        {
            ans.push_back(s1.top()->data);

            root1 = s1.top()->right;
            s1.pop();

            root2 = s2.top()->right;
            s2.pop();
        }

        // s1 > s2
        else if (s1.top()->data > s2.top()->data)
        {
            root2 = s2.top()->right;
            s2.pop();
        }

        // s2 > s1
        else
        {
            root1 = s1.top()->right;
            s1.pop();
        }

        // all left push again
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
    }

    return ans;
}
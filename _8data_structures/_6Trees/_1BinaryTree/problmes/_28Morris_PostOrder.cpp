// same pre er moto just pre er left gula right krbo and right gula left krbo then reverse krbo..
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

vector<int> postOrder(Node *root)
{
    vector<int> ans;

    while (root)
    {
        // Case 1: no right child
        if (!root->right)
        {
            ans.push_back(root->data);
            root = root->left;
        }
        else
        {
            Node *curr = root->right;

            // find predecessor (leftmost in right subtree)
            while (curr->left && curr->left != root)
            {
                curr = curr->left;
            }

            if (curr->left == NULL)
            {
                // create thread
                ans.push_back(root->data); // NRL
                curr->left = root;
                root = root->right;
            }
            else
            {
                // remove thread
                curr->left = NULL;
                root = root->left;
            }
        }
    }

    // reverse to get LRN (postorder)
    reverse(ans.begin(), ans.end());

    return ans;
}
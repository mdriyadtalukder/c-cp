// j subtree er max sum hbe oitai dibo
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};
class Box
{
public:
    int sum, min, max;
    bool BST;

    Box()
    {
        BST = true;
        sum = 0;
        min = INT_MAX;
        max = INT_MIN;
    }
};

class Solution
{
public:
    Box *find(TreeNode *root, int &sum)
    {
        if (!root)
            return new Box();

        Box *left = find(root->left, sum);
        Box *right = find(root->right, sum);

        if (left->BST && right->BST &&
            left->max < root->val && root->val < right->min)
        {
            Box *curr = new Box();

            curr->BST = true;
            curr->sum = left->sum + right->sum + root->val;

            curr->min = min(root->val, left->min);
            curr->max = max(root->val, right->max);

            sum = max(sum, curr->sum);

            return curr;
        }
        else
        {
            Box *curr = new Box();
            curr->BST = false;
            return curr;
        }
    }

    int maxSumBST(TreeNode *root)
    {
        int sum = 0;
        find(root, sum);
        return sum;
    }
};
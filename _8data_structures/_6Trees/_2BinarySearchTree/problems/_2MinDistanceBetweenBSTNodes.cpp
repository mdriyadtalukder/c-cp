/*
pre er shthe inorder er 1st node er shthe substract kre ans a dukabo..
then curr node er value pre te boshabo then next node  er shthe pre er substract krbo..jdi choto hy tahole ans e dukabo..
so on..
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void minDist(TreeNode *root, int &prev, int &ans)
{
    if (!root)
        return;

    minDist(root->left, prev, ans);

    if (prev != INT_MIN)
        ans = min(ans, root->val - prev);

    prev = root->val;

    minDist(root->right, prev, ans);
}

// wrapper function
int getMinimumDifference(TreeNode *root)
{
    int prev = INT_MIN;
    int ans = INT_MAX;

    minDist(root, prev, ans);

    return ans;
}
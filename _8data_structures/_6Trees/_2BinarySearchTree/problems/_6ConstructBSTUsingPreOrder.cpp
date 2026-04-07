// 1st node hbe intmin to intmax er modde value..then left side check krbo intmin -currect node value(for all left's left)
// and right value current node value to previous node value..so on
// for all right's right->current node value to intmax..and left hbe intmin to current node

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
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

TreeNode *BST(vector<int> &preorder, int &index, int lower, int upper)
{
    // base case
    if (index >= preorder.size() || preorder[index] < lower || preorder[index] > upper)
        return NULL;

    // create root
    TreeNode *root = new TreeNode(preorder[index++]);

    // left subtree
    root->left = BST(preorder, index, lower, root->val);

    // right subtree
    root->right = BST(preorder, index, root->val, upper);

    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int index = 0;
    return BST(preorder, index, INT_MIN, INT_MAX);
}

// helper: inorder print (to check BST)
void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    TreeNode *root = bstFromPreorder(preorder);

    cout << "Inorder: ";
    inorder(root); // should print sorted order

    return 0;
}
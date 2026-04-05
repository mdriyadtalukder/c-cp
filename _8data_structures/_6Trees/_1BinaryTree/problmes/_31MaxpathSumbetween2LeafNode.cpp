// 2 ta leaf node or special node er path max path sum
/*
        4
       / \
      2   3
     / \
    5   7

    5,7,3 are special or leaf node..
    so 5&7 er path sum=5+2+7=14
    so 5&3 er path sum=5+2+4+3=14
    so 7&3 er path sum=7+2+4+3=16
    so max sum 16..
    in other 4 er modde max value ta return krbo like 5 and -7..so 5+2 return krto in 4..

*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// helper function
int PathSum(Node *root, int &sum)
{
    if(!root) return 0;

    // leaf node
    if(!root->left && !root->right)
        return root->data;

    int left = PathSum(root->left, sum);
    int right = PathSum(root->right, sum);

    // both children exist
    if(root->left && root->right)
    {
        sum = max(sum, root->data + left + right);
        return root->data + max(left, right);
    }

    // only one child exists
    if(root->left)
        return root->data + left;
    else
        return root->data + right;
}

// main function
int maxPathSum(Node* root) 
{
    int sum = INT_MIN;

    int val = PathSum(root, sum);

    // if root has both children → valid leaf-to-leaf path exists
    if(root->left && root->right)
        return sum;

    // otherwise single path (like skew tree)
    return max(sum, val);
}
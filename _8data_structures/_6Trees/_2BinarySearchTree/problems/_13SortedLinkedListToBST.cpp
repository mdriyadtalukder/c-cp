// sorted LL deoya thkbe ..oitar mid ber krbo and root er value dibo then left side gula left side e
// r right side gula right side e diye eki kaj krte thkbo..
// balance hote hbe..means -<=l-r<=1;
#include <bits/stdc++.h>
using namespace std;

struct LNode
{
    int data;
    LNode *next;
};

struct TNode
{
    int data;
    TNode *left;
    TNode *right;

    TNode(int x)
    {
        data = x;
        left = right = NULL;
    }
};

TNode *BuildBST(vector<int> &Tree, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = start + (end - start + 1) / 2; // FIXED

    TNode *root = new TNode(Tree[mid]);

    root->left = BuildBST(Tree, start, mid - 1);
    root->right = BuildBST(Tree, mid + 1, end);

    return root;
}

TNode *sortedListToBST(LNode *head)
{
    vector<int> Tree;

    while (head)
    {
        Tree.push_back(head->data);
        head = head->next;
    }

    return BuildBST(Tree, 0, Tree.size() - 1); // FIXED
}
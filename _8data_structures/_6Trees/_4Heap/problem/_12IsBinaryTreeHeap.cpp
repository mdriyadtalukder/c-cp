// ekta binary tree thakbe dekhbte hbe oita max heap nki
// er jnno 1st e total node count krbo
// then dekbo total count er theke besi kono index ase nki..like total node 5 but 6 index e ekta node ase..so eita heap na.
// then check krbo // Every Parent>= child  ei condition thik ase nki for each node as max heap
//TC=O(n)
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// count nodes
int count(Node *root)
{
    if (!root)
        return 0;

    return 1 + count(root->left) + count(root->right);
}

// check CBT
bool CBT(Node *root, int index, int total_nodes)
{
    if (!root)
        return 1;

    if (index >= total_nodes)
        return 0;

    return CBT(root->left, 2 * index + 1, total_nodes) &&
           CBT(root->right, 2 * index + 2, total_nodes);
}

// check Max Heap
bool maxHeap(Node *root)
{
    // One node exist atleast
    if (root->left)
    {
        if (root->data < root->left->data)
            return 0;
        if (!maxHeap(root->left))
            return 0;
    }
    if (root->right)
    {
        if (root->data < root->right->data)
            return 0;
        return maxHeap(root->right);
    }
    return 1;
}

// main function
bool isHeap(struct Node *tree)
{
    // count nodes
    int num = count(tree);

    // check CBT
    if (!CBT(tree, 0, num))
        return 0;

    // check max heap property
    return maxHeap(tree);
}
#include <bits/stdc++.h>
using namespace std;

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

// Build Tree (DFS style)
Node *BinaryTree()
{
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    Node *temp = new Node(x);

    cout << "Enter left child of " << x << ": ";
    temp->left = BinaryTree();

    cout << "Enter right child of " << x << ": ";
    temp->right = BinaryTree();

    return temp;
}

// Preorder Traversal---problem--TC=SC=O(n)
void Preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

int main()
{
    cout << "Enter root node: ";
    Node *root = BinaryTree();

    cout << "Preorder Traversal: ";
    Preorder(root);

    return 0;
}

/* problem-2..not print ,,just add in vector
void pre(Node *root, vector<int>& ans)
{
    if (root == NULL)
        return;

    // Node
    ans.push_back(root->data);

    // Left
    pre(root->left, ans);

    // Right
    pre(root->right, ans);
}

vector<int> preorder(Node* root)
{
    vector<int> ans;
    pre(root, ans);
    return ans;
}

*/

/*Types of Traversal in Binary Tree

✅ 1. Depth-First Traversal (DFS)
Preorder → Root → Left → Right
Inorder → Left → Root → Right
Postorder → Left → Right → Root

✅ 2. Breadth-First Traversal (BFS)
Level Order Traversal → Level by level*/
#include <bits/stdc++.h>
using namespace std;
// details in note
// for delete leaf node thakle sora sori delete r ekta child thakle tar parent k delele kre grandparent er shthe connect kore
// both child thkle left r right ..tahole right side er min elem k khuje jeta delete krbo oitar shthe swap kre then target node delete krbo.
// delete krle unbalace hote pare node..so delete krte tar opposite side e unbalance hy,,r insert krle sei side ei hy unbalance.
class Node
{
public:
    int data, height;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

int getheight(Node *root)
{
    if (!root)
        return 0;
    return root->height;
}

int getbalance(Node *root)
{
    if (!root)
        return 0;
    return getheight(root->left) - getheight(root->right);
}

// Right Rotation
Node *rightRotation(Node *root)
{
    Node *child = root->left;
    Node *childRight = child->right;

    child->right = root;
    root->left = childRight;

    // Update height
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    return child;
}

// Left Rotation
Node *leftRotation(Node *root)
{
    Node *child = root->right;
    Node *childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    return child;
}

Node *insert(Node *root, int key)
{
    // Doesn't exist
    if (!root)
        return new Node(key);

    // Exist hai
    if (key < root->data) // Left side
        root->left = insert(root->left, key);
    else if (key > root->data) // Right side
        root->right = insert(root->right, key);
    else
        return root; // Duplicate elements are not allowed

    // Update height
    root->height = 1 + max(getheight(root->left), getheight(root->right));

    // Balancing check
    int balance = getbalance(root);

    // Left Left case
    if (balance > 1 && key < root->left->data)
        return rightRotation(root);

    // Right Right case
    else if (balance < -1 && key > root->right->data)
        return leftRotation(root);

    // Left Right case
    else if (balance > 1 && key > root->left->data)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // Right Left case
    else if (balance < -1 && key < root->right->data)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    // No Unbalancing
    return root;
}

Node *deleteNode(Node *root, int key)
{
    // add code here,
    if (!root)
        return NULL;

    if (key < root->data) // left side
        root->left = deleteNode(root->left, key);
    else if (key > root->data) // Right side
        root->right = deleteNode(root->right, key);
    else
    {
        // Leaf Node
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        // Only one child exist
        else if (root->left && !root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (!root->left && root->right)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            // Right side smallest element
            Node *curr = root->right;
            while (curr->left)
            {
                curr = curr->left;
            }
            root->data = curr->data;
            root->right = deleteNode(root->right, curr->data);
        }
    }

    // Update the height
    root->height = 1 + max(getheight(root->left), getheight(root->right));

    // Check the balance
    int balance = getbalance(root);

    // Left side
    if (balance > 1)
    {
        // LL
        if (getbalance(root->left) >= 0)
            return rightRotation(root);
        // LR
        else
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    // Right side
    else if (balance < -1)
    {
        // RR
        if (getbalance(root->right) <= 0)
            return leftRotation(root);
        // RL
        else
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    else
        return root;
}

bool search(Node *root, int key)
{
    if (!root)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
void preorder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);

    cout << "preorder: " << endl;
    preorder(root);

    cout << "\ninorder: " << endl;
    inorder(root);

    // delete
    root = deleteNode(root, 50);

    cout << "\n\nafter delete preorder: " << endl;
    preorder(root);

    cout << "\nafter delete inorder: " << endl;
    inorder(root);

    // search
    if (search(root, 30))
        cout << "\nFound\n";
    else
        cout << "\nNot Found\n";

    return 0;
}
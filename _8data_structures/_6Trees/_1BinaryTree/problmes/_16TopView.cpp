/*
..nich theke left side gula then upor theke right side gula for top view..emn na ashole 0 theke dekha oitar konta 1st and kon gula covered
1.left and right most ber krbo
2.then ans and visited ei 2 array create krbo..r-l+1 size er..
 (-1*l) krle top node er index pabe then -1 kre hbe next left gulir index
 and +1 krle hbe next right gular index..
 then check krbo oi index visited nki na thke ans array te borto value ta thik oi index ei..
3. left side -4,-3,-2,-1,0->top,1,2,3 right side(index-0,1,2,3,4,5,6,7)


for bottom view, we do not need tracking visited index..er jnno nich theke dekhbo konta 1st e por.r kongula convered.
*/
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

// Build Tree
Node *BinaryTree()
{
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    Node *temp = new Node(x);

    temp->left = BinaryTree();
    temp->right = BinaryTree();

    return temp;
}

// Find min & max horizontal distance
void findRange(Node *root, int pos, int &l, int &r)
{
    if (!root)
        return;

    l = min(l, pos);
    r = max(r, pos);

    findRange(root->left, pos - 1, l, r);
    findRange(root->right, pos + 1, l, r);
}

// Top View (your style)
vector<int> topView(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    int l = 0, r = 0;

    // step 1: find range
    findRange(root, 0, l, r);

    vector<int> ans(r - l + 1);
    vector<bool> filled(r - l + 1, 0); // not will be in bottom view

    queue<Node *> q;
    queue<int> index;

    q.push(root);
    index.push(-1 * l); // shift index

    while (!q.empty())
    {
        Node *temp = q.front();
        int pos = index.front();

        q.pop();
        index.pop();

        // store only first node
        if (!filled[pos]) // not will be in bottom view
        {
            ans[pos] = temp->data;
            filled[pos] = 1;
        }
        // ans[pos] = temp->data; //it will be in bottom view
        if (temp->left)
        {
            q.push(temp->left);
            index.push(pos - 1);
        }

        if (temp->right)
        {
            q.push(temp->right);
            index.push(pos + 1);
        }
    }

    return ans;
}

int main()
{
    Node *root = BinaryTree();

    vector<int> ans = topView(root);

    return 0;
}

/*/ recusion

void Tview(Node *root, int pos, vector<int> &ans, vector<int> &level, int l)
{
    if (!root)
        return;

    if (l < level[pos]) //for bottom view >=
    {
        ans[pos] = root->data;
        level[pos] = l;
    }

    Tview(root->left, pos - 1, ans, level, l + 1);
    Tview(root->right, pos + 1, ans, level, l + 1);
}

vector<int> topView(Node *root)
{
    // Your code here
    int l = 0, r = 0;

    find(root, 0, l, r);

    vector<int> ans(r - l + 1);
    vector<int> level(r - l + 1, INT_MAX);

    Tview(root, -1*l, ans, level, 0);

    return ans;
}
*/
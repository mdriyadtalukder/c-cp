/*target value er node e giye burn krbo node ta and oitar just height count krbo then
 backtracking kre pichabe in 1sec(burn timer;-1) e sei node burn krbe
then j side theke agun ashse tar ulta side e giye oi node er height count krbe..then height+2sec
then abr backtracking krbe in 2s(burn timer;-2) then oitar height count krbe then height+2sec..so on
then max ta result hbe

**height count er jnno every node er left and right cout kre jog kre upore pathabe .
but burn er node theke negative value return krbo..-1 hbe like 1s -1,2nd -1-1=-2 so on.
ekside thekei negative value ashbe like h=4 and burn=-3 so abs(4+(-3))=7
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Burn function
int Burn(Node *root, int &timer, int target)
{
    if (!root)
        return 0;

    // target node mil gaya
    if (root->data == target)
        return -1;

    int left = Burn(root->left, timer, target);
    int right = Burn(root->right, timer, target);

    // agar target left me hai
    if (left < 0)
    {
        timer = max(timer, abs(left) + right);
        return left - 1;
    }

    // agar target right me hai
    if (right < 0)
    {
        timer = max(timer, left + abs(right));
        return right - 1;
    }

    // normal height return
    return 1 + max(left, right);
}

// target node find karna
void find(Node *root, int target, Node *&BurnNode)
{
    if (!root)
        return;

    if (root->data == target)
    {
        BurnNode = root;
        return;
    }

    find(root->left, target, BurnNode);
    find(root->right, target, BurnNode);
}

// height calculate
int Height(Node *root)
{
    if (!root)
        return 0;

    return 1 + max(Height(root->left), Height(root->right));
}

// main function
int minTime(Node *root, int target)
{
    int timer = 0;

    // upward + sideways burn calculate
    Burn(root, timer, target);

    // target node find karo
    Node *BurnNode = NULL;
    find(root, target, BurnNode);

    // target ke subtree ka height
    int high = Height(BurnNode) - 1;

    // final answer
    return max(timer, high);
}
int main() {}
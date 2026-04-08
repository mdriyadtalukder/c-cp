// ekta tree deoya thkbe oitar sob theke sub tree ber kre oitar number of nodes return krte hbe..
// proti ta BST er node check krbo r dekhbo oi BST nki and er length koto..boro length ekta variable e store krbo..its O(n^2)
// optimized->root theke left e check krbo and right e check krbo j tara BST nki..
// left node(curr root) er left er leaf node e jbo then er size hbe 1 and eita bST then er max and min value same hbe.
//.then oiar right tao same vabe ber krbo then dekhbo left max value<current root and right min value>current root hole er size
// hbe 1+1+1=left+right+curr root.max hbe 2tar modde jeta max oita and min as well.then eigula curr root er parent e pathabe upore..so on
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
class Box
{
public:
    bool BST;
    int size;
    int min, max;

    Box()
    {
        BST = 1;
        size = 0;
        min = INT_MAX; // last leaf 6 so intmax r 6 compare krle min=6 e hbe
        max = INT_MIN; // same as min logic
    }
};
class Solution
{
public:
    Box *find(Node *root, int &Totalsize)
    {
        // root doesn't exist
        if (!root)
        {
            return new Box();
        }

        Box *Lefthead = find(root->left, Totalsize);
        Box *Righthead = find(root->right, Totalsize);

        // check BST condition
        if (Lefthead->BST && Righthead->BST &&
            Lefthead->max < root->data && root->data < Righthead->min)
        {
            Box *head = new Box();

            head->BST = 1;
            head->size = 1 + Lefthead->size + Righthead->size;

            head->min = min(root->data, Lefthead->min);
            head->max = max(root->data, Righthead->max);

            Totalsize = max(Totalsize, head->size);

            return head;
        }
        else
        {
            Box *head = new Box();
            head->BST = 0;
            head->size = 0;
            return head;
        }
    };

    int largestBst(Node *root)
    {

        // Your code here
        int Totalsize = 0;
        find(root, Totalsize);
        return Totalsize;
    };
};
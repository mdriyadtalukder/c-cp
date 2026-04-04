// // boundary like root theke britto..mane sob last k gure ashbe..like ()..1st / left boundary then leaps then right \ boundary..
// void LeftSub(Node *root, vector<int> &ans)
// {
//     if (!root || (!root->left && !root->right))
//         return;

//     ans.push_back(root->data);

//     if (root->left)
//         LeftSub(root->left, ans);
//     else
//         LeftSub(root->right, ans);
// }

// void Leaf(Node *root, vector<int> &ans)
// {
//     if (!root)
//         return;

//     if (!root->left && !root->right)
//     {
//         ans.push_back(root->data);
//         return;
//     }

//     Leaf(root->left, ans);
//     Leaf(root->right, ans);
// }

// void RightSub(Node *root, vector<int> &ans)
// {
//     if (!root || (!root->left && !root->right))
//         return;

//     if (root->right)
//         RightSub(root->right, ans);
//     else
//         RightSub(root->left, ans);

//     ans.push_back(root->data);
// }

// vector<int> boundary(Node *root)
// {
//     vector<int> ans;

//     if (!root)
//         return ans;

//     // root
//     ans.push_back(root->data);

//     // left boundary
//     LeftSub(root->left, ans);

//     // leaf nodes
//     Leaf(root->left, ans);
//     Leaf(root->right, ans);

//     // right boundary (stored separately then reversed)
//     vector<int> temp;
//     RightSub(root->right, temp);

//     for (int i = temp.size() - 1; i >= 0; i--)
//     {
//         ans.push_back(temp[i]);
//     }

//     return ans;
// }
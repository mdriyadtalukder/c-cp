//  vertical | 0 theke eivebe 1st to last ekta ekta print hbe .. top view er motoi ..
// 1. index: 0,-1,-2,-3,-4 eivbe left side e jabei sudu tree then..left side e gele -1 hbe and right e gele +1.
// 2. jeta sob cheye kom index oigula age print hbe..order wise.
// 3. 2ta 2d array nibo ..eta 0-positive index er valuve rakho r ektai negative index er value rakhbo..
// then sob cheye kom index like -5 theke value print krte krte jbo max obdi.
// .like min to max index.like -3 index e 1,2,3 total 3 ta value ase..so print hbe 1,2,3..serially

// void Find(Node *root, int pos, int &l, int &r)
// {
//     if (!root)
//         return;

//     l = min(l, pos);
//     r = max(r, pos);

//     Find(root->left, pos - 1, l, r);
//     Find(root->right, pos + 1, l, r);
// }

// vector<int> verticalOrder(Node *root)
// {
//     if (!root)
//         return {};

//     int l = 0, r = 0;
//     Find(root, 0, l, r);

//     // Positive (0 → r)
//     vector<vector<int>> Positive(r + 1);

//     // Negative (-1 → l)
//     vector<vector<int>> Negative(abs(l) + 1);

//     queue<Node *> q;
//     queue<int> index;

//     q.push(root);
//     index.push(0);

//     while (!q.empty())
//     {
//         Node *temp = q.front();
//         q.pop();
//         int pos = index.front();
//         index.pop();

//         if (pos >= 0)
//             Positive[pos].push_back(temp->data);
//         else
//             Negative[abs(pos)].push_back(temp->data);

//         // Left child
//         if (temp->left)
//         {
//             q.push(temp->left);
//             index.push(pos - 1);
//         }

//         // Right child
//         if (temp->right)
//         {
//             q.push(temp->right);
//             index.push(pos + 1);
//         }
//     }

//     vector<int> ans;

//     // Negative side (leftmost → -1)
//     for (int i = Negative.size() - 1; i >= 1; i--)
//     {
//         for (int j = 0; j < Negative[i].size(); j++)
//         {
//             ans.push_back(Negative[i][j]);
//         }
//     }

//     // Positive side (0 → rightmost)
//     for (int i = 0; i < Positive.size(); i++)
//     {
//         for (int j = 0; j < Positive[i].size(); j++)
//         {
//             ans.push_back(Positive[i][j]);
//         }
//     }

//     return ans;
// }
// // Diagonal \ ei vbe sob gula select kre level dibo like 1st \ gula l=1 then 2nd \ l=2 so on.
// //.then 2d array create krbo..then level num onujayi index e dukabo like l=1 er gula index 1 e dukabo then so on..
// // age nijer gula like \ er sob print krbo then right gua te jabo jdi eki level er thek..
// // left side e gelei level +1 hbe..right side e gele same thkbe level

// void find(Node *root, int pos, int &l)
// {
//     if (!root)
//         return;

//     l = max(pos, l);

//     find(root->left, pos + 1, l);
//     find(root->right, pos, l);
// }

// void findDig(Node *root, int pos, vector<vector<int>> &ans)
// {
//     if (!root)
//         return;

//     ans[pos].push_back(root->data);

//     findDig(root->left, pos + 1, ans);
//     findDig(root->right, pos, ans);
// }

// vector<int> diagonal(Node *root)
// {
//     if (!root) return {};

//     int l = 0; // max diagonal index
//     find(root, 0, l);

//     vector<vector<int>> ans(l + 1);

//     findDig(root, 0, ans);

//     vector<int> temp;

//     for (int i = 0; i < ans.size(); i++)
//     {
//         for (int j = 0; j < ans[i].size(); j++)
//         {
//             temp.push_back(ans[i][j]);
//         }
//     }

//     return temp;
// }
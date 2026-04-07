// inorder LNR ja accending order e dei..
// eita k reverse krle RNL hbe ja decending order e dibe then 1st kth elem er sum ber krbo..
// same as small kth..just right ta left hbe and left ta right..
// void kThLargest(Node *root, int &ans, int &K)
// {
//     if (!root || K <= 0)
//         return;

//     // Right first (largest first)
//     kThLargest(root->right, ans, K);

//     K--;

//     if (K == 0)
//     {
//         ans = root->data;
//     }

//     // Left
//     kThLargest(root->left, ans, K);
// }

// int kthLargest(Node *root, int k)
// {
//     int ans = 0;

//     kThLargest(root, ans, k);

//     return ans;
// }
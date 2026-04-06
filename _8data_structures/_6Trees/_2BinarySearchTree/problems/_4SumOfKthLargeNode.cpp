// inorder LNR ja accending order e dei..
// eita k reverse krle RNL hbe ja decending order e dibe then 1st kth elem er sum ber krbo..
// same as small kth..just right ta left hbe and left ta right..
// void kThLargest(Node *root, int &ans, int &K)
// {
//     if (!root || k <= 0)
//         return;
//     kThLargest(root->right, ans, k);
//     K--;
//     if (k == 0)
//         ans += root->data;

//     kThLargest(root->left, ans, k)
// };
// 2ta node er value just swap hoye wrong hbe..so ei 2 ta fix krte hbe....ei prblm 2 node ba 4 node orthat 1 ba 2 bar prblm hote pare maximun.
// er jnno inorder ber krbo then sort krbo then ei value diye abar graph banabo..
// optimizing->morris inorder traversal krbo..jdi pre boro hy curr theke tahole first e rakhbo then problem ta second e.

// void correctBST(struct Node* root)
// {
//     Node *curr = NULL;
//     Node *first = NULL, *second = NULL;
//     Node *last = NULL, *present = NULL;

//     while (root)
//     {
//         // left doesn't exist
//         if (!root->left)
//         {
//             last = present;
//             present = root;

//             if (last && last->data > present->data)
//             {
//                 if (!first)
//                     first = last;
//                 if (first)
//                     second = present;
//             }

//             root = root->right;
//         }
//         // left exists
//         else
//         {
//             curr = root->left;

//             while (curr->right && curr->right != root)
//             {
//                 curr = curr->right;
//             }

//             if (!curr->right)
//             {
//                 curr->right = root;
//                 root = root->left;
//             }
//             else // left subtree already traversed
//             {
//                 curr->right = NULL;

//                 last = present;
//                 present = root;

//                 if (last && last->data > present->data)
//                 {
//                     if (!first)
//                         first = last;
//                     if (first)
//                         second = present;
//                 }

//                 root = root->right;
//             }
//         }
//     }

//     int num = first->data;
//     first->data = second->data;
//     second->data = num;
// }
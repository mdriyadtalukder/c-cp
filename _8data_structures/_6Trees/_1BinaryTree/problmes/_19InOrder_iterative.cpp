// vector<int> inOrder(Node *root)
// {
//     vector<int> ans;
//     if (!root)
//         return ans;

//     stack<Node *> s;
//     stack<bool> visited;

//     s.push(root);
//     visited.push(0);

//     while (!s.empty())
//     {
//         Node *temp = s.top();
//         s.pop();

//         bool flag = visited.top();
//         visited.pop();

//         // first time visit
//         if (flag == 0)
//         {
//             // Right (push first so it is processed later)
//             if (temp->right)
//             {
//                 s.push(temp->right);
//                 visited.push(0);
//             }

//             // Node (mark for second visit)
//             s.push(temp);
//             visited.push(1);

//             // Left (processed first in inorder)
//             if (temp->left)
//             {
//                 s.push(temp->left);
//                 visited.push(0);
//             }
//         }
//         else
//         {
//             // second time visit → process node
//             ans.push_back(temp->data);
//         }
//     }

//     return ans;
// }
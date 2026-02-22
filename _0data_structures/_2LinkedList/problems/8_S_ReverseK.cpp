// class Solution
// {
// public:
//     ListNode reversekGroup(ListNode nead, int K)
//     {
//         ListNode *temp = head;
//         int cnt = 0;
//         // check if k nodes exist
//         while (cnt < k)
//         {
//             if (temp == NULL)
//             {
//                 return head;
//             }
//             temp = temp->next;
//             cnt++;
//         }
//         // recursively call for rest of LL
//         ListNode *prevNode = reverseKGroup(temp, k);
//         // reverse current group
//         temp = head;
//         cnt = 0;
//         while (cnt < k)
//         {
//             ListNode *next = temp->next;
//             temp->next = prevNode; // prevNode means head of return nodes..it will be next of temp..so on..then pre  hbe temp t and tem ta hbe next ta for doing this again..
//             prevNode = temp;
//             temp = next;
//             cnt++;
//         }
// return prevNode;
//     }
// }
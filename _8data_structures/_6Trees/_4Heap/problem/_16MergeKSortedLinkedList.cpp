// k=6 6 ta sorted linkedlist deoya thkbe oita k merge krte hbe sorted way te.
// minheap e sob dukabo then ekta ekta kre ber krbo..its TC=O(nklognk)..Sc=O(nk)
// optimal-> k size er minheap banabo and sob linkedlist er 1st elem dukabo prothom e.then ekta ekta kore pop krbo and ans e dukabo
// and oitar next a ja ase oita k push krbo..next na thakle onno pop kre tar next ta dukabo..so on..TC=O(nklogk).Sc=O(k)

// #include <bits/stdc++.h>
// using namespace std;
// class Solution
// {
// public:
//     class Compare
//     {
//     public:
//         bool operator()(Node *a, Node *b)
//         {
//             return a->data > b->data; // min heap
//         }
//     };

//     Node *mergeKLists(vector<Node *> &arr)
//     {

//         // Min heap
//         priority_queue<Node *, vector<Node *>, Compare> p; // aurgument k deoya thkle p(arr,arr+k)

//         // push first node of each list
//         for (int i = 0; i < arr.size(); i++)
//         {
//             if (arr[i] != NULL)
//             {
//                 p.push(arr[i]);
//             }
//         }

//         Node *root = new Node(0); //// 1st node 0 dorlam jake point krse tail and head both..
//         Node *tail = root;
//         Node *temp;

//         while (!p.empty())
//         {
//             temp = p.top();
//             p.pop();

//             tail->next = temp; //// 0 1..so jeheto 0 k tail point krse so tail er next hbe 1...
//             tail = tail->next; //// tail ta hbe abr tail er next..

//             if (temp->next)
//             {
//                 p.push(temp->next);
//             }
//         }

//         return root->next;
//     }
// };
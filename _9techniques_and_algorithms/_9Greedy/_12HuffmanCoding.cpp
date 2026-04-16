// // ei coding file compress kre..10mb er file 2 mb kre..
// // total character ase 100 ta like abcdaabbdhrri...eigular ascii value hbe..like a=98..er 8 bit hbe like 10001100.
// //.so 100*8=800bit size hbe ei msg er...so msg pass hy ascii value te..so ei 800bit k compress kre back korbo..
// // like total letter as 6 ta abcdef..eigula k ami amr moto represent krbo..like a=000,b=001,c=010...etc then 100*3=300 bits..
// //  table pathabo like a=000 mane a=01100001...jate buje 000 mane 01100001..eivbe a k chine and decode kre..others letter o emn vabe represent hbe table e
// // so 6*8+6*3=66  er table hbe.ei table ta reciever k pathate hbe decode er jnno.sp 300+66=366 size hbe mag er

// // huffman-->boro msg re kom bit dibe and choto re besi bit dibe..like 45=0 , 3=101. like a ase 5 bar so a=1011 r d ase 1 bar so d=0;
// // a=5,b=8,c=21... eita diye tree banabo..choto gula diye sum krte thakbo 1st e..left e gele 0 r right e gele 1.
// //.eivbe  bit creates krbo sob gulir jnno
// // so X-->5*4(a 5 bar ase r er bit 4 ta)+1*1(d 1 bar ase r er bit 1 ta)+..so on .so jog hbe.
// // Y---> then a=01100001,b=01100011..so 6tar 8 bit kre so 6*8+total bit of all huffman so 4+1(a er 4 ta and d er 1 ta ..so on)
// // so X+Y=total size..ja hbe ager tar theke choto..366 er theke choto

// // updated
// class Solution
// {
// public:
//     class Node
//     {
//     public:
//         int freq;
//         char c;
//         int idx;
//         Node *left, *right;

//         Node(int frequency, char name, int i)
//         {
//             freq = frequency;
//             c = name;
//             idx = i;
//             left = right = NULL;
//         }
//     };

//     class comp
//     {
//     public:
//         bool operator()(Node *a, Node *b)
//         {
//             if (a->freq == b->freq)
//                 return a->idx > b->idx;

//             return a->freq > b->freq; // heap ke case me ulta kaam krta hai normally
//                                       //  a<b hona chahiye but in heap a>b
//         }
//     };

//     void preorder(Node *root, string &temp, vector<string> &ans)
//     {
//         if (!root)
//             return;

//         if (!root->left && !root->right)
//         {
//             if (temp == "")
//                 temp = '0';

//             ans.push_back(temp);
//             return;
//         }
//         //   left
//         temp.push_back('0');
//         preorder(root->left, temp, ans);

//         // right
//         temp.pop_back();
//         temp.push_back('1');
//         preorder(root->right, temp, ans);

//         // nxt again start from root
//         temp.pop_back();
//     }
//     vector<string> huffmanCodes(string &s, vector<int> f)
//     {
//         // Code here

//         // Build the huffman tree
//         // build the min heap(frequency ke basis pe)
//         // greater<int> this will be customised
//         priority_queue<Node *, vector<Node *>, comp> pq;
//         int N = s.size();
//         for (int i = 0; i < N; i++)
//         {
//             pq.push(new Node(f[i], s[i], i));
//         }

//         while (pq.size() > 1)
//         {
//             Node *first = pq.top();
//             pq.pop();
//             Node *second = pq.top();
//             pq.pop();

//             Node *root = new Node(first->freq + second->freq, '$', min(first->idx, second->idx));
//             root->left = first;
//             root->right = second;
//             pq.push(root);
//         }

//         Node *root = pq.top();
//         pq.pop();
//         // preorder find krna
//         vector<string> ans;
//         string temp;
//         preorder(root, temp, ans);
//         return ans;
//     }
// };

// // old
// class Solution
// {
// public:
//     class Node
//     {
//     public:
//         int freq;
//         char c;
//         Node *left, *right;

//         Node(int frequency, char name)
//         {
//             freq = frequency;
//             c = name;
//             left = right = NULL;
//         }
//     };

//     class comp
//     {
//     public:
//         bool operator()(Node *a, Node *b)
//         {
//             return a->freq > b->freq;
//         }
//     };

//     void preorder(Node *root, string &temp, vector<string> &ans)
//     {
//         if (!root)
//             return;

//         if (!root->left && !root->right)
//         {
//             ans.push_back(temp);
//             return;
//         }

//         temp.push_back('0');
//         preorder(root->left, temp, ans);
//         temp.pop_back();

//         temp.push_back('1');
//         preorder(root->right, temp, ans);
//         temp.pop_back();
//     }

//     vector<string> huffmanCodes(string &s, vector<int> f)
//     {

//         priority_queue<Node *, vector<Node *>, comp> pq;

//         int N = s.size();

//         for (int i = 0; i < N; i++)
//         {
//             pq.push(new Node(f[i], s[i]));
//         }

//         while (pq.size() > 1)
//         {
//             Node *first = pq.top();
//             pq.pop();
//             Node *second = pq.top();
//             pq.pop();

//             Node *root = new Node(first->freq + second->freq, '$');

//             root->left = first;
//             root->right = second;

//             pq.push(root);
//         }

//         Node *root = pq.top();
//         pq.pop();

//         vector<string> ans;
//         string temp;

//         preorder(root, temp, ans);

//         return ans;
//     }
// };
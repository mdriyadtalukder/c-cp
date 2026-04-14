// // k=3 3 ta array or list thakbe ..1ta smallest range banate jetate atleast ekta kore elem thakbe from all array or list.
// //[0,5]..1st array te 4 ase ja 0-5 e ase..1st e 0 ase and 3rd e 5 ase..so 0-5 er modde sob ase atleast ekbar kre.
// // eivbe onk possible range ashte pare..so sob theke smallest posible range ta ans hbe..5-0=5,23-21=2..so samllest is (21,23)
// // minheap nibo..oitar vitor sob array er 1st elem dukbao..then 1ta 1ta pop krbo r tar next ta dukabo..min hbe heap er top ta./
// // r max ta compare kre ber krbo every time..then range hbe min to max..then shortest range ta nibo as ans.
// // TC=O(nklogk).
// vector<int> smallestRange(vector<vector<int>> &nums)
// {
//     priority_queue<pair<int, pair<int, int>>,
//                    vector<pair<int, pair<int, int>>>,
//                    greater<pair<int, pair<int, int>>>>
//         p;

//     int minimum, maximum = INT_MIN;

//     // insert first element of each row into heap
//     for (int i = 0; i < nums.size(); i++)
//     {
//         p.push(make_pair(nums[i][0], make_pair(i, 0)));
//         maximum = max(maximum, nums[i][0]);
//     }

//     minimum = p.top().first;

//     vector<int> ans(2);
//     ans[0] = minimum;
//     ans[1] = maximum;

//     pair<int, pair<int, int>> temp;
//     int row, col, elem;

//     while (p.size() == nums.size())
//     {
//         temp = p.top();
//         p.pop();

//         elem = temp.first;
//         row = temp.second.first;
//         col = temp.second.second;

//         minimum = elem;

//         // If I have got smallest range
//         if (maximum - minimum < ans[1] - ans[0])
//         {
//             ans[0] = minimum;
//             ans[1] = maximum;
//         }

//         if (col + 1 < nums[row].size())
//         {
//             col++;
//             p.push(make_pair(nums[row][col], make_pair(row, col)));

//             maximum = max(maximum, nums[row][col]);
//         }
//     }

//     return ans;
// }
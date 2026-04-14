// // k=4 4*4 er matrix thakbe.. every row ekek ta sorted array..so sob row k merge kre ekta sorted array banate hbe.

// // 1st approcah:k size er minheap banabo and 1st column er sob dukabo..then ekta ekta pop krbo r oitar next-> ta push krbo.TC = O(k ^ 2logk)

// // 2nd approach:--  1st e 2d array ekta 1d array te vorbo then oitar upor merge sorte krbo.
// //  merge sort divide kre into subarray untill get single value but ei khetre divide krbe untill get k size of subarray.TC = O(k ^ 2logk)

// vector<int> mergeArrays(vector<vector<int>> &arr)
// {
//     int K = arr.size();

//     // temp vector (value, (row, col))
//     vector<pair<int, pair<int, int>>> temp;

//     // store first element of each array
//     for (int i = 0; i < K; i++)
//     {
//         if (!arr[i].empty())
//         {
//             temp.push_back({arr[i][0], {i, 0}});
//         }
//     }

//     // min heap from temp
//     priority_queue<
//         pair<int, pair<int, int>>,
//         vector<pair<int, pair<int, int>>>,
//         greater<pair<int, pair<int, int>>>>
//         pq(temp.begin(), temp.end());

//     vector<int> ans;

//     pair<int, pair<int, int>> Element;
//     int i, j;

//     while (!pq.empty()) // FIXED
//     {
//         Element = pq.top(); // FIXED
//         pq.pop();

//         ans.push_back(Element.first);

//         i = Element.second.first;
//         j = Element.second.second;

//         if (j + 1 < arr[i].size())
//         {
//             pq.push({arr[i][j + 1], {i, j + 1}}); // FIXED
//         }
//     }

//     return ans;
// }

// void merge(vector<int> & arr, int st, int mid, int end)
// {
//     vector<int> temp;
//     int i = st, j = mid + 1;

//     while (i <= mid && j <= end)
//     {
//         if (arr[i] <= arr[j])
//         {
//             temp.push_back(arr[i++]);
//         }
//         else
//         {
//             temp.push_back(arr[j++]);
//         }
//     }

//     while (i <= mid)
//         temp.push_back(arr[i++]);

//     while (j <= end)
//         temp.push_back(arr[j++]);

//     for (int idx = 0; idx < temp.size(); idx++)
//     {
//         arr[st + idx] = temp[idx];
//     }
// }

// void mergeSort(vector<int> &arr, int st, int end, int portion, int k)
// {
//     if (portion < 2)
//         return;

//     int leftSize = portion / 2;
//     int rightSize = portion - leftSize;

//     int mid = st + leftSize * k - 1;

//     mergeSort(arr, st, mid, leftSize, k);       // left part
//     mergeSort(arr, mid + 1, end, rightSize, k); // right part

//     merge(arr, st, mid, end);
// }

// vector<int> mergeKArrays(vector<vector<int>> arr, int K)
// {
//     vector<int> ans;

//     // flatten
//     for (int i = 0; i < K; i++)
//     {
//         for (int j = 0; j < K; j++) // assuming each array size = K..j<arr[0].size()).. k na thakle
//         {
//             ans.push_back(arr[i][j]);
//         }
//     }

//     // apply your custom merge sort
//     mergeSort(ans, 0, ans.size() - 1, K, K);
//     // mergeSort(ans, 0, ans.size() - 1, K, arr[0].size()); k na deoya thakle

//     return ans;
// }
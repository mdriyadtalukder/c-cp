// // 2d array thakbe..1st column holo enqueu time like 1 means 1ta baje theke eita available hbe.
// //.and 2nd column is processing time like 2 means eita execute hyte 2h time lgbe.
// // onk task eksthe hole jar proceesing time kom tar kaj cpu age krbe.

// // ans-:means heap nibo oitar modde processing time and index rakhbo..and ans e index ta rakhbo..

// vector<int> getOrder(vector<vector<int>> &tasks)
// {
//     vector<int> ans;
//     int n = tasks.size();

//     // add index
//     for (int i = 0; i < n; i++)
//     {
//         tasks[i].push_back(i);
//     }

//     // sort by enqueue time
//     sort(tasks.begin(), tasks.end());

//     long long timer = tasks[0][0];
//     int i = 0;

//     // {processing time, index}
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//     while (!pq.empty() || i < n)
//     {

//         // push all available tasks
//         while (i < n && tasks[i][0] <= timer)
//         {
//             pq.push({tasks[i][1], tasks[i][2]});
//             i++;
//         }

//         // if heap empty → jump time
//         if (pq.empty())
//         {
//             timer = tasks[i][0];
//         }
//         else
//         {
//             ans.push_back(pq.top().second);
//             timer += pq.top().first;
//             pq.pop();
//         }
//     }

//     return ans;
// }
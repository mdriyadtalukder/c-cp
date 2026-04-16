// //[1,3][3,6]--non overlappin..[1,3][2,6]--overlapping..so min koto gula overlapping sorailer non overlapping hbe..
// // 1st e sort krbo then ei end1<=star2 condition follow krbo..

// bool comp(vector<int> &a, vector<int> &b)
// {
//     return a[1] < b[1]; // sort by end time
// }

// int eraseOverlapIntervals(vector<vector<int>> &intervals)
// {
//     sort(intervals.begin(), intervals.end(), comp);

//     int end = INT_MIN;
//     int remove = 0;

//     for (int i = 0; i < intervals.size(); i++)
//     {
//         if (end <= intervals[i][0]) // 0 start
//         {
//             // no overlap
//             end = intervals[i][1]; // 1 end
//         }
//         else
//         {
//             // overlap → remove this interval
//             remove++;
//         }
//     }

//     return remove;
// }
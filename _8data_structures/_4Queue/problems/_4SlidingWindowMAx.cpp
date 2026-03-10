
//ekta window er max number
// class Solution
// {
// public:
//     vector<int> maxSlidingWindow(vector<int> &nums, int k)
//     {
//         deque<int> dq;
//         vector<int> res;
//         // 1st wind
//         // dequeue e element push krbo and pop krbo from back jdi current elem boro hy.
//         for (int i = 0; i < k; i++)
//         {
//             while (dq.size() > 0 && nums[dq.back()] <= nums[i])
//             {
//                 dq.pop_back();
//             }
//             dq.push_back(i);
//         }
//         for (int i = k; i < nums.size(); i++)
//         {
//             res.push_back(nums[dq.front()]); // push result
//             // remove not part of curr window..remove krbo shamne theke
//             while (dq.size() > 0 && dq.front() <= i - k)
//             {
//                 dq.pop_front();
//             }

//             // remove the smaller vals
//             while (dq.size() > 0 && nums[dq.back()] <= nums[i])
//             {
//                 dq.pop_back();
//             }
//             dq.push_back(i);
//         }
//         res.push_back(nums[dq.front()]);
//         return res;
//     }
// };
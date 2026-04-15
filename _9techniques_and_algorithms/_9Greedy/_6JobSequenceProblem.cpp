// // 2d array thkbe..1st colunm job id,2nd colun deadline and 3rd profit..
// // sob cheye jar profit besi take nibo and tar dead line index fill hbe in 1 based index array...
// // deadline index vore thkle tar ager index check krbo j faka ase nki..
// // optimized->deadline er index vore gele eitar value -1 krbo..value and index soman hole oitar fill krbo and oitar boro gular(recursive) index sob oi value tai kre dibo.
// class Solution {
// public:

//     static bool comp(pair<int,int> a, pair<int,int> b)
//     {
//         return a.second > b.second; // profit descending
//     }

//     int find(int num, vector<int>& parent)
//     {
//         if(num == parent[num])
//             return num;

//         return parent[num] = find(parent[num], parent);
//     }

//     vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) 
//     {
//         int n = deadline.size();

//         // create jobs as (deadline, profit)
//         vector<pair<int,int>> jobs;

//         for(int i = 0; i < n; i++)
//         {
//             jobs.push_back({deadline[i], profit[i]});
//         }

//         // sort by profit
//         sort(jobs.begin(), jobs.end(), comp);

//         int maxDead = 0;

//         for(int i = 0; i < n; i++)
//         {
//             maxDead = max(maxDead, jobs[i].first);
//         }

//         vector<int> parent(maxDead + 1);

//         for(int i = 0; i <= maxDead; i++)
//             parent[i] = i;

//         vector<int> ans(2, 0);

//         for(int i = 0; i < n; i++)
//         {
//             int slot = find(jobs[i].first, parent);

//             if(slot > 0)
//             {
//                 ans[0]++;
//                 ans[1] += jobs[i].second;

//                 parent[slot] = slot - 1;
//             }
//         }

//         return ans;
//     }
// };
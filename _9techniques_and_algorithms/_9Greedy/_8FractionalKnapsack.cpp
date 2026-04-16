// // 2 ta array thakbe..ektai value thakbe r ektai tar weight..
// // ekta box thakbe ekta fixed weight er.tar modde emn vabe value rakhte hbe ja maximum hbe.
// // value/weight= jar besi hobe seikhn theke rakhte thakbo..

// bool comp(Item a, Item b)
// {
//     return a.value * b.weight > b.value * a.weight;
// }
// double fractionalKnapsack(int w, Item arr[], int n)
// {

//     // sort by value/weight ratio
//     sort(arr, arr + n, comp);

//     double profit = 0.0;
//     int i = 0;

//     while (w > 0 && i < n)
//     {

//         if (w >= arr[i].weight)
//         {
//             profit += arr[i].value;
//             w -= arr[i].weight;
//         }
//         else
//         {
//             double temp = (double)arr[i].value / arr[i].weight; // weigh besi hoye gele
//             profit += temp * w;
//             w = 0; // knapsack full
//         }

//         i++;
//     }

//     return profit;
// }
// // appraoch 2
// class Solution
// {
// public:
//     static bool comp(pair<int, int> a, pair<int, int> b)
//     {
//         // compare value/weight ratio
//         return (double)a.first / a.second > (double)b.first / b.second;
//     }

//     double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
//     {

//         int n = val.size();

//         // store {value, weight}
//         vector<pair<int, int>> arr;
//         for (int i = 0; i < n; i++)
//         {
//             arr.push_back({val[i], wt[i]});
//         }

//         // sort by ratio
//         sort(arr.begin(), arr.end(), comp);

//         double profit = 0.0;
//         int i = 0;

//         while (capacity > 0 && i < n)
//         {

//             if (capacity >= arr[i].second)
//             {
//                 profit += arr[i].first;
//                 capacity -= arr[i].second;
//             }
//             else
//             {
//                 double ratio = (double)arr[i].first / arr[i].second;
//                 profit += ratio * capacity;
//                 capacity = 0;
//             }

//             i++;
//         }

//         return profit;
//     }
// };
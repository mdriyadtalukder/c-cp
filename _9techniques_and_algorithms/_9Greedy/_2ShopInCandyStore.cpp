// k=2 1 ta candy kinle 2 ta free dite parbo..so min cost koto hbe? index value is candy price.
//.sort krbo and index 0 theke nite thakbo...so eivabe min and max ta return krbo ber kre..

// vector<int> candyStore(int candies[], int N, int k)
// {
//     sort(candies, candies + N); // ascending order

//     int min_amount = 0, max_amount = 0;

//     // 🔹 Minimum cost
//     int i = 0, j = N - 1;
//     while (i <= j)
//     {
//         min_amount += candies[i];
//         i++;
//         j -= k;
//     }

//     // 🔹 Maximum cost
//     i = N - 1;
//     j = 0;
//     while (i >= j)
//     {
//         max_amount += candies[i];
//         i--;
//         j += k;
//     }

//     // 🔹 Store answer
//     vector<int> ans;
//     ans.push_back(min_amount);
//     ans.push_back(max_amount);

//     return ans;
// }

// // n=2 ..2 ta vinno deoyar por oi letter boshbe A A A B B C-->B C A B _ A _ _ A=9..ans=9
// // jeta besi oitar count ber krbo then (count-1)*(n+1)+1formola diye ans ber krbo..but count er soman aro elem thakbe every tar jnno 1 jog krbo.
// // ans er size jdi choto hy letter er size theke then ans hbe letter ar size.
// int leastInterval(vector<char> &tasks, int n)
// {
//     // frequency array
//     vector<int> freq(26, 0);

//     // count frequencies
//     for (int i = 0; i < tasks.size(); i++)
//     {
//         freq[tasks[i] - 'A']++;
//     }

//     // find max frequency
//     int count = 0;
//     for (int i = 0; i < 26; i++)
//     {
//         count = max(count, freq[i]);
//     }

//     // base formula
//     int ans = (count - 1) * (n + 1);

//     // count how many tasks have max frequency
//     for (int i = 0; i < 26; i++)
//     {
//         if (freq[i] == count)
//             ans++;
//     }

//     // final answer
//     return max(ans, (int)tasks.size());
// }
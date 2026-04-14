// //[3,8,5]-.ei array banano jabe nki given array dara like [1,1,1] ei array dara..
// // every bar sum ber krbo and ekta index e boshabo..emn kre oi array banano jbe nki.
// // j array banate hbe oitar sob elem maxheap e vorbo and sum ber krbo
// // then sum-maxheap er top ta mane boro na minus krbo jeta hbe remindSum..then Element = MaxEle %RemSum; and sum = RemSum + Element;
// // then element abr push krbo heap e...pop hote thkbe until top 1 na hy..
// bool isPossible(vector<int> &target)
// {
//     priority_queue<long long> p;
//     long long sum = 0;

//     for (int i = 0; i < target.size(); i++)
//     {
//         p.push(target[i]);
//         sum += target[i];
//     }
//     long long maxEle, remSum, element;

//     while (p.top() != 1)
//     {
//         maxEle = p.top();
//         p.pop();

//         remSum = sum - maxEle;

//         // invalid cases
//         if (remSum <= 0 || remSum >= maxEle)
//             return false;

//         element = maxEle % remSum;

//         // if cannot reduce further
//         if (element == 0)
//         {
//             if (remSum != 1)
//                 return false;
//             else
//                 return true;
//         }

//         sum = remSum + element;
//         p.push(element);
//     }

//     return true;
// }
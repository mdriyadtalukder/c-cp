// onk coins deoya thakbe..n=145 banate mot koita coins lagbe?..er jnno sob theke kacher coin gula nibo of n
// 2000,1000,500,100,50,20,20,10,1...145 er kacher hoolo 100 so 100 dibo then 43 er kache 20..so 2 ta 20 nibo..3 er kacher 2.
// so 2 nibo then 1 .so 1 nibo..total 5 coins lagbe..so always possible max coin ta nibo current n er ..eitai greedy
//TC=O(n)
#include <bits/stdc++.h>
using namespace std;
int findMin(int N)
{
    int currency[] = {10, 5, 2, 1}; // just reverse order
    int notes = 0, i = 0;
    vector<int> ans;

    while (N)
    {
        notes = N / currency[i]; // 43/20=2

        while (notes--)
        {
            ans.push_back(currency[i]); // 20 k 2 bar borbo
        }

        N %= currency[i]; //// 43%20=3..so N=3 hbe..
        i++;
    }

    return ans.size();
}
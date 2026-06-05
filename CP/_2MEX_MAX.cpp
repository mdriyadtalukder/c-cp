// task--sob elem er mex+max er sum ber krte hbe..
// mex holo excluded min value..jdi kono array te 0 na thake tahole oita te mex hole 0
// r 0,1,2,7,4 ba 0,1,2,4,7 thakle eitar mex hbe 3
// max hbe max value ta..er jnno max value shamne anbo like for 0,1,2,4,7 to 7,0,1,2,4..so jdi 0 na thakto then mex hoto sob gular jnno 0..
// but 0 ase..er jnno 7[7] er max=7 and mex=0,0[7,0] er max=7 and mex=1,1[7,0,1] er max=7 and mex=2,2[7,0,1,2] er max=7 and mex=3,4[7,0,1,2,4] er max=7 and mex=3.
//.er por er sob gular elem(jdi thakto) er mex 3 coz..min excluded value is 3 in that array
// so (7+0)+(7+1)+(7+2)+(7+3)+(7+3)=44=ans

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        // input array
        for (int &x : a)
            cin >> x;

        // maximum value ber korlam
        int maxi = *max_element(a.begin(), a.end());

        // frequency count
        unordered_map<int, int> mp;

        for (int x : a)
            mp[x]++;

        // max value ta already shamne rakhbo
        // tai frequency ekta komiye dilam
        mp[maxi]--;

        vector<int> res; //rearrange vector

        // maximum value first e rakhlam
        // jate sob prefix er max same thake
        res.push_back(maxi);

        int mexi = 0;

        // 0,1,2,3... jotodin ase
        // totodin sequence e add korbo
        // karon ete mex fastest barbe
        while (mp[mexi] > 0) 
        {
            res.push_back(mexi);

            mp[mexi]--;

            mexi++;
        }

        // baki element gula add korlam
        // ekhon mex ar barbe na
        for (auto &it : mp)
        {
            int cnt = it.second;
            int vl = it.first;

            while (cnt)
            {
                res.push_back(vl);

                cnt--;
            }
        }

        long long ans = 0;

        // current maximum
        int maxid = 0;

        // prefix e kon value koybar ase
        unordered_map<int, int> calcmex;

        // current mex
        int mex = 0;

        // final array traverse
        for (int x : res)
        {
            // prefix maximum update
            maxid = max(maxid, x);

            // value add in frequency
            calcmex[x]++;

            // jotokkhon mex present
            // mex samne barabo
            while (calcmex[mex] > 0)
                mex++;

            // every prefix er (max + mex)
            ans += mex + maxid;
        }

        cout << ans << endl;
    }

    return 0;
}
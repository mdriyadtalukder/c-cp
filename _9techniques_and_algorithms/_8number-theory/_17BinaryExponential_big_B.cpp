#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int binExp(int a, long long b, int m)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return ans;
}

int main()
{
    cout << binExp(50, binExp(64, 32, M - 1), M);
}

/*
b is in array form

#include <bits/stdc++.h>
using namespace std;

int binExp(int a, int b, int m){
    a %= m;
    int ans = 1;
    while(b > 0){
        if(b & 1){
            ans = (ans * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return ans;
}

int superPow(int a, vector<int>& b) {
    int m = 1337;
    int phi = 1140;

    int bmod = 0;
    for(int val: b){
        bmod = (bmod * 10 + val) % phi;
    }

    // 🔥 ONLY FIX
    // if(__gcd(a, m) != 1){
    //     bmod += phi;
    // }

    return binExp(a, bmod, m);
}
*/
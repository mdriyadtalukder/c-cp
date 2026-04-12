#include <bits/stdc++.h>
using namespace std;
// sobcheye boro chocolate khabo and er half push krbo abr queue e..eita krbo A barr..
//Time: O(A log N)
int nchoc(int A, vector<int> &B)
{

    // Max heap
    priority_queue<int> p;
    for (int i = 0; i < B.size(); i++)
        p.push(B[i]);

    long long MaxChoc = 0;

    while (A && (!p.empty()))
    {
        MaxChoc += p.top();
        if (p.top() / 2)
            p.push(p.top() / 2);
        p.pop();
        A--;
    }
    return MaxChoc % 1000000007; // double  int e convert kra
}

int main()
{
    int A = 3;              // number of minutes
    vector<int> B = {6, 5}; // chocolates in bags

    cout << nchoc(A, B) << endl;

    return 0;
}
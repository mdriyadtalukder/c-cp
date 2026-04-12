// k1 er max heap banabo and k2 er max heap banabo then k2 er max heap er sob sum minus k1 er sob elem sum krbo tai result ashbe
// Time: O(N log K2)
#include <bits/stdc++.h>
using namespace std;

long long diffSum(vector<long long> &A, long long N, long long K1, long long K2)
{

    // Max heap for K1 smallest
    priority_queue<long long> p1;

    // Max heap for K2 smallest
    priority_queue<long long> p2;

    // build initial heaps
    for (long long i = 0; i < K1; i++)
        p1.push(A[i]);

    for (long long i = 0; i < K2 - 1; i++)
        p2.push(A[i]);

    // maintain K1 smallest
    for (long long i = K1; i < N; i++)
    {
        if (A[i] < p1.top())
        {
            p1.pop();
            p1.push(A[i]);
        }
    }

    // maintain K2 smallest
    for (long long i = K2 - 1; i < N; i++)
    {
        if (A[i] < p2.top())
        {
            p2.pop();
            p2.push(A[i]);
        }
    }

    long long sum1 = 0, sum2 = 0;

    while (!p1.empty())
    {
        sum1 += p1.top();
        p1.pop();
    }

    while (!p2.empty())
    {
        sum2 += p2.top();
        p2.pop();
    }

    return sum2 - sum1;
}
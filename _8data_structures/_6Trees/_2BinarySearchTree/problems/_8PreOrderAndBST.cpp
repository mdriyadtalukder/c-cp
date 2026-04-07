// pre order deoya thkbe oikhn theke return krbo oita tara BST banano jbe or not..
// segmentation fault->recursion use krle sob stack memory te jai jar speace limit thke.
//.so jkhn large input thke tokhn unaccess speace eo store hote jaii tokhn error dei..
// r stack<> ja ekti STL.eita use krle heap e sob store hy..jar speace onkkkkk..tai error hyna..

// 2 ta stack thkbe..lower and upper.1st e lower e thkbe intmin and upper e intmax
// then 1st e right side er tai dukabo 2 stack ei..1st value hbe lower e and 2nd ta upper e.then left ta..
// then new node e gele pop krbo utill get rage of that value..like 15..lower e ase 15 and upper e 20..so ekhn push krbo er upore.

#include <bits/stdc++.h>
using namespace std;

int canRepresentBST(int arr[], int N)
{
    stack<int> lower, upper;

    lower.push(INT_MIN);
    upper.push(INT_MAX);

    for (int i = 0; i < N; i++)
    {

        // 1️⃣ check range
        if (arr[i] < lower.top())
        {
            return 0;
        }

        // 2️⃣ find correct parent range
        while (arr[i] > upper.top())
        {
            lower.pop();
            upper.pop();
        }

        // 3️⃣ current range
        int left = lower.top();
        int right = upper.top();

        lower.pop();
        upper.pop();

        // 4️⃣ push right subtree range
        lower.push(arr[i]);
        upper.push(right);

        // 5️⃣ push left subtree range
        lower.push(left);
        upper.push(arr[i]);
    }

    return 1;
}

int main()
{
    int arr[] = {2, 4, 3};
    int N = 3;

    if (canRepresentBST(arr, N))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}

/*
recursive

void BST(int arr[], int &index, int lower, int upper, int N)
{
    if (index == N || arr[index] < lower || arr[index] > upper)
        return;

    int value = arr[index++];

    // left
    BST(arr, index, lower, value, N);

    // right
    BST(arr, index, value, upper, N);
}

int canRepresentBST(int arr[], int N)
{
    int index = 0;

    BST(arr, index, INT_MIN, INT_MAX, N);

    return index == N;
}*/
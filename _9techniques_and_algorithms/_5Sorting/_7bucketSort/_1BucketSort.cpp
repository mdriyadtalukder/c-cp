// element k n dara gun krbo in int then oi index e dukabo in 2d array..then 2d array and er sub array sort krbo then oigula sob main array te insert krbo sot wise
#include <bits/stdc++.h>
using namespace std;
//tc=O(N+K)..WORST CASE TC=o(n^2)
void bucketSort(float arr[], int size)
{
    vector<vector<float>> bucket(size);
    // step1: inserting elements into bucket
    for (int i = 0; i < size; i++)
    {
        int index = arr[i] * size;
        bucket[index].push_back(arr[i]);
    }
    // step2: sorting individual buckets
    for (int i = 0; i < size; i++)
    {
        if (!bucket[i].empty())
        {
            sort(bucket[i].begin(), bucket[i].end());
        }
    }
    // step3:combining elements from buckets
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < bucket[i].size(); j++)
        {
            arr[k++] = bucket[i][j];
        }
    }
}
int main()
{
    float arr[] = {0.13, 0.45, 0.12, 0.89, 0.75, 0.63, 0.85, 0.39};
    int size = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, size);
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    return 0;
}
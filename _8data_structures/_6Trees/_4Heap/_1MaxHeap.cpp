/*
Parent's child index:
2i + 1 (Left Node index)
2i + 2 (Right Node index)
Child index: i
Parent index: (i-1)/2

*insert TC=O(nlogn)

*delete mane top node k delete kora and last node re top node banano and eitar child er shthe compare kora j konta boro parent theke
jeta boro hbe oita parent baniye dibo swap kre..other parent tar child er shth ei kaj krbe so on.. eitar name heapify process.
.deletion TC O(logn)
*/

#include <bits/stdc++.h>
using namespace std;
class MaxHeap
{
    int *arr;
    int size;       // total elements in heap
    int total_size; // total size of array
public:
    MaxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }
    // insert into heap--stepup.
    void insert(int value)
    {
        // if heap size is available or not
        if (size == total_size)
        {
            cout << "Heap Overflow\n";
            return;
        }
        arr[size] = value;
        int index = size;
        size++;
        // Compare it with its parent
        while (index > 0 && arr[(index - 1) / 2] < arr[index]) // min heap e > hbe..just condition change
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        };
        cout << arr[index] << " is inserted into the heap" << endl;
    }
    void Heapify(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && arr[left] > arr[largest]) // left child boro..min heap e < hbe..just condition change
            largest = left;
        if (right < size && arr[right] > arr[largest]) // right child boro..min heap e < hbe..just condition change
            largest = right;
        if (largest != index) // shoman na ..its mean exchange hyse..
        {
            swap(arr[index], arr[largest]); // exchange hyse tai swap krlm value
            Heapify(largest);               // abar check dilam for kono parents choto nki child theke.
        }
    }
    void Delete()
    {
        if (size == 0)
        {
            cout << "Heap Underflow\n";
            return;
        }
        cout << arr[0] << " deleted from the heap" << endl;
        arr[0] = arr[size - 1];
        size--;
        if (size == 0)
            return;
        Heapify(0);
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    MaxHeap H1(6);
    H1.insert(4);
    H1.insert(14);
    H1.insert(11);
    H1.Delete();
    H1.print();
    H1.insert(114);
    H1.insert(24);
    H1.insert(1);
    H1.insert(10);
    H1.print();
}
#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    int *arr;
    int size;
    int total_size;

public:
    MinHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    // insert into heap
    void insert(int value)
    {
        if (size == total_size)
        {
            cout << "Heap Overflow\n";
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        // 🔥 change: parent > child hole swap (MinHeap)
        while (index > 0 && arr[(index - 1) / 2] > arr[index])
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }

        cout << arr[index] << " is inserted into the heap" << endl;
    }

    void Heapify(int index)
    {
        int smallest = index; // 🔥 change
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // 🔥 change: smaller child select
        if (left < size && arr[left] < arr[smallest])
            smallest = left;
        if (right < size && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != index)
        {
            swap(arr[index], arr[smallest]);
            Heapify(smallest);
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
    MinHeap H1(6);

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
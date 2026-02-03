#include <bits/stdc++.h>
using namespace std;

class IntVector
{
private:
    static const int DEFAULT_CAP = 1 << 3; // 8
    int *arr;
    int len;
    int cap;

    void resize(int newCap)
    {
        int *newArr = new int[newCap];
        for (int i = 0; i < len; i++)
            newArr[i] = arr[i];

        delete[] arr;
        arr = newArr;
        cap = newCap;
    }

public:
    /* ================= CONSTRUCTORS ================= */

    IntVector() : len(0), cap(DEFAULT_CAP)
    {
        arr = new int[cap];
    }

    IntVector(int capacity) : len(0), cap(capacity)
    {
        if (capacity <= 0)
            throw invalid_argument("Illegal capacity");
        arr = new int[cap];
    }

    IntVector(const int a[], int n)
    {
        if (a == nullptr)
            throw invalid_argument("Array cannot be null");
        len = cap = n;
        arr = new int[cap];
        for (int i = 0; i < n; i++)
            arr[i] = a[i];
    }

    /* ================= SIZE / CAPACITY ================= */

    int size() const { return len; }
    int capacity() const { return cap; }
    bool empty() const { return len == 0; }

    /* ================= ELEMENT ACCESS ================= */

    int at(int index) const
    {
        if (index < 0 || index >= len)
            throw out_of_range("Index out of bounds");
        return arr[index];
    }

    int &operator[](int index)
    {
        return arr[index]; // no bounds check (like std::vector)
    }

    int front() const { return arr[0]; }
    int back() const { return arr[len - 1]; }

    /* ================= MODIFIERS ================= */

    void push_back(int value)
    {
        if (len + 1 > cap)
        {
            cap = (cap == 0) ? 1 : cap * 2;
            resize(cap);
        }
        arr[len++] = value;
    }

    void pop_back()
    {
        if (empty())
            throw out_of_range("Vector is empty");
        len--;
    }

    void clear()
    {
        len = 0; // keep memory (same as std::vector)
    }

    /* ================= SEARCH ================= */

    int indexOf(int value) const
    {
        for (int i = 0; i < len; i++)
            if (arr[i] == value)
                return i;
        return -1;
    }

    bool contains(int value) const
    {
        return indexOf(value) != -1;
    }

    /* ================= ERASE / REMOVE ================= */

    // erase by index (like removeAt)
    void erase(int index)
    {
        if (index < 0 || index >= len)
            throw out_of_range("Index out of bounds");

        for (int i = index; i < len - 1; i++)
            arr[i] = arr[i + 1];

        len--;
        cap--; // keeping same behavior as your Java code
    }

    // erase by value
    bool remove(int value)
    {
        int idx = indexOf(value);
        if (idx == -1)
            return false;
        erase(idx);
        return true;
    }

    /* ================= ALGORITHMS ================= */

    void sort()
    {
        std::sort(arr, arr + len);
    }

    void reverse()
    {
        for (int i = 0; i < len / 2; i++)
            std::swap(arr[i], arr[len - i - 1]);
    }

    int binary_search(int key)
    {
        auto it = std::lower_bound(arr, arr + len, key);
        if (it != arr + len && *it == key)
            return it - arr;
        return -1;
    }

    /* ================= ITERATORS ================= */

    int *begin() { return arr; }
    int *end() { return arr + len; }

    /* ================= PRINT ================= */

    friend ostream &operator<<(ostream &os, const IntVector &v)
    {
        os << "[";
        for (int i = 0; i < v.len; i++)
        {
            os << v.arr[i];
            if (i != v.len - 1)
                os << ",";
        }
        os << "]";
        return os;
    }

    /* ================= DESTRUCTOR ================= */

    ~IntVector()
    {
        delete[] arr;
    }
};
int main()
{
    IntVector ar(14);

    ar.push_back(1);
    ar.push_back(2);
    ar.push_back(3);
    ar.push_back(4);

    ar[3] = 5;
    ar.reverse();

    cout << ar.binary_search(3) << endl;
    cout << ar << endl;

    for (int x : ar)
        cout << x << " ";
}

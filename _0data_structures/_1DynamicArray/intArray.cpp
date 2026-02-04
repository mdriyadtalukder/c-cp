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

    int front() const
    {
        if (empty())
            throw out_of_range("Vector is empty");
        return arr[0];
    }
    int back() const
    {
        if (empty())
            throw out_of_range("Vector is empty");
        return arr[len - 1];
    }

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
        arr[len - 1] = 0;
        len--;
    }

    void clear()
    {
        // delete[] arr;       // free all memory
        // arr = new int[cap]; // allocate new array with same capacity

        for (int i = 0; i < len; i++)
        {
            arr[i] = 0;
        }
        len = 0; // reset logical size
    }

    /* ================= SEARCH ================= */

    int indexOf(int value) const // const means indexof does not change the vector.It only reads the data
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
        // cap--; // keeping same behavior as your Java code
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

    int binary_search(int key) const
    {
        // std::binary_search returns true if key exists in [arr, arr + len)
        bool found = std::binary_search(arr, arr + len, key);

        return found ? 1 : 0; // 1 if found, 0 if not
    }

    /* ================= ITERATORS ================= */

    int *begin() { return arr; }
    int *end() { return arr + len; }

    /* ================= PRINT ================= */

    friend ostream &operator<<(ostream &os, const IntVector &v) // friend = lets the function access private stuff.cout is an output stream..operator<< is just a function that tells C++ how to print something.v.arr[i] Direct access to array inside class .Works in friend function
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
    ar.sort();
    cout << "bi " << ar.binary_search(22) << endl; // need sort array

    ar.reverse();

    cout << ar << endl;

    for (int x : ar)
        cout << x << " ";

    cout << endl;

    // iteration
    for (int *it = ar.begin(); it != ar.end(); ++it)
        cout << *it << " "; // prints 10 20 30

    operator<<(cout, ar);
}
